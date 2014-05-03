#include "Arduino.h"
#include "ModuleDrumSequencer.h"
#include "Defines.h"

ModuleDrumSequencer::ModuleDrumSequencer(int bank)
{
  this->clocked = false;
  this->bank = bank;
  this->step = 0;
  this->my_output = 0;
  
  this->patterns = {
    { 
      // Bank #1 = kick patterns         
      32896,    // 1000000010000000
      32932,    // 1000000010100100
      41506,    // 1010001000100010
      45714,    // 1011001010010010
      41120,    // 1010000010100000
      41504,    // 1010001000100000
      33058,    // 1000000100100010
      41508     // 1001000010010000
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

  // Initialize all inputs
  this->clock_input = NULL;
  this->pattern_input = NULL;  
}

uint32_t ModuleDrumSequencer::compute()
{
  uint32_t clock = this->readInput(clock_input);
  
  if((clock < MID_CV) && clocked) clocked = false;
  
  if((clock >= MID_CV) && !clocked) 
  {
    clocked = true;
    
    // Read scale input.
    // Convert the standard 12 bit CV value to a 3-bit value, which ranges from 0 to 7
    uint32_t selected_pattern = this->readInput(pattern_input, CONVERT_TO_3_BIT);
    
    my_output = bitRead(patterns[bank][selected_pattern], step) * MAX_AUDIO_VALUE;
    
    step++;
    if(step == 16) step = 0;
  }
  
  return(my_output);
}
