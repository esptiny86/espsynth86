#include "SynthDrumSelektor.h"

SynthDrumSelektor::SynthDrumSelektor(Inputs* inputs)
{
	ModuleEqDrum *drum_sound = new ModuleEqDrum();
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);

	ext_clock->clock_input = inputs->gate;

	drum_sound->sample_rate_input = inputs->sr;
	drum_sound->drum_selection_input = inputs->mod;
	drum_sound->trigger_input = ext_clock;

	this->last_module = drum_sound;
}