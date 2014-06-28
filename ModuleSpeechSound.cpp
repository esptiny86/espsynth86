#include "Arduino.h"
#include "ModuleSpeechSound.h"
#include "Defines.h"
#include "SpeechTables.h"

ModuleSpeechSound::ModuleSpeechSound()
{
  output = 0;
  frameTime = 15;
  noise = 0;
}


uint16_t ModuleSpeechSound::compute()
{
  uint32_t formant_scale = readInput(this->param2_input, CONVERT_TO_7_BIT)+8;
  uint32_t pitch_input = readInput(this->pitch_input, CONVERT_TO_6_BIT);
  uint32_t sound_input = readInput(this->param1_input, CONVERT_TO_10_BIT);
  uint32_t word_input = readInput(this->sound_input, CONVERT_TO_2_BIT);
  
  uint32_t word_start = 18*word_input;
  uint32_t word_shifter = speechWordTable[word_start];
  uint32_t shifter_high = 1<<word_shifter;
  uint32_t word_pos = sound_input>>word_shifter;
   
  // parameters update
  uint32_t formantPos;
  uint32_t formantPosNext;
  
  formantPos = (speechWordTable[word_pos + word_start+1]) * 6;
  formantPosNext = (speechWordTable[word_pos + word_start + 2]) * 6;
  uint32_t pos = sound_input - (shifter_high*word_pos);
   
  // parameters update
  pitchPhaseInc = speechPitchTable[pitch_input];
  form1PhaseInc = ((uint32_t)speechFormantTable[formantPos] *(shifter_high - pos)*formant_scale/shifter_high) + ((uint32_t)speechFormantTable[formantPosNext] *pos*formant_scale/shifter_high);
  form2PhaseInc = ((uint32_t)speechFormantTable[formantPos+1] *(shifter_high - pos)*formant_scale/shifter_high) + ((uint32_t)speechFormantTable[formantPosNext+1] *pos*formant_scale/shifter_high);
  form3PhaseInc = ((uint32_t)speechFormantTable[formantPos+2] *(shifter_high - pos)*formant_scale/shifter_high) + ((uint32_t)speechFormantTable[formantPosNext+2] *pos*formant_scale/shifter_high);
  form1Amp = ((uint32_t)speechFormantTable[formantPos+3] *(shifter_high - pos)/shifter_high) + ((uint32_t)speechFormantTable[formantPosNext+3] *pos/shifter_high);;
  form2Amp = ((uint32_t)speechFormantTable[formantPos+4] *(shifter_high - pos)/shifter_high) + ((uint32_t)speechFormantTable[formantPosNext+4] *pos/shifter_high);;
  form3Amp = ((uint32_t)speechFormantTable[formantPos+5] *(shifter_high - pos)/shifter_high) + ((uint32_t)speechFormantTable[formantPosNext+5] *pos/shifter_high);;
    
  int16_t value;
  int16_t phaseNoise = 0;
  noise += noise<<2; noise++;  // noise' = 5*noise+1
  
  form1Phase += form1PhaseInc;
  value = speechSinCalc[(int)(((form1Phase>>8) & 0xf0) | form1Amp)];
  form2Phase += form2PhaseInc;
  value += speechSinCalc[(int)(((form2Phase>>8) & 0xf0) | form2Amp)];
  form3Phase += form3PhaseInc;
  value += speechSqrCalc[(int)(((form3Phase>>8) & 0xf0) | form3Amp)];


  value = (value * (0xff^(pitchPhase>>8)))>>8;
  pitchPhase += pitchPhaseInc;
  
  if ((pitchPhase+phaseNoise) < pitchPhaseInc) {
    form1Phase = 0;
    form2Phase = 0;
    form3Phase = 0;
  }
  
  value*=16;
  value+=2047;

  return(value);
}