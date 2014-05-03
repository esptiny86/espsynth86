#ifndef ModuleEqDrum_h
#define ModuleEqDrum_h

#include "Arduino.h"
#include "Module.h"
#include "HighPassFilter.h"

class ModuleEqDrum : public Module
{
  
  public:
    ModuleEqDrum();
    uint32_t compute();
    uint32_t stop_playback();

    // Inputs
    Module *drum_selection_input;
    Module *trigger_input;
    Module *sample_rate_input;    
    
  private:
    int drum_selection;
    boolean triggered;
    boolean playing;
    HighPassFilter hpf;
    
    uint32_t t;           // Accumulator used in equations 
    uint32_t w;           // The final output of the equation
   
    // 19.13 fixed point number (using the upper 19 bits for holding the usable
    // numbers and an additional 13 bits (0-8192) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_20_12_index;
    uint32_t increment_by;
    
    uint32_t SquareRoot(uint32_t a_nInput);
};

#endif
