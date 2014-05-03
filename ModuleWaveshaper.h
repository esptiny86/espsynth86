/*
 *  +----------------------+
 *  | ModuleWaveshaper     |
 *  |----------------------|
 *  > audio_input          |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */


#ifndef ModuleWaveshaper_h
#define ModuleWaveshaper_h

#include "Module.h"

class ModuleWaveshaper : public Module
{
  
  public:
    
    // Methods
    ModuleWaveshaper();
    uint32_t compute();
    
    // Inputs
    Module *audio_input; 
                     
};

#endif
