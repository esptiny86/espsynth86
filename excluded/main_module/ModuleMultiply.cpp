#include "ModuleMultiply.h"
#include "Defines.h"

ModuleMultiply::ModuleMultiply()
{
  this->input_1 = NULL;
  this->input_2 = NULL; 
}

uint16_t ModuleMultiply::compute()
{
  // Read inputs
  uint32_t value_1 = this->readInput(input_1);
  uint32_t value_2 = this->readInput(input_2);

  uint32_t product = value_1 * value_2;

  if(product > MAX_CV)
  {
    return(product >> 12);
  }
  else
  {
    return(product);
  }
}
