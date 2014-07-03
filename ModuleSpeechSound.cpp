#include "Arduino.h"
#include "ModuleSpeechSound.h"
#include "Defines.h"
#include "GlobalSpeechTables.h"

ModuleSpeechSound::ModuleSpeechSound()
{
  output = 0;
}


uint16_t ModuleSpeechSound::compute()
{
  uint32_t param1_input = readInput(this->param1_input, CONVERT_TO_6_BIT)+8;
  uint32_t param2_input = readInput(this->param2_input, CONVERT_TO_6_BIT)+20;
  uint32_t param3_input = readInput(this->param3_input, CONVERT_TO_7_BIT);
  uint32_t formant_scale = readInput(this->formant_scale_input, CONVERT_TO_7_BIT)+8;
  uint32_t pitch_input = readInput(this->pitch_input, CONVERT_TO_6_BIT);
   
  // parameters update
  pitchPhaseInc = speechPitchTable[pitch_input];
  form1PhaseInc = param1_input * formant_scale;
  form2PhaseInc = param2_input * formant_scale;
  form3PhaseInc = param3_input * formant_scale;
  //form3PhaseInc = 0;
  form1Amp = 14;
  form2Amp = 14;
  form3Amp = 15;
    
  int16_t value;
    
  form1Phase += form1PhaseInc;
  value = speechSinCalc[(int)(((form1Phase>>8) & 0xf0) | form1Amp)];
  form2Phase += form2PhaseInc;
  value += speechSinCalc[(int)(((form2Phase>>8) & 0xf0) | form2Amp)];
  form3Phase += form3PhaseInc;
  value += speechSqrCalc[(int)(((form3Phase>>8) & 0xf0) | form3Amp)];


  value = (value * (0xff^(pitchPhase>>8)))>>8;
  pitchPhase += pitchPhaseInc;
  
  if (pitchPhase < pitchPhaseInc) {
    form1Phase = 0;
    form2Phase = 0;
    form3Phase = 0;
  }
  
 
  value*=16;
  value+=2047;
  return(value);
}
