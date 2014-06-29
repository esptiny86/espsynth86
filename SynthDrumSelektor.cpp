#include "SynthDrumSelektor.h"

SynthDrumSelektor::SynthDrumSelektor(Inputs* inputs)
{
	ModuleEqDrum *drum_sound = new ModuleEqDrum();
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
	ModuleFreeze *freeze = new ModuleFreeze();

	ext_clock->clock_input = inputs->gate;

	drum_sound->sample_rate_input = inputs->sr;
	drum_sound->drum_selection_input = inputs->mod;
	drum_sound->trigger_input = ext_clock;

	freeze->audio_input = drum_sound;
	freeze->freeze_input = inputs->param1;
	freeze->length_input = inputs->param2;

	this->last_module = freeze;
}