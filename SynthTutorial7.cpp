#include "SynthTutorial7.h"

SynthTutorial7::SynthTutorial7(Inputs* inputs)
{
	ModuleClock *clock = new ModuleClock(120);
	ModuleClockDivider *clock_divider = new ModuleClockDivider();
	ModuleLFO *lfo = new ModuleLFO();
	ModuleEqDrum *drum_sound= new ModuleEqDrum();
	ModuleMap *map_0_24 = new ModuleMap(0,24);

	lfo->frequency_input = inputs->param1;
	lfo->wavetable_input = inputs->param2;

	map_0_24->input = lfo;

	clock_divider->clock_input = clock;
	clock_divider->division_input = map_0_24;

	drum_sound->drum_selection_input = inputs->mod;
	drum_sound->sample_rate_input = inputs->sr;
	drum_sound->trigger_input = clock_divider;

	this->last_module = drum_sound;
}