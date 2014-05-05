#include "Arduino.h"
#include "ModuleWords.h"
#include "Defines.h"

ModuleWords::ModuleWords()
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
  
  formantTable  = {
   0x1b,0x28,0x59,0xf,0xd,0x1,/*09 AA 0*/
   0x1b,0x2b,0x58,0xf,0xd,0x1,/*51 AW 1*/
   0x15,0x1f,0x58,0xf,0xc,0x0,/*11 AO 2*/ 
   0x17,0x2c,0x57,0xf,0xc,0x1,/*10 AH 3*/ 
   0x18,0x3f,0x58,0xf,0xe,0x8,/*08 AE 4*/
   0x15,0x1f,0x58,0xf,0xc,0x0,/*50 OY 5*/
   0x12,0x1e,0x58,0xf,0xc,0x0,/*17 OH 6*/
   0x12,0x1e,0x58,0xf,0xc,0x0,/*52 OW 7*/ 
   0x10,0x25,0x52,0xf,0xb,0x1,/*12 UH 8*/
   0xd,0x22,0x52,0xd,0x8,0x0,/*53 UW 9*/ 
   0xe,0x49,0x5d,0xd,0x8,0x7,/*06 IH 10*/                  
   0xa,0x54,0x6e,0xd,0xa,0x8,/*05 IY 11*/
   0x1b,0x27,0x58,0xf,0xd,0x1,/*49 AY 12*/
   0x13,0x48,0x5a,0xe,0xe,0x9,/*48 EY 13*/   
   0x13,0x43,0x5b,0xe,0xd,0x8,/*07 EH 14*/
   0x12,0x31,0x3e,0xc,0xb,0x5,/*15 ER 15*/ 
   0x0,0x0,0x0,0x0,0x0,0x0,/*space*/ 
  };  
  
  word = {
   6,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0,
   7,1,4,11,7,9,8,14,15,1,-1,-1,-1,-1,-1,-1,-1,-1,
   8,0,4,8,9,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
   9,0,7,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1
  };
  
  frameTime = 15;
  noise = 0;

  // Initialize all inputs to NULL
  sound_input = NULL;
  param1_input = NULL;
  param2_input = NULL;
  param3_input = NULL;
  pitch_input = NULL;

}



uint32_t ModuleWords::compute()
{


  uint32_t param3_input = readInput(this->param3_input, CONVERT_TO_3_BIT);
  uint32_t formant_scale = readInput(this->param2_input, CONVERT_TO_7_BIT)+8;
  //uint32_t formant_scale = 54;
  uint32_t pitch_input = readInput(this->pitch_input, CONVERT_TO_6_BIT);
  uint32_t sound_input = readInput(this->param1_input, CONVERT_TO_10_BIT);
  
  uint32_t word_input = readInput(this->sound_input, CONVERT_TO_2_BIT);
  
  //  uint32_t word_start = 0;
  uint32_t word_start = 18*word_input;
  uint32_t word_shifter = word[word_start];
  //uint32_t word_shifter = 6;
  uint32_t shifter_high = 1<<word_shifter;
  //uint32_t shifter_high = 64;
  uint32_t word_pos = sound_input>>word_shifter;
  //uint32_t word_pos = 0;
   
  // parameters update
  uint32_t formantPos;
  uint32_t formantPosNext;
  
  formantPos = (word[word_pos + word_start+1]) * 6;
  formantPosNext = (word[word_pos + word_start + 2]) * 6;
  uint32_t pos = sound_input - (shifter_high*word_pos);
  //uint32_t pos = 0;
   
  // parameters update
  pitchPhaseInc = pitchTable[pitch_input];
  form1PhaseInc = ((uint32_t)formantTable[formantPos] *(shifter_high - pos)*formant_scale/shifter_high) + ((uint32_t)formantTable[formantPosNext] *pos*formant_scale/shifter_high);
  form2PhaseInc = ((uint32_t)formantTable[formantPos+1] *(shifter_high - pos)*formant_scale/shifter_high) + ((uint32_t)formantTable[formantPosNext+1] *pos*formant_scale/shifter_high);
  form3PhaseInc = ((uint32_t)formantTable[formantPos+2] *(shifter_high - pos)*formant_scale/shifter_high) + ((uint32_t)formantTable[formantPosNext+2] *pos*formant_scale/shifter_high);
  form1Amp = ((uint32_t)formantTable[formantPos+3] *(shifter_high - pos)/shifter_high) + ((uint32_t)formantTable[formantPosNext+3] *pos/shifter_high);;
  form2Amp = ((uint32_t)formantTable[formantPos+4] *(shifter_high - pos)/shifter_high) + ((uint32_t)formantTable[formantPosNext+4] *pos/shifter_high);;
  form3Amp = ((uint32_t)formantTable[formantPos+5] *(shifter_high - pos)/shifter_high) + ((uint32_t)formantTable[formantPosNext+5] *pos/shifter_high);;
    
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