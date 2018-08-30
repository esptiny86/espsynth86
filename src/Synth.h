#ifndef Synth_h
#define Synth_h

#include "Arduino.h"
#include "Inputs.h"
#include "Modules.h"

class Synth
{
  public:
  
    // Methods
    uint16_t run(uint8_t cycle);

    
    // 'last_module' is the last module in the synth.  
    // This module's run() method will be called by the synth.
    Module *last_module; 
};

#endif
