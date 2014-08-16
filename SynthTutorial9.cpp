#include "SynthTutorial9.h"

SynthTutorial9::SynthTutorial9(Inputs* inputs)
{
	// Create modules
	ModuleQuantizer *quantizer = new ModuleQuantizer();	
	ModuleWavetableOsc *osc = new ModuleWavetableOsc();
	ModulePatternGenerator *pattern_generator = new ModulePatternGenerator();
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);

	// Allow the GATE input to override the internal clock
	ext_clock->clock_input = inputs->gate;

	// Wire up the pattern generator
	pattern_generator->cv_pattern_input = inputs->param2;
	pattern_generator->clock_input = ext_clock;
	pattern_generator->length_input = new ModuleConstant(16);

	// Quantize the output of the pattern generator
	quantizer->scale_input = inputs->param1;
	quantizer->cv_input = pattern_generator;

	// Use the quantized output of the pattern generator to 
	// control the frequency of a wavetable oscillator.
	osc->wavetable_input  = inputs->mod;
	osc->frequency_input  = quantizer;

	// Output the audio of the wavetable oscillator
	this->last_module = osc;
}