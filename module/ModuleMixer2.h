/*
 *  +----------------------+
 *  | ModuleMixer2         |
 *  |----------------------|
 *  > input_1              |
 *  > input_2              |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// 2 input mixer.
//
// Example usage:
//
//   ModuleWavetableOsc *wavetable_osc1 = new WavetableOsc();
//   ModuleWavetableOsc *wavetable_osc2 = new WavetableOsc();
//   ModuleMixer2 *mixer = new ModuleMixer2();
//
//   wavetable_osc1->frequency_input = inputs->sr;
//   wavetable_osc2->frequency_input = inputs->sr;
//
//   wavetable_osc1->wavetable_input = inputs->param1;
//   wavetable_osc2->wavetable_input = inputs->param2;
//
//   mixer->input_1 = wavetable_osc1;
//   mixer->input_2 = wavetable_osc2;
//
//   this->last_module = mixer;
//

#ifndef ModuleMixer2_h
#define ModuleMixer2_h

#include "Module.h"

class ModuleMixer2 : public Module
{
    public:    
  	ModuleMixer2();
    uint16_t compute();  

    // Inputs
    Module *input_1;
    Module *input_2;
};

#endif
