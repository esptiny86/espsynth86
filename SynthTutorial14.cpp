#include "SynthTutorial14.h"

SynthTutorial14::SynthTutorial14(Inputs* inputs)
{
	// Crate a wavetable oscillator and a rotating router
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModuleRotatingRouter3 *rotating_router = new ModuleRotatingRouter3();
	 
	// Hook up param1, param2, and param3 inputs to the rotating router
	// When the router is gated, the outputs will rotate
	rotating_router->input_1 = inputs->param1->smooth;
	rotating_router->input_2 = inputs->param2->smooth;
	rotating_router->input_3 = inputs->param3->smooth;
	rotating_router->rotate_input = inputs->gate;
	 
	// Wire the output of the rotating router to the wavetable selection
	// input of the wavetable oscillator
	wavetable_osc->wavetable_input = rotating_router;
	// \_The above line could have also been:
	// wavetable_osc->wavetable_input = rotating_router->output_1;

	// Use the SR input to control the frequency
	wavetable_osc->frequency_input = inputs->sr;
	 
	// Output the audio from the wavetable oscillator
	this->last_module = wavetable_osc;
}