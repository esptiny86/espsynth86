#include "SynthTutorial9.h"

SynthTutorial9::SynthTutorial9(Inputs* inputs)
{
	ModuleQuantizer *quantizer = new ModuleQuantizer();	
	ModuleWavetableOsc *osc = new ModuleWavetableOsc();
	ModulePatternGenerator *pattern_generator = new ModulePatternGenerator();
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);

	ext_clock->clock_input = inputs->gate;

	pattern_generator->cv_pattern_input = inputs->param2;
	pattern_generator->clock_input = ext_clock;
	pattern_generator->length_input = new ModuleConstant(16);

	quantizer->scale_input = inputs->param1;
	quantizer->cv_input = pattern_generator;

	osc->wavetable_input  = inputs->mod;
	osc->frequency_input  = quantizer;

	this->last_module = osc;
}