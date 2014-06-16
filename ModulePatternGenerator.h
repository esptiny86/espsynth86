/*
 *   +-------------------------+
 *   | ModulePatternGenerator  |
 *   |-------------------------|
 *   > clock_input             |
 *   > pattern_input           |
 *   > length_input            |
 *   |                         |
 *   |                  output >
 *   +-------------------------+
 *
*/
// =============================================================================
// 
// ModulePatternGenerator is a clocked pattern generator with selectable
// pattern and pattern length.  There are 512 internal patterns which can be
// anywhere from 0 to 64 steps in length.  These limitations were created to 
// avoid sensitivity to line noise.
//
// Example usage:
//
//    ModuleQuantizer *quantizer = new ModuleQuantizer(); 
//    ModuleWavetableOsc *osc = new ModuleWavetableOsc();
//    ModulePatternGenerator *pattern_generator = new ModulePatternGenerator();
//    ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
//
//    ext_clock->clock_input = inputs->gate;
//
//    pattern_generator->clock_input = ext_clock; 
//    pattern_generator->pattern_input = inputs->param2;
//    pattern_generator->length_input = new ModuleConstant(16);
//
//    quantizer->scale_input = inputs->param1;
//    quantizer->cv_input = pattern_generator;
//
//    osc->wavetable_input  = inputs->mod;
//    osc->frequency_input  = quantizer;
//
//    this->last_module = osc;
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
    uint32_t compute();
    
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
    uint32_t old_clock;
    uint32_t latched_cv_output;
    uint32_t latched_gate_output;

    Rand cv_rand;
    Rand gate_rand;
};

#endif
