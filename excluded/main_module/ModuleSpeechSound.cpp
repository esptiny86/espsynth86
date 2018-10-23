#include "Arduino.h"
#include "ModuleSpeechSound.h"
#include "Defines.h"
#include "GlobalSpeechTables.h"

uint16_t ModuleSpeechSound::compute()
{
  uint8_t phase1_input  = readInput(this->phase1_input, CONVERT_TO_6_BIT)+8;
  uint8_t phase2_input  = readInput(this->phase2_input, CONVERT_TO_6_BIT)+20;
  uint8_t phase3_input  = readInput(this->phase3_input, CONVERT_TO_7_BIT);
  uint8_t formant_scale = readInput(this->formant_scale_input, CONVERT_TO_7_BIT)+8;
  uint8_t pitch_input   = readInput(this->pitch_input, CONVERT_TO_6_BIT);
   
  int16_t value;

  pitchPhaseInc = speechPitchTable[pitch_input];
  form1PhaseInc = phase1_input * formant_scale;
  form2PhaseInc = phase2_input * formant_scale;
  form3PhaseInc = phase3_input * formant_scale;

  form1Amp = 14;
  form2Amp = 14;
  form3Amp = 15;
    
  form1Phase += form1PhaseInc;
  value = speechSinCalc[(int)(((form1Phase>>8) & 0xf0) | form1Amp)];
  form2Phase += form2PhaseInc;
  value += speechSinCalc[(int)(((form2Phase>>8) & 0xf0) | form2Amp)];
  form3Phase += form3PhaseInc;
  value += speechSqrCalc[(int)(((form3Phase>>8) & 0xf0) | form3Amp)];

  value = (value * (0xff^(pitchPhase>>8)))>>8;
  pitchPhase += pitchPhaseInc;
  
  if (pitchPhase < pitchPhaseInc) 
  {
    form1Phase = 0;
    form2Phase = 0;
    form3Phase = 0;
  }
  
  value = value << 4;
  value += 2047;
  
  return(value);
}
