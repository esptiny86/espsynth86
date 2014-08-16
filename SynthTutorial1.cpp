#include "SynthTutorial1.h"

SynthTutorial1::SynthTutorial1(Inputs* inputs)
{
	// Create a wavetable oscillator
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();

	// Select the second wavetable (0=first, 1=second, 2=third, etc..)
	wavetable_osc->wavetable_input = new ModuleConstant(1);

	// If you instead wanted to control the wavetable selection 
	// using the mod input, the code would look like:
	//
	// wavetable_osc->wavetable_input  = inputs->mod;
	//

	// Control the frequency using the SR input
	wavetable_osc->frequency_input = inputs->sr;

  	// Output the value of the wavetable oscillator
	this->last_module = wavetable_osc;
}