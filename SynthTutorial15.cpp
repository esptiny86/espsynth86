#include "SynthTutorial15.h"

SynthTutorial15::SynthTutorial15(Inputs* inputs)
{
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModuleWaveFolder *wave_folder = new ModuleWaveFolder();

	wavetable_osc->wavetable_input  = inputs->mod;
	wavetable_osc->frequency_input  = inputs->sr;
 
	wave_folder->audio_input = wavetable_osc;
	wave_folder->lower_clipping_level_input = inputs->param1;
	wave_folder->upper_clipping_level_input = inputs->param2;

	this->last_module = wave_folder;
}