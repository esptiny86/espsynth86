#include "SynthWavetableFolder.h"

SynthWavetableFolder::SynthWavetableFolder(Inputs* inputs)
{

	// Create the modules
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModuleBitReducer *bit_reducer = new ModuleBitReducer();
	ModuleWaveFolder *wave_folder = new ModuleWaveFolder();
	ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();

	// Wire up the wavetable oscillator
	wavetable_osc->wavetable_input = inputs->mod;
	wavetable_osc->frequency_input = inputs->sr;

	// Put the wavetable oscillator through a lowpass filter
	lowpass_filter->audio_input = wavetable_osc;
	lowpass_filter->cutoff_input = inputs->param2;
	lowpass_filter->resonance_input = inputs->param3;

	// Wire the output of the lowpass filter into a wave folder
	wave_folder->audio_input = lowpass_filter;
	wave_folder->lower_clipping_level_input = inputs->param1;
	wave_folder->upper_clipping_level_input = inputs->param1;

	// Output the audio of the wave folder
	this->last_module = wave_folder;

}