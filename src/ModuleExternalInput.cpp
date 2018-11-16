#include "ModuleExternalInput.h"

void ModuleExternalInput::setup()
{
  this->value = 0;
  this->no_output_conversion = false;
  this->module_output_bit = OUTPUT_10BIT;
}

ModuleExternalInput::ModuleExternalInput(const  char * address, Input_Manager * inputManager)
{
  setup();
  is_osc = true;
  inputManager->osc.push_back(this);
  this->address = address;
};

ModuleExternalInput::ModuleExternalInput(int pot_number, Input_Manager * inputManager)
{
  setup();
  is_osc = false;
  pot_index = pot_number;
  inputManager->pot.push_back(this);    
};

uint16_t ModuleExternalInput::compute()
{
  return(this->value);
}

void ModuleExternalInput::setValue(uint32_t new_value)
{
  this->value = new_value;
}

uint32_t ModuleExternalInput::getValue()
{
  return(this->value);
}

