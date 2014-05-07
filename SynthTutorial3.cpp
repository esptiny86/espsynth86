#include "SynthTutorial3.h"

SynthTutorial3::SynthTutorial3(Inputs* inputs)
{
	ModuleDrumSequencer *kick_drum_sequencer = new ModuleDrumSequencer(0);

	kick_drum_sequencer->pattern_input = inputs->mod;
	kick_drum_sequencer->clock_input = inputs->gate;

	this->last_module = kick_drum_sequencer;
}