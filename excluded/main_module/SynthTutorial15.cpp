#include "SynthTutorial15.h"

SynthTutorial15::SynthTutorial15(Inputs* inputs)
{
	// Create modules
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModuleWaveFolder *wave_folder = new ModuleWaveFolder();

	// Wire up wavetable oscillator
	wavetable_osc->wavetable_input = inputs->mod;
	wavetable_osc->frequency_input = inputs->sr;
 
 	// Wave fold the output of the wavetable oscillator
	wave_folder->audio_input = wavetable_osc;
	wave_folder->lower_clipping_level_input = inputs->param1;
	wave_folder->upper_clipping_level_input = inputs->param2;

	// Output the audio of the wave folder
	this->last_module = wave_folder;
}