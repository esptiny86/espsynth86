#include "ModuleClockDivider.h"
#include "defines.h"

ModuleClockDivider::ModuleClockDivider(int clock_division)
{
  this->counter = 0;  
  this->clock_division = clock_division;
  this->clocked = false;
  this->my_output = 0;

  this->clock_input = NULL;
}

uint32_t ModuleClockDivider::compute()
{
  uint32_t clock = this->readInput(clock_input);
  
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
