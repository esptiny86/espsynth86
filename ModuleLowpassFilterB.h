/*
 *  +-----------------------+
 *  | ModuleLowpassFilterB  |
 *  |-----------------------|
 *  > audio_input           |
 *  > cutoff_input          |
 *  > resonance_input       |
 *  |                       |
 *  |                output >
 *  +-----------------------+
 */
 
#ifndef ModuleLowpassFilterB_h
#define ModuleLowpassFilterB_h

#include "Arduino.h"
#include "Module.h"
#include "LowPassFilterButterworth.h"

class ModuleLowpassFilterB : public Module
{
  
  public:
    
    // Methods
    ModuleLowpassFilterB();
    uint16_t compute();
    
    // Inputs
    Module *audio_input; 
    Module *cutoff_input;
    Module *resonance_input;

    // A low pass filter object from LowPassFilter.h, not to beconfused with the ModuleLowpassFilter type.
    LowPassFilterButterworth lpf;    
                     
};

#endif
