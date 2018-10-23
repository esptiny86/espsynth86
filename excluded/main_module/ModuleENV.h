/*
 *  +----------------------+
 *  | ModuleENV            |
 *  |----------------------|
 *  > gate_input           |
 *  > frequency_input      |
 *  > slope_input          |
 *  |                      |
 *  |               output >
 *  |      inverted_output >
 *  |           end_output >
 *  +----------------------+
 */
 //
// =============================================================================
// 
// ModuleENV is a simple envelope generator, similar to an ADSR, but uses preset
// slopes and has no sustain.  Playback starts when the gate_input goes high.
// The slope playback speed is controlled by the frequency_input.  The slope_input
// selects among the various possible sloped defined in GlobalSlopes.cpp
//
// Example Usage:
//
//  // Create the modules
//  ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
//  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
//  ModuleENV *envelope_generator = new ModuleENV();
//
//  // Patch up envelope generator
//  envelope_generator->slope_input = inputs->param2;
//  envelope_generator->trigger_input = inputs->gate;
//  envelope_generator->frequency_input = inputs->param1;
//
//  // Patch up oscillator
//  wavetable_osc->frequency_input = inputs->sr;
//  wavetable_osc->wavetable_input = inputs->mod; 
//  
//  // Patch up filter
//  lowpass_filter->audio_input = wavetable_osc;
//  lowpass_filter->cutoff_input = envelope_generator;
//  lowpass_filter->resonance_input = inputs->param3;
//
//  this->last_module = lowpass_filter;
//

#ifndef ModuleENV_h
#define ModuleENV_h

#include "Arduino.h"
#include "Module.h"
#include "ModuleOutput.h"

#define ENV_INACTIVE 0
#define ENV_PLAYING 1


class ModuleENV : public Module
{
  
  public:
    ModuleENV();

    // Inputs
    Module *frequency_input;
    Module *slope_input;
    Module *trigger_input;

    // Outputs
    ModuleOutput *output;
    ModuleOutput *inverted_output;
    ModuleOutput *end_output;    
    
  private:
  
    // Functions
    uint16_t compute();  

    // Variables
    uint32_t slope_index;
    uint32_t frequency;
    uint16_t slope;
    uint32_t increment;
    bool triggered;
    int state;
    uint32_t env_output;
    
    // 10.22 fixed point number (using the upper 10 bits for addressing the indexes 
    // up to 1024 (we only need 600), and an additional 22 bits (0-4194304) for 
    // simulating fractional values
    uint32_t fixed_point_10_22_index;
    uint32_t increment_by;
};

#endif
