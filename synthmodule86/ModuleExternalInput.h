#ifndef MODULEXTINPUT
#define MODULEXTINPUT

#include "Arduino.h"
#include "Module.h"
#include "Defines.h"
#include "Vector.h"

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
  void setup();
  ModuleExternalInput(const  char * address, Input_Manager * inputManager);
  ModuleExternalInput(int pot_number, Input_Manager * inputManager);
  uint16_t compute();
  void setValue(uint32_t new_value);
  uint32_t getValue();
};

#endif
