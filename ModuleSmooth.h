#ifndef ModuleSmooth_h
#define ModuleSmooth_h

#include "Arduino.h"
#include "Module.h"

class ModuleSmooth : public Module
{
  
  public:
    ModuleSmooth();
    uint32_t compute();
    
    // Inputs
    Module *audio_input;
    Module *mix_input;   
    
  private:
    
    uint32_t buffer[6];
    int mix;  // ranged from 0 to 4095, where 0 == dry, 4095 == wet
    uint32_t smooth_output;
};

#endif
