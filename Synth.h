#ifndef Synth_h
#define Synth_h

// Include all of the module definitions so that they
// don't need to be included in the individual synths

#include "Arduino.h"
#include "Inputs.h"
#include "Modules.h"

class Synth
{
  public:
  
    // Methods
    Synth(); // Constructor
    uint32_t run(double cycle);

    
    // 'last_module' is the last module in the synth.  
    // This module's run() method will be called by the synth.
    Module *last_module; 
};

#endif
