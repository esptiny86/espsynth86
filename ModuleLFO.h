/*
 *  +----------------------+
 *  | ModuleLFO            |
 *  |----------------------|
 *  > frequency_input      |
 *  > wavetable_input      |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
 
#ifndef ModuleLFO_h
#define ModuleLFO_h

#include "Arduino.h"
#include "Module.h"

#define WAVE_SAMPLES 512

class ModuleLFO : public Module
{
  
  public:
    ModuleLFO();

    // Inputs
    Module *frequency_input;
    Module *wavetable_input;
    
  private:
  
    // Functions
    uint32_t compute();  
  
    // Variables
    uint32_t wavetable_index;
    uint32_t rate;
    uint16_t wavetables[2][WAVE_SAMPLES];  // Array holding the wavetable data
    uint16_t number_of_wavetables;         // The number of wavetables (surprise, surprise)
    uint16_t wavetable;                    // The currenly selected wavetable
    uint32_t increments[128];
    
    // 10.22 fixed point number (using the upper 10 bits for addressing the indexes 
    // up to 1024 (we only need 600), and an additional 22 bits (0-4194304) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_10_22_index;
    uint32_t increment_by;
};

#endif
