#include "SynthTutorial7.h"

SynthTutorial7::SynthTutorial7(Inputs* inputs)
{
	// Create a clock, clock divider, lfo, map, and drum sound module
	ModuleExtClock *ext_clock = new ModuleExtClock(120);
	ModuleClockDivider *clock_divider = new ModuleClockDivider();
	ModuleLFO *lfo = new ModuleLFO();
	ModuleEqDrum *drum_sound= new ModuleEqDrum();
	ModuleMap *map_0_24 = new ModuleMap(0,24);

	// Allow the GATE input to override the internal clock
	ext_clock->clock_input = inputs->gate;

	// Control the LFO's frequency and wavetable using
	// the param1 and param2 inputs
	lfo->frequency_input = inputs->param1;
	lfo->wavetable_input = inputs->param2;

	// Map the LFO's output to 0 - 24
	map_0_24->input = lfo;

	// Wire up the clock divider
	clock_divider->clock_input = ext_clock;
	clock_divider->division_input = map_0_24;

	// Wire up the drum sound.  The drum sound
	// is triggered by the clock divider.
	drum_sound->drum_selection_input = inputs->mod;
	drum_sound->sample_rate_input = inputs->sr;
	drum_sound->trigger_input = clock_divider;

	// Output the sound of the drum
	this->last_module = drum_sound;
}