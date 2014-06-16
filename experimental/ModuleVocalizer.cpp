#include "Arduino.h"
#include "ModuleVocalizer.h"
#include "defines.h"

ModuleVocalizer::ModuleVocalizer()
{
  output = 0;
  
  pitchTable = {
    58,61,65,69,73,77,82,86,92,97,
    103,109,115,122,129,137,145,154,163,173,
    183,194,206,218,231,244,259,274,291,308,
    326,346,366,388,411,435,461,489,518,549,
    581,616,652,691,732,776,822,871,923,978,
    1036,1097,1163,1232,1305,1383,1465,1552,1644,1742,
    1845,1955,2071,2195
  };
  
  sinCalc  = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,2,2,3,3,4,5,6,7,8,10,12,14,17,20,24,
    0,4,4,5,6,7,9,11,13,15,18,22,26,31,37,45,
    0,5,6,7,8,10,12,14,17,20,24,28,34,41,49,58,
    0,5,6,7,9,10,12,15,18,21,26,31,37,44,53,63,
    0,5,6,7,8,10,12,14,17,20,24,28,34,41,49,58,
    0,4,4,5,6,7,9,11,13,15,18,22,26,31,37,45,
    0,2,2,3,3,4,5,6,7,8,10,12,14,17,20,24,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,-2,-2,-3,-3,-4,-5,-6,-7,-8,-10,-12,-14,-17,-20,-24,
    0,-4,-4,-5,-6,-7,-9,-11,-13,-15,-18,-22,-26,-31,-37,-45,
    0,-5,-6,-7,-8,-10,-12,-14,-17,-20,-24,-28,-34,-41,-49,-58,
    0,-5,-6,-7,-9,-10,-12,-15,-18,-21,-26,-31,-37,-44,-53,-63,
    0,-5,-6,-7,-8,-10,-12,-14,-17,-20,-24,-28,-34,-41,-49,-58,
    0,-4,-4,-5,-6,-7,-9,-11,-13,-15,-18,-22,-26,-31,-37,-45,
    0,-2,-2,-3,-3,-4,-5,-6,-7,-8,-10,-12,-14,-17,-20,-24
  };  
  
  sqrCalc  ={
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16
  };
  
  noise = 0;

  // initialize all inputs
  this->param1_input = NULL;  
  this->param2_input = NULL;  
  this->param3_input = NULL; 
  this->pitch_input = NULL;
  this->formant_scale_input = NULL;    
}


uint32_t ModuleVocalizer::compute()
{
  uint32_t param1_input = readInput(this->param1_input, CONVERT_TO_5_BIT)+8;
  uint32_t param2_input = readInput(this->param2_input, CONVERT_TO_6_BIT)+20;
  uint32_t param3_input = readInput(this->param3_input, CONVERT_TO_3_BIT);
  uint32_t formant_scale = readInput(this->formant_scale_input, CONVERT_TO_7_BIT)+8;
  //uint32_t formant_scale = 54;
  uint32_t pitch_input = readInput(this->pitch_input, CONVERT_TO_6_BIT);
   
  // parameters update
  pitchPhaseInc = pitchTable[pitch_input];
  form1PhaseInc = param1_input * formant_scale;
  form2PhaseInc = param2_input * formant_scale;
  //form3PhaseInc = param3_input * formant_scale;
  form3PhaseInc = 0;
  form1Amp = 14;
  form2Amp = 14;
  form3Amp = 0;
    
  int16_t value;
  //int16_t phaseNoise = noise * noiseMod;
  int16_t phaseNoise = param3_input * noiseMod;
  noise += noise<<2; noise++;  // noise' = 5*noise+1
  
  form1Phase += form1PhaseInc;
  value = sinCalc[(int)(((form1Phase>>8) & 0xf0) | form1Amp)];
  form2Phase += form2PhaseInc;
  value += sinCalc[(int)(((form2Phase>>8) & 0xf0) | form2Amp)];
  form3Phase += form3PhaseInc;
  value += sqrCalc[(int)(((form3Phase>>8) & 0xf0) | form3Amp)];


  value = (value * (0xff^(pitchPhase>>8)))>>8;
  pitchPhase += pitchPhaseInc;
  
  if ((pitchPhase+phaseNoise) < pitchPhaseInc) {
    form1Phase = 0;
    form2Phase = 0;
    form3Phase = 0;
  }
  
/*  value+=127;
  uint32_t ret = value;
 
  
  return((ret) << 3);*/
  
  value*=16;
  value+=2047;
  return(value);
//return(value>>4);  
}