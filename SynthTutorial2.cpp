#include "SynthTutorial2.h"

SynthTutorial2::SynthTutorial2(Inputs* inputs)
{
	int sequence[] = { 0, 100, 2300, 4000, 1400, 500, 70, 4092 };

	ModuleSequencer *sequencer = new ModuleSequencer(sequence);
	ModuleWavetableOsc *wavetable = new ModuleWavetableOsc();

	sequencer->clock_input = inputs->gate;

	wavetable->wavetable_input  = inputs->mod;
	wavetable->frequency_input = sequencer;

	this->last_module = wavetable;
}