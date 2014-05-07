#include "SynthTutorial2.h"

SynthTutorial2::SynthTutorial2(Inputs* inputs, EquationsWavetable *equations_wavetable)
{
	int sequence[] = { 0, 100, 2300, 4000, 1400, 500, 70, 4092 };

	ModuleSequencer *sequencer = new ModuleSequencer(sequence);
	ModuleWavetable *wavetable = new ModuleWavetable(equations_wavetable);

	sequencer->clock_input = inputs->gate;

	wavetable->equation_input  = inputs->mod;
	wavetable->frequency_input = sequencer;

	this->last_module = wavetable;
}