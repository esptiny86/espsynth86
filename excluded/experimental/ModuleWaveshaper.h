/*
 *  +----------------------+
 *  | ModuleWaveshaper     |
 *  |----------------------|
 *  > audio_input          |
 *  |                      |
 *  |               output >
 *  +----------------------+

!!!!!!! This module doesn't work at all yet !!!!!!!!!!!!!!!

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
    Module *amount_input;
                     
};

#endif
