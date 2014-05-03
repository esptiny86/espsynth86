#ifndef ModuleDelay_h
#define ModuleDelay_h

#include "Arduino.h"
#include "Module.h"

class ModuleDelay : public Module
{
  
  public:
    ModuleDelay();
    uint32_t compute();
    
    // Inputs
    Module *audio_input;
    Module *mix_input;   
    
  private:
    
    uint32_t buffer[1024];
    int buffer_index;
    
    int feedback;
    int mix;  // ranged from 0 to 4095, where 0 == dry, 4095 == wet
    uint32_t delay_output;
};

#endif
