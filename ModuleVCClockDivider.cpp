#include "ModuleVCClockDivider.h"
#include "Defines.h"

ModuleVCClockDivider::ModuleVCClockDivider()
{
  this->counter = 0;  
  this->clocked = false;
  this->my_output = 0;
  this->clock_divisions = { 96, 48, 24, 12, 6, 3, 1 };

  // Initialize all inputs
  this->clock_input = NULL;
  this->clock_division_input = NULL;  
}

uint32_t ModuleVCClockDivider::compute()
{
  uint32_t clock = this->readInput(clock_input);
  int clock_division = clock_divisions[this->readInput(clock_division_input, 0, 6)];
  
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
