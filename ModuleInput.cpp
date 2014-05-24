#include "Arduino.h"
#include "ModuleInput.h"
#include "defines.h"

ModuleInput::ModuleInput()
{
  this->value = 0;
}

uint32_t ModuleInput::run()
{ 
  return(this->value);
}

void ModuleInput::setValue(uint32_t new_value)
{
  this->value = new_value;
}

uint32_t ModuleInput::getValue()
{
  return(this->value);
}
