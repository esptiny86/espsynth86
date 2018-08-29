#include "SynthWavetableDelay.h"

SynthWavetableDelay::SynthWavetableDelay(Inputs* inputs)
{
	// Create modules
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModuleDelay *delay = new ModuleDelay();

	// Wire up the wavetable oscillator
	wavetable_osc->wavetable_input  = inputs->mod;
	wavetable_osc->frequency_input  = inputs->sr;

	// Put the wavetable oscillator through a delay
	delay->audio_input = wavetable_osc;
	delay->mix_input = inputs->param1;
	delay->feedback_input = inputs->param2;
	delay->length_input = inputs->param3;

	// Output the audio of the delay
	this->last_module = delay;
}