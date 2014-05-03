/*
 *   +----------------------+
 *   | ModuleAnalogInput    |
 *   |----------------------|
 *   |                      |
 *   |               output >
 *   +----------------------+
 *
 */
 
#ifndef ModuleAnalogInput_h
#define ModuleAnalogInput_h

#include "ModuleInput.h"

class ModuleAnalogInput : public ModuleInput
{
  private:
      uint32_t compute();
      
  public:
    
    // Methods
    ModuleAnalogInput(int input_pin);    
    uint32_t read();
};

#endif
