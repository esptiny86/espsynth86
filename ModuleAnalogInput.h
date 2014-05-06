/*
 *   +----------------------+
 *   | ModuleAnalogInput    |
 *   |----------------------|
 *   |                      |
 *   |               output >
 *   +----------------------+
 *
 */
// =============================================================================
// 
// ModuleAnalogInput is used for reading one of the analog inputs of the Arduino.
// The pin number of the input to be read is passed in the constructor.  Pin
// numbers are defined in defines.h.  Outputs a value ranging from 0 to 4095.
//
// You should never need to instantiate a ModuleAnalogInput yourself.  All of
// the Equation Composer's input modules are created for you and stored in the
// Inputs (see Inputs.h/Inputs.cpp) object.

#ifndef ModuleAnalogInput_h
#define ModuleAnalogInput_h

#include "ModuleInput.h"

class ModuleAnalogInput : public ModuleInput
{
  private:
      uint32_t compute();
      
  public:
    
    ModuleAnalogInput(int input_pin);    
    uint32_t read();
};

#endif
