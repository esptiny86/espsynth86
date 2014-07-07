/*
 *  +----------------------+
 *  | ModuleRingMod        |
 *  |----------------------|
 *  > audio_input          |
 *  > frequency_input      |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 


#ifndef ModuleRingMod_h
#define ModuleRingMod_h

#include "Arduino.h"
#include "Module.h"

class ModuleRingMod : public Module
{
  
  public:
    ModuleRingMod();
    uint16_t compute();
    
    // Inputs
    Module *audio_input;
    Module *frequency_input;

    // 10.22 fixed point number (using the upper 10 bits for addressing the indexes 
    // up to 1024 (we only need 600), and an additional 22 bits (0-4194304) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_10_22_index;
    uint32_t wavetable_index;
};

#endif
