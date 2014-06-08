#include "SynthTutorial2.h"

SynthTutorial2::SynthTutorial2(Inputs* inputs)
{
	int sequence[] = { 0, 100, 2300, 4000, 1400, 500, 70, 4092 };

	ModuleSequencer *sequencer = new ModuleSequencer(sequence);
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();

	sequencer->clock_input = inputs->gate;

	wavetable_osc->wavetable_input  = inputs->mod;
	wavetable_osc->frequency_input = sequencer;

	this->last_module = wavetable_osc;
}