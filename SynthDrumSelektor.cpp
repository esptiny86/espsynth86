#include "SynthDrumSelektor.h"

SynthDrumSelektor::SynthDrumSelektor(Inputs* inputs)
{
	// Create modules
	ModuleEqDrum *drum_sound = new ModuleEqDrum();
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
	ModuleFreeze *freeze = new ModuleFreeze();
	ModuleWaveFolder *wave_folder = new ModuleWaveFolder();

	// Allow the GATE input to override the internal clock
	ext_clock->clock_input = inputs->gate;

	// Wire up the drum player.  Trigger the drum player
	// with either the internal or external clock
	drum_sound->sample_rate_input = inputs->sr;
	drum_sound->drum_selection_input = inputs->mod;
	drum_sound->trigger_input = ext_clock;

	// Send the drum sounds through a freeze effect
	freeze->audio_input = drum_sound;
	freeze->freeze_input = inputs->param1;
	freeze->length_input = inputs->param2;

	// Apply wave folding
	wave_folder->audio_input = freeze;
	wave_folder->lower_clipping_level_input = inputs->param3;
	wave_folder->upper_clipping_level_input = inputs->param3;

	// Output the audio of the wave folder
	this->last_module = wave_folder;
}