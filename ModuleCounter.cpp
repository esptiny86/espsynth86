#include "Arduino.h"
#include "ModuleCounter.h"
#include "defines.h"

ModuleCounter::ModuleCounter(int target)
{
  this->value = 0;
  this->target = target;
  this->clocked = false;
  this->my_output = 0;
  this->no_output_conversion = true;

  this->clock_input = NULL;
}

uint32_t ModuleCounter::compute()
{
  uint32_t clock = this->readInput(clock_input);
  
  if((clock < MID_CV) && clocked) clocked = false;
  
  if((clock >= MID_CV) && !clocked) 
  {
    clocked = true;
    my_output = value; 
    value = value + 1;
    if(value > target) value = 0;
  }
  
  return(my_output);
  
}
