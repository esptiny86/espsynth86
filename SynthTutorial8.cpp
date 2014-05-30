#include "SynthTutorial8.h"

SynthTutorial8::SynthTutorial8(Inputs* inputs)
{
	ModuleLFO *lfo = new ModuleLFO();
	ModuleQuantizer *quantizer = new ModuleQuantizer();
	ModuleWavetableOsc *osc = new ModuleWavetableOsc();

	lfo->frequency_input = inputs->sr;
	lfo->wavetable_input = inputs->param2;

	quantizer->scale_input = inputs->param1;
	quantizer->cv_input = lfo;

	osc->wavetable_input  = inputs->mod;
	osc->frequency_input  = quantizer;

	this->last_module = osc;
}