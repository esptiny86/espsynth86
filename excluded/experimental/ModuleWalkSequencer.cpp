/*
#include "Arduino.h"
#include "ModuleWalkSequencer.h"
#include "Defines.h"

ModuleWalkSequencer::ModuleWalkSequencer()
{
  this->step = 0;
  this->old_clock = 0;

  this->patterns = {
    { 
      32896, 32932, 41506, 45714, 41120, 41504, 33058, 41508
    },
    {
      // Bank #2 = snare patterns
      2056,     // 0000100000001000
      2393,     // 0000100101011001
      2190,     // 0000100010001110
      2057,     // 0000100000001001
      128,      // 0000000010000000
      6144,     // 0001100000000000
      6152,     // 0001100000001000
      2230      // 0000100010110110
    },
    {
      // Bank #3 = hihat patterns
      65535,    // 1111111111111111
      43690,    // 1010101010101010
      47031,    // 1011011110110111
      47086,    // 1011011111101110
      41535,    // 1010001000111111
      33808,    // 1000010000010000
      33510,    // 1000001011100110
      21847     // 0101010101010111
    }    
  };
}

uint32_t ModuleSequencer::compute()
{
  uint32_t clock = this->readInput(clock_input);
  
  // Step the sequencer on the rising edge 
  if((clock > MID_CV) && (old_clock < MID_CV))
  {
    step++;
    if(step >= 8) step = 0;
  }
  
  old_clock = clock;
  
  // Serial.println(sequence[step]);

  return(sequence[step]);
}
*/
