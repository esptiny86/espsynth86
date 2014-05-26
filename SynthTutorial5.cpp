#include "SynthTutorial5.h"

SynthTutorial5::SynthTutorial5(Inputs* inputs)
{
	ModuleWavetableOsc *osc1 = new ModuleWavetableOsc();
	osc1->wavetable_input  = inputs->param2;
	osc1->frequency_input  = inputs->param3;

	ModuleWavetableOsc *osc2 = new ModuleWavetableOsc();
	osc2->wavetable_input  = new ModuleConstant(6);
	osc2->frequency_input  = inputs->sr;

	ModuleWavetableOsc *osc3 = new ModuleWavetableOsc();
	osc3->wavetable_input  = inputs->mod;
	osc3->frequency_input  = inputs->param1;

	ModuleSwitch *switchAB = new ModuleSwitch();
	switchAB->a_input = osc1;
	switchAB->b_input = osc2;
	switchAB->select_input = osc3;

	this->last_module = switchAB;
}