#include "SynthTutorial5.h"

SynthTutorial5::SynthTutorial5(Inputs* inputs)
{
	// Create modules
	ModuleWavetableOsc *osc1 = new ModuleWavetableOsc();
	ModuleWavetableOsc *osc2 = new ModuleWavetableOsc();
	ModuleWavetableOsc *osc3 = new ModuleWavetableOsc();
	ModuleSwitch *switchAB = new ModuleSwitch();

	// Wire up oscillator #1
	osc1->wavetable_input  = inputs->param2;
	osc1->frequency_input  = inputs->param3;

	// Wire up oscillator #2
	osc2->wavetable_input  = new ModuleConstant(6);
	osc2->frequency_input  = inputs->sr;

	// Wire up oscillator #3
	osc3->wavetable_input  = inputs->mod;
	osc3->frequency_input  = inputs->param1;

	// Wire the output of oscillator #3 into the switching
	// mechanism of switchAB, and rapidly switch between
	// the output from oscillator #1 and #2.
	switchAB->a_input = osc1;
	switchAB->b_input = osc2;
	switchAB->select_input = osc3;

	this->last_module = switchAB;
}