#include "SynthTutorial8.h"

SynthTutorial8::SynthTutorial8(Inputs* inputs)
{
	// Create an lfo, quantizer, and oscillator
	// They're going to be patched together like:
	//
	// lfo ---> quantizer ---> oscillator
	// 
	ModuleLFO *lfo = new ModuleLFO();
	ModuleQuantizer *quantizer = new ModuleQuantizer();
	ModuleWavetableOsc *osc = new ModuleWavetableOsc();

	// Control the LFO rate and waveform via inputs
	lfo->frequency_input = inputs->sr;
	lfo->wavetable_input = inputs->param2;

	// Wire the output of the lfo to the input of the quantizer
	quantizer->scale_input = inputs->param1;
	quantizer->cv_input = lfo;

	// Wire the output of the quantizer to the frequency
	// input of the oscillator.
	osc->wavetable_input  = inputs->mod;
	osc->frequency_input  = quantizer;

	this->last_module = osc;
}