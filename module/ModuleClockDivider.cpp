#include "ModuleClockDivider.h"
#include "defines.h"

ModuleClockDivider::ModuleClockDivider()
{
  this->counter = 0;  
  this->clock_division = 0;
  this->clocked = false;
  this->my_output = 0;

  this->clock_input = NULL;
}

uint16_t ModuleClockDivider::compute()
{
  uint32_t clock = this->readInput(clock_input);
  uint32_t clock_division = this->readInput(division_input,0,20);
  

  if((clock < MID_CV) && clocked) clocked = false;
  
  if((clock >= MID_CV) && !clocked) 
  {
    clocked = true;
    
    counter = counter + 1;
    
    if(counter >= clock_division)
    {
      counter = 0;
      
      if(my_output == 0)
      {
        my_output = MAX_CV;
      }
      else
      {
        my_output = 0;
      }
    }
  }
  
  return(my_output);
}
