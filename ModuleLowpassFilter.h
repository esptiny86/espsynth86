/*
 *  +----------------------+
 *  | ModuleLowpassFilter  |
 *  |----------------------|
 *  > audio_input          |
 *  > cutoff_input         |
 *  > resonance_input      |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
 
#ifndef ModuleLowpassFilter_h
#define ModuleLowpassFilter_h

#include "Arduino.h"
#include "Module.h"
#include "LowPassFilter.h"

class ModuleLowpassFilter : public Module
{
  
  public:
    
    // Methods
    ModuleLowpassFilter();
    uint32_t compute();
    
    // Inputs
    Module *audio_input; 
    Module *cutoff_input;
    Module *resonance_input;

    // Public variables
    
    // A low pass filter object from LowPassFilter.h, not to be
    // confused with the ModuleLowpassFilter type.
    LowPassFilter lpf;    
                     
};

#endif
