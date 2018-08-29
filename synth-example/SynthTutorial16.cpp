#include "SynthTutorial16.h"

SynthTutorial16::SynthTutorial16(Inputs* inputs)
{
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModuleWaveshaper *wave_shaper = new ModuleWaveshaper();

	wavetable_osc->wavetable_input  = inputs->mod;
	wavetable_osc->frequency_input  = inputs->sr;
 
	wave_shaper->audio_input = wavetable_osc;
	wave_shaper->mix_input = inputs->param1;
	wave_shaper->waveshaper_input = inputs->param2;

	this->last_module = wave_shaper;
}