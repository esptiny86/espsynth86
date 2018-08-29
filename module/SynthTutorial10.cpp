#include "SynthTutorial10.h"

SynthTutorial10::SynthTutorial10(Inputs* inputs)
{
	// Create the modules.  There are two different clocked 
	// random number generators: One for the note selection
	// and the other for the wavetable selection
	ModuleQuantizer *quantizer = new ModuleQuantizer();	
	ModuleWavetableOsc *osc = new ModuleWavetableOsc();
	ModuleClockedRandom *clocked_random1 = new ModuleClockedRandom();
	ModuleClockedRandom *clocked_random2 = new ModuleClockedRandom();	
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);

	// Either use an external gate or an internal 120BPM clock
	ext_clock->clock_input = inputs->gate;

	// Wire the clock to both of the clocked random number generators
	clocked_random1->clock_input = ext_clock;
	clocked_random2->clock_input = ext_clock;

	// Wire up a quantizer
	quantizer->scale_input = inputs->param1;
	quantizer->cv_input = clocked_random1;

	// Route the quantizer into the wavetable oscillator
	osc->wavetable_input = clocked_random2;
	osc->frequency_input = quantizer;

	this->last_module = osc;
}