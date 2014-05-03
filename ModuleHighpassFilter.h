/*
 *  +----------------------+
 *  | ModuleHighpassFilter |
 *  |----------------------|
 *  > audio_input          |
 *  > cutoff_input         |
 *  > resonance_input      |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
 
#ifndef ModuleHighpassFilter_h
#define ModuleHighpassFilter_h

#include "Arduino.h"
#include "Module.h"
#include "HighPassFilter.h"

class ModuleHighpassFilter : public Module
{
  
  public:
    
    // Methods
    ModuleHighpassFilter();
    uint32_t compute();
    
    // Inputs
    Module *audio_input; 
    Module *cutoff_input;
    Module *resonance_input;

    // Public variables
    
    // A high pass filter object from HighPassFilter.h, not to be
    // confused with the ModuleLowpassFilter type.
    HighPassFilter hpf;    
                     
};

#endif
