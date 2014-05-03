#ifndef ModuleDrum_h
#define ModuleDrum_h

#include "Arduino.h"
#include "Module.h"

#define KICK_SAMPLE_LENGTH 4342
#define SNARE_SAMPLE_LENGTH 5222
#define HIHAT_SAMPLE_LENGTH 183

class ModuleDrum : public Module
{
  
  public:
    ModuleDrum();
    uint32_t compute();

    // Inputs
    Module *drum_selection_input;
    Module *trigger_input;
    Module *sample_rate_input;    
    
  private:
    int drum_selection;
    boolean triggered;
    boolean playing;
    
    uint32_t t;  // Accumulator used in equations 
    uint32_t w;  // The final output
   
    // Arrays to hold the sample data
    int kick_sample[KICK_SAMPLE_LENGTH];
    int snare_sample[SNARE_SAMPLE_LENGTH];
    int hihat_sample[HIHAT_SAMPLE_LENGTH];    

    
    // 19.13 fixed point number (using the upper 19 bits for holding the usable
    // numbers and an additional 13 bits (0-8192) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_20_12_index;
    uint32_t increment_by;

    void stop_playback();
};

#endif
