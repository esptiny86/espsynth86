#include "Arduino.h"
#include "ModuleSampleAndHold.h"
#include "defines.h"

ModuleSampleAndHold::ModuleSampleAndHold()
{
  this->triggered = false;
  this->sampled_value = 0;
}

uint16_t ModuleSampleAndHold::compute()
{
  uint32_t clock = this->readInput(trigger_input);
  
  if((clock < MID_CV) && triggered) triggered = false;
  
  if((clock >= MID_CV) && !triggered) 
  {
    sampled_value = this->readInput(sample_input);
    triggered = true;
  }
  
  return(sampled_value);
}
