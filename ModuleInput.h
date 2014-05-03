#ifndef ModuleInput_h
#define ModuleInput_h

#include "Arduino.h"
#include "Module.h"

class ModuleInput : public Module
{
  
  public:
    
    // Methods
    ModuleInput();
    uint32_t run();
    
    void setValue(uint32_t value);
    uint32_t getValue();

    virtual uint32_t read() = 0;  // Pure virtual function.  This must be implemented in the derived class.
    
    // Variables
    uint32_t value; // The value of the input
    int pin;        // The pin for the input
};

#endif
