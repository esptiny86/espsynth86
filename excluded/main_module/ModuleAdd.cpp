#include "ModuleAdd.h"
#include "Defines.h"

ModuleAdd::ModuleAdd()
{
  this->input_1 = NULL;
  this->input_2 = NULL; 
}

uint16_t ModuleAdd::compute()
{
  // Read inputs
  uint32_t value_1 = this->readInput(input_1);
  uint32_t value_2 = this->readInput(input_2);

  uint32_t sum = value_1 + value_2;

  if(sum > MAX_CV)
  {
    return(sum >> 12);
  }
  else
  {
    return(sum);
  }
}
