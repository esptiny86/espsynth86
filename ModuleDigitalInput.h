/*
 *   +----------------------+
 *   | ModuleDigitalInput   |
 *   |----------------------|
 *   |                      |
 *   |               output >
 *   +----------------------+
 *
 */
 
#ifndef ModuleDigitalInput_h
#define ModuleDigitalInput_h

#include "ModuleInput.h"

class ModuleDigitalInput : public ModuleInput
{
  
  public:
    
    // Methods
    ModuleDigitalInput(int pin);
    uint32_t read();
    uint32_t compute();
};

#endif
