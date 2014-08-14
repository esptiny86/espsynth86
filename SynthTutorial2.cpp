#include "SynthTutorial2.h"

SynthTutorial2::SynthTutorial2(Inputs* inputs)
{
	// Create a sequence for the sequencer module
	int sequence[] = { 0, 100, 2300, 4000, 1400, 500, 70, 4092 };

	// Create the modules
	ModuleSequencer *sequencer = new ModuleSequencer(sequence);
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();

	// Step the sequencer when the GATE input it triggered
	sequencer->clock_input = inputs->gate;

	// Control the wavetable selection using the MOD input
	wavetable_osc->wavetable_input = inputs->mod;

	// Control the wavetable frequency using the sequencer's output
	wavetable_osc->frequency_input = sequencer;

	// Output the value of the wavetable oscillator
	this->last_module = wavetable_osc;
}