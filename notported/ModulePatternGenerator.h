/*
 *   +-------------------------+
 *   | ModulePatternGenerator  |
 *   |-------------------------|
 *   > clock_input             |
 *   > cv_pattern_input        |
 *   > gate_pattern_input      |
 *   > gate_density_input      | 
 *   > length_input            |
 *   |                         |
 *   |               cv_output >
 *   |             gate_output >
 *   +-------------------------+
 *
*/
// =============================================================================
// 
// ModulePatternGenerator is a clocked pattern generator with both pattern and
// gate outputs.  There are 512 internal patterns which can be anywhere from 0 
// to 64 steps in length.  The gate pattern can be selected independently from
// the cv pattern, although both the cv and gate patterns are the same length.
//
//
// Example usage:
//
//    ModuleQuantizer *quantizer = new ModuleQuantizer(); 
//    ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
//    ModulePatternGenerator *pattern_generator = new ModulePatternGenerator();
//    ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
//    ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
//    ModuleENV *envelope_generator = new ModuleENV();
//    ModuleSampleAndHold *sample_and_hold = new ModuleSampleAndHold();
//    ModuleDelay *delay = new ModuleDelay();
//
//    ext_clock->clock_input = inputs->gate;
//
//    pattern_generator->cv_pattern_input = inputs->param1;
//    pattern_generator->gate_pattern_input = inputs->param2;
//    pattern_generator->gate_density_input = inputs->param3;
//    pattern_generator->clock_input = ext_clock;
//    pattern_generator->length_input = new ModuleConstant(16);
//
//    sample_and_hold->sample_input = pattern_generator;
//    sample_and_hold->trigger_input = pattern_generator->gate_output;
//
//    quantizer->scale_input = new ModuleConstant(1);
//    quantizer->cv_input = sample_and_hold;
//
//    wavetable_osc->wavetable_input  = inputs->mod;
//    wavetable_osc->frequency_input  = quantizer;
//
//    envelope_generator->slope_input = new ModuleConstant(0);
//    envelope_generator->frequency_input = new ModuleConstant(1000);
//    envelope_generator->trigger_input = pattern_generator->gate_output;
//
//    lowpass_filter->audio_input = wavetable_osc;
//    lowpass_filter->cutoff_input = envelope_generator;
//    lowpass_filter->resonance_input = new ModuleConstant(0);
//
//    this->last_module = lowpass_filter;
//
 
#ifndef ModulePatternGenerator_h
#define ModulePatternGenerator_h

#include "Arduino.h"
#include "Module.h"
#include "ModuleOutput.h"
#include "Rand.h"

class ModulePatternGenerator : public Module
{
  
  public:
  
    ModulePatternGenerator();
    uint16_t compute();
    
    // Inputs
    Module *clock_input;
    Module *cv_pattern_input;
    Module *gate_pattern_input;
    Module *gate_density_input;    
    Module *length_input;

    // Outputs
    ModuleOutput *output;
    ModuleOutput *gate_output;    

  private:
  
    int step;
    boolean clocked;
    boolean first_iteration;
    uint16_t old_clock;
    uint16_t latched_cv_output;
    uint16_t latched_gate_output;

    Rand cv_rand;
    Rand gate_rand;
};

#endif
