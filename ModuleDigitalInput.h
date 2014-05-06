/*
 *   +----------------------+
 *   | ModuleDigitalInput   |
 *   |----------------------|
 *   |                      |
 *   |               output >
 *   +----------------------+
 *
 */
// =============================================================================
// 
// ModuleDigitalInput is used for reading one of the digital inputs of the Arduino.
// The pin number of the input to be read is passed in the constructor.  Pin
// numbers are defined in defines.h.  Outputs "0" for low and "4095" for high.
//
// Unlike analog pins, the pinMode for digital pins must be set in the Arduino's
// setup() routine, liks so:
//
// pinMode([pin number], INPUT);
//
// You should never need to instantiate a ModuleDigitalInput yourself.  All of
// the Equation Composer's input modules are created for you and stored in the
// Inputs (see Inputs.h/Inputs.cpp) object.

#ifndef ModuleDigitalInput_h
#define ModuleDigitalInput_h

#include "ModuleInput.h"

class ModuleDigitalInput : public ModuleInput
{
  
  public:
    ModuleDigitalInput(int pin);
    uint32_t read();
    uint32_t compute();
};

#endif
