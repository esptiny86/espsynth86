#include "Arduino.h"
#include "ModuleConstant.h"
#include "defines.h"

ModuleConstant::ModuleConstant()
{
  this->value = 0;
  this->no_output_conversion = false;
  this->module_output_bit = OUTPUT_10BIT;
}

ModuleConstant::ModuleConstant(int value)
{
  this->value = value;
  this->no_output_conversion = false;
  this->module_output_bit = OUTPUT_10BIT;
}

uint16_t ModuleConstant::compute()
{
  return(this->value);
}

void ModuleConstant::setValue(uint32_t new_value)
{
  this->value = new_value;
}

uint32_t ModuleConstant::getValue()
{
  return(this->value);
}


