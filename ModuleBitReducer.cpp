#include "Arduino.h"
#include "ModuleBitReducer.h"
#include "defines.h"

ModuleBitReducer::ModuleBitReducer()
{
  audio_input = NULL;
  bit_input = NULL;  
}

uint16_t ModuleBitReducer::compute()
{
  uint16_t audio = this->readInput(audio_input);
  uint16_t bits = this->readInput(bit_input, 0, 12);

  audio = audio >> bits;  // Shave off bits for the effect
  audio = audio << bits;  // Restore to a 12 bit number

  return(audio);
}
