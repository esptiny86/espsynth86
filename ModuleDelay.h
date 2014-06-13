#ifndef ModuleDelay_h
#define ModuleDelay_h

#include "Arduino.h"
#include "Module.h"

#define DELAY_BUFFER_SIZE 4096

class ModuleDelay : public Module
{
  
  public:
    ModuleDelay();
    uint32_t compute();
    
    // Inputs
    Module *audio_input;
    Module *mix_input;   
    Module *feedback_input;
    Module *length_input; 

  private:
    
    uint16_t buffer[DELAY_BUFFER_SIZE];
    int buffer_index;
    
    uint16_t feedback;
    int mix;  // ranged from 0 to 4095, where 0 == dry, 4095 == wet
    uint32_t delay_output;
};

#endif
