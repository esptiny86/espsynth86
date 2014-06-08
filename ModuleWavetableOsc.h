/*
 *  +----------------------+
 *  | ModuleWavetableOsc   |
 *  |----------------------|
 *  > frequency_input      |
 *  > wavetable_input      |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleWavetableOsc is a wavetable oscillator with control over frequency and
// wavetable.  The wavetables are defined in Wavetables.cpp.
//
// Example usage:
//
//   ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
//   wavetable_osc->frequency_input = inputs->sr_input;
//   wavetable_osc->wavetable_input = inputs->mod_input;
//   this->last_module = wavetable_osc; 

#ifndef ModuleWavetableOsc_h
#define ModuleWavetableOsc_h

#include "Arduino.h"
#include "Module.h"
#include "ModuleOutput.h"

class ModuleWavetableOsc : public Module
{
  
  public:
    ModuleWavetableOsc();
    uint32_t compute();
    
    // Inputs
    Module *frequency_input;   // Input module for controlling frequency
    Module *wavetable_input;   // Input module for controlling wavetable selection

  private:
    uint32_t wavetable_index;  // An index into the wavetables array
    uint32_t wavetable;        // Which wavetable is currently selected
    uint32_t frequency;        // An index into the increments table
    uint32_t increments[4096];
    
    // 10.22 fixed point number (using the upper 10 bits for addressing the indexes 
    // up to 1024 (we only need 600), and an additional 22 bits (0-4194304) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_10_22_index;
    uint32_t increment_by;
};

#endif
