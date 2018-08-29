/*
 *  +----------------------+
 *  | ModuleSampleAndHold  |
 *  |----------------------|
 *  > trigger_input        |
 *  > sample_input         |
 *  |               output >
 *  +----------------------+
 *
 *
 */
// =============================================================================
// 
// ModuleSampleAndHold acts like a traditional analog Sample&Hold module.  
// A rising clock signal at trigger_input samples the value at sample_input and
// outputs it.
//
// Example usage:
//
//   ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
//   ModulePatternGenerator *pattern_generator = new ModulePatternGenerator();
//   ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
//   ModuleSampleAndHold *sample_and_hold = new ModuleSampleAndHold();
//
//   ext_clock->clock_input = inputs->gate;
//
//   pattern_generator->cv_pattern_input = inputs->param1;
//   pattern_generator->gate_pattern_input = inputs->param2;
//   pattern_generator->gate_density_input = inputs->param3;
//   pattern_generator->clock_input = ext_clock;
//   pattern_generator->length_input = new ModuleConstant(16);
//
//   sample_and_hold->sample_input = pattern_generator->cv_output;
//   sample_and_hold->trigger_input = pattern_generator->gate_output;
//
//   wavetable_osc->wavetable_input  = inputs->mod;
//   wavetable_osc->frequency_input  = pattern_generator;
//
//	 this->last_module = wavetable_osc;

 
#ifndef ModuleSampleAndHold_h
#define ModuleSampleAndHold_h

#include "Module.h"

class ModuleSampleAndHold : public Module
{
  public:
    ModuleSampleAndHold();
    uint16_t compute();
    
    // Inputs
    Module *trigger_input;      
    Module *sample_input;      
    
  private:
    uint16_t sampled_value;
    boolean triggered;
};

#endif