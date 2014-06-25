/*
 *  +----------------------+
 *  | ModuleMultiply       |
 *  |----------------------|
 *  > input_1              |
 *  > input_2              |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// Multiplies the values at input_1 and input_2 and outputs the product.
//
// Example usage:
//
//   ModuleWavetableOsc *wavetable_osc1 = new ModuleWavetableOsc();
//   ModuleWavetableOsc *wavetable_osc2 = new ModuleWavetableOsc();
//   ModuleMultiply *multiply = new ModuleMultiply();
//
//   wavetable_osc1->wavetable_input  = inputs->param1;
//   wavetable_osc2->wavetable_input  = inputs->param2;
//
//   wavetable_osc1->frequency_input  = inputs->sr;
//   wavetable_osc2->frequency_input  = inputs->sr;
//
//   wavetable_osc2->phase_input  = inputs->mod;
//
//   multiply->input_1 = wavetable_osc1;
//   multiply->input_2 = wavetable_osc2;
//
//   this->last_module = multiply;


#ifndef ModuleMultiply_h
#define ModuleMultiply_h

#include "Module.h"

class ModuleMultiply : public Module
{
    public:    
  	ModuleMultiply();
    uint16_t compute();  

    // Inputs
    Module *input_1;
    Module *input_2;
};

#endif
