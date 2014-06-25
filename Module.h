#ifndef Module_h
#define Module_h

#include "Arduino.h"

class Module
{
  public:
  
    // Methods
    Module(); 
    uint16_t run(uint8_t cycle);        // Run this module.  This is implemented in Module.cpp
    uint16_t readInput(Module *);    // Read one of this module's inputs. This is implemented in Module.cpp
    uint16_t readInput(Module *, int conversion); // See defines.h for a list of conversions
    uint16_t readInput(Module *, uint32_t map_low, uint32_t map_high); // Read input and map the results
    virtual uint16_t compute() = 0;  // Compute the output of the module. Pure virtual function.  This must be implemented in the derived class.

    // Variables
    uint8_t cycle;                    // Current interrupt cycle
    uint16_t output;               // Instance variable to store the module's output
    boolean no_output_conversion;  // Set this to true in the derived class in order to skip any output scaling
};

#endif
