#include "SynthTutorial14.h"

SynthTutorial14::SynthTutorial14(Inputs* inputs)
{
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModuleRotatingRouter3 *rotating_router = new ModuleRotatingRouter3();
	 
	rotating_router->input_1 = inputs->param1;
	rotating_router->input_2 = inputs->param2;
	rotating_router->input_3 = inputs->param3;
	rotating_router->rotate_input = inputs->gate;
	 
	wavetable_osc->frequency_input = inputs->sr;
	wavetable_osc->wavetable_input = rotating_router;
	// The above line could have also been:
	// wavetable_osc->wavetable_input = rotating_router->output_1;
	 
	this->last_module = wavetable_osc;
}