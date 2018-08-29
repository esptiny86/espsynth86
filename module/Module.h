#ifndef Module_h
#define Module_h

#include "Arduino.h"

class Module
{
  public:
  
    // Methods
    Module(); 

    // run(cycle)
    //
    // The run() method uses the cycle iterator to ensure that it isn't being 
    // run twice in a single interrupt cycle.  Then run() calls the module's 
    // compute() method and returns the results.  No need to override this 
    // method.

    uint16_t run(uint8_t cycle); 

    // readInput(..)
    //
    // The readInput(..) methods take a module * as a parameter, calls the
    // run() method on that module, then returns the results.  An input to a
    // module is really just a pointer to another module.

    uint16_t readInput(Module *); // Read one of this module's inputs. This is implemented in Module.cpp
    uint16_t readInput(Module *, int conversion); // See defines.h for a list of conversions
    uint16_t readInput(Module *, uint32_t map_low, uint32_t map_high); // Read input and map the results

    // compute()
    //
    // Compute the output of the module. Pure virtual function.  This is the
    // method of a module that actually -does stuff- and must be implemented
    // in the derived class.

    virtual uint16_t compute() = 0;

    // Variables
    uint8_t cycle;                 // Current interrupt cycle
    uint16_t output;               // Instance variable to store the module's output
    boolean no_output_conversion;  // Set this to true in the derived class in order to skip any output scaling
};

#endif
