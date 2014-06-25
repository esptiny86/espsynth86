/*
 *  +----------------------+
 *  | ModuleSwitch         |
 *  |----------------------|
 *  > select_input         |
 *  > a_input              |
 *  > b_input              |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleSwitch routes either a_input or b_input to the output depending on the
// value at select_input.  If select_input is greater than MID_CV, intput_b
// is routed to the output.  Otherwise input_a is routed to the output.
//
// Example usage:
//
//	ModuleWavetableOsc *osc1 = new ModuleWavetableOsc();
//	osc1->wavetable_input  = inputs->param2;
//	osc1->frequency_input  = inputs->param3;
//
//	ModuleWavetableOsc *osc2 = new ModuleWavetableOsc();
//	osc2->wavetable_input  = new ModuleConstant(6);
//	osc2->frequency_input  = inputs->sr;
//
//	ModuleWavetableOsc *osc3 = new ModuleWavetableOsc();
//	osc3->wavetable_input  = inputs->mod;
//	osc3->frequency_input  = inputs->param1;
//
//	ModuleSwitch *switchAB = new ModuleSwitch();
//	switchAB->a_input = osc1;
//	switchAB->b_input = osc2;
//	switchAB->select_input = osc3;
//
//	this->last_module = switchAB;

 
#ifndef ModuleSwitch_h
#define ModuleSwitch_h

#include "Module.h"

class ModuleSwitch : public Module
{
  public:
    ModuleSwitch();
    uint16_t compute();
    
    // Inputs
    Module *select_input;
    Module *a_input;
    Module *b_input;
};

#endif