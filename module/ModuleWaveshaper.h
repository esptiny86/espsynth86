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
    uint16_t compute();
    
    // Inputs
    Module *audio_input; 
    Module *mix_input;
    Module *waveshaper_input;    
};

#endif
