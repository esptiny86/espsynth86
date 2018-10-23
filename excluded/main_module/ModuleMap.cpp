#include "Arduino.h"
#include "ModuleMap.h"
#include "defines.h"

ModuleMap::ModuleMap(uint32_t low, uint32_t high)
{
  this->no_output_conversion = true;
  this->low = low;
  this->high = high;
}

uint16_t ModuleMap::compute()
{  
  return(map(this->readInput(input), 0, 4095, low, high));
}