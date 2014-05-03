#include "Arduino.h"
#include "ModuleSequencer.h"
#include "Defines.h"

ModuleSequencer::ModuleSequencer(int values[])
{
  this->step = 0;
  this->old_clock = 0;

  for(int i=0; i < 8; i++)
  {
    this->sequence[i] = values[i];
  }

  // Initialize all inputs
  this->clock_input = NULL;
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
