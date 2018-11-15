#ifndef MODULEXTINPUT
#define MODULEXTINPUT

#include "Arduino.h"
#include "Module.h"
#include "Defines.h"

class ModuleExternalInput;

struct Input_Manager{
  Vector<ModuleExternalInput*> osc;
  Vector<ModuleExternalInput*> pot;
};


class ModuleExternalInput : public Module
{
private:
    uint32_t value;  
public:  
  bool is_osc;
  int input_value;
  int pot_index;
  const char * address;

  void setup()
  {
    this->value = 0;
    this->no_output_conversion = false;
    this->module_output_bit = OUTPUT_10BIT;
  }

  ModuleExternalInput(const  char * address, Input_Manager * inputManager)
  {
    setup();
    is_osc = true;
    inputManager->osc.push_back(this);
    this->address = address;
  };

  ModuleExternalInput(int pot_number, Input_Manager * inputManager)
  {
    setup();
    is_osc = false;
    pot_index = pot_number;
    inputManager->pot.push_back(this);    
  };

  uint16_t compute()
  {
    return(this->value);
  }

  void setValue(uint32_t new_value)
  {
    this->value = new_value;
  }

  uint32_t getValue()
  {
    return(this->value);
  }
};

#endif
