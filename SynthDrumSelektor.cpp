#include "SynthDrumSelektor.h"

SynthDrumSelektor::SynthDrumSelektor(Inputs* inputs)
{
	ModuleEqDrum *drum_sound = new ModuleEqDrum();

	drum_sound->sample_rate_input = inputs->sr;
	drum_sound->drum_selection_input = inputs->mod;
	drum_sound->trigger_input = inputs->gate;

	this->last_module = drum_sound;
}