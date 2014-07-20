#ifndef ModuleSamplePlayer_h
#define ModuleSamplePlayer_h

#include "Arduino.h"
#include "Module.h"

class ModuleSamplePlayer : public Module
{
  
  public:
    ModuleSamplePlayer();
    uint16_t compute();

    // Inputs
    Module *sample_selection_input;
    Module *trigger_input;
    Module *sample_rate_input;    
    
  private:
    boolean triggered;
    boolean playing;
    
    uint32_t t;  // Accumulator used in equations 
    uint32_t w;  // The final output
    
    uint32_t fixed_point_20_12_index;

    void stop_playback();
};

#endif
