#include "Arduino.h"
#include "ModuleSpeechSound.h"
#include "defines.h"

ModuleSpeechSound::ModuleSpeechSound()
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
  
  formantTable  = 
  {
     0x1b,0x28,0x59,0xf,0xd,0x1,0x0,  /*09 AA*/
     0x1b,0x2b,0x58,0xf,0xd,0x1,0x0,  /*51 AW*/
     0x15,0x1f,0x58,0xf,0xc,0x0,0x0,  /*11 AO*/ 
     0x17,0x2c,0x57,0xf,0xc,0x1,0x0,  /*10 AH*/ 
     0x18,0x3f,0x58,0xf,0xe,0x8,0x0,  /*08 AE*/
     0x15,0x1f,0x58,0xf,0xc,0x0,0x0,  /*50 OY*/
     0x12,0x1e,0x58,0xf,0xc,0x0,0x0,  /*17 OH*/
     0x12,0x1e,0x58,0xf,0xc,0x0,0x0,  /*52 OW*/ 
     0x10,0x25,0x52,0xf,0xb,0x1,0x0,  /*12 UH*/
     0xd,0x22,0x52,0xd,0x8,0x0,0x0,   /*53 UW*/ 
     0xe,0x49,0x5d,0xd,0x8,0x7,0x0,   /*06 IH*/                  
     0xa,0x54,0x6e,0xd,0xa,0x8,0x0,   /*05 IY*/
     0x1b,0x27,0x58,0xf,0xd,0x1,0x0,  /*49 AY*/
     0x13,0x48,0x5a,0xe,0xe,0x9,0x0,  /*48 EY*/   
     0x13,0x43,0x5b,0xe,0xd,0x8,0x0,  /*07 EH*/
     0x12,0x31,0x3e,0xc,0xb,0x5,0x0,  /*15 ER*/ 
     0x0,0x0,0x0,0x0,0x0,0x0,0x0      /*space*/ 
  }; 

  frameTime = 15;
  noise = 0;

  // initialize all inputs
  this->sound_input = NULL;
  this->pitch_input = NULL;
  this->formant_scale_input = NULL;  
}


uint32_t ModuleSpeechSound::compute()
{
  uint32_t sound_input = readInput(this->sound_input, CONVERT_TO_10_BIT);
  uint32_t pitch_input = readInput(this->pitch_input, CONVERT_TO_6_BIT);
  uint32_t formant_scale = readInput(this->formant_scale_input, CONVERT_TO_7_BIT);
   
  // parameters update
  uint8_t formantPos;
  pitchPhaseInc = pitchTable[pitch_input];
  formantPos = (sound_input>>6) * 7;
  uint8_t pos = sound_input - ((sound_input>>6)<<6);
  form1PhaseInc = (((formantTable[formantPos] * formant_scale)*(64-pos))>>6) + (((formantTable[formantPos+7] * formant_scale)*(pos))>>6);
  form2PhaseInc = (((formantTable[formantPos+1] * formant_scale)*(64-pos))>>6) + (((formantTable[formantPos+8] * formant_scale)*(pos))>>6);
  form3PhaseInc = (((formantTable[formantPos+2] * formant_scale)*(64-pos))>>6) + (((formantTable[formantPos+9] * formant_scale)*(pos))>>6);
  form1Amp = ((formantTable[formantPos+3]*(64-pos))>>6) + ((formantTable[formantPos+10]*(pos))>>6);
  form2Amp = ((formantTable[formantPos+4]*(64-pos))>>6) + ((formantTable[formantPos+11]*(pos))>>6);
  form3Amp = ((formantTable[formantPos+5]*(64-pos))>>6) + ((formantTable[formantPos+12]*(pos))>>6);
  noiseMod = ((formantTable[formantPos+6]*(64-pos))>>6) + ((formantTable[formantPos+13]*(pos))>>6);
  
  int8_t value;
  int16_t phaseNoise = noise * noiseMod;
  noise += noise<<2; noise++;  // noise' = 5*noise+1
  
  form1Phase += form1PhaseInc;
  value = pgm_read_byte(sinCalc+(((form1Phase>>8) & 0xf0) | form1Amp));
  form2Phase += form2PhaseInc;
  value += pgm_read_byte(sinCalc+(((form2Phase>>8) & 0xf0) | form2Amp));
  form3Phase += form3PhaseInc;
  value += pgm_read_byte(sqrCalc+(((form3Phase>>8) & 0xf0) | form3Amp));

  value = (value * (0xff^(pitchPhase>>8)))>>8;
  pitchPhase += pitchPhaseInc;
  
  if ((pitchPhase+phaseNoise) < pitchPhaseInc) {
    form1Phase = 0;
    form2Phase = 0;
    form3Phase = 0;
  }
  
  return(((int)value + 0x80) << 4);  
}

