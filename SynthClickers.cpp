#include "SynthClickers.h"

SynthClickers::SynthClickers(Inputs* inputs)
{

	ModuleExtClock *ext_clock = new ModuleExtClock(120);
	ModuleClockDivider *clock_divider = new ModuleClockDivider();
	ModuleLFO *lfo = new ModuleLFO();
	ModuleEqDrum *drum_sound = new ModuleEqDrum();
	ModuleMap *map_0_24 = new ModuleMap(0,24);
	ModuleMap *map_0_8 = new ModuleMap(0,8);
	ModuleAdd *add = new ModuleAdd();

	ext_clock->clock_input = inputs->gate;

	// Read parameter 3 and scale it between 0 - 5
	map_0_8->input = inputs->param3;

	// Generate an LFO and scale the output to 0 - 24
	lfo->frequency_input = inputs->param1;
	lfo->wavetable_input = inputs->param2;
	map_0_24->input = lfo;

	// Add the scaled LFO value to the scaled param3 value
	add->input_1 = map_0_24;
	add->input_2 = map_0_8;

	// Feed a clock and the LFO + Param3 into the clock divider
	clock_divider->clock_input = ext_clock;
	clock_divider->division_input = add;

	// Trigger the drums
	drum_sound->drum_selection_input = inputs->mod;
	drum_sound->sample_rate_input = inputs->sr;
	drum_sound->trigger_input = clock_divider;

	this->last_module = drum_sound;

}