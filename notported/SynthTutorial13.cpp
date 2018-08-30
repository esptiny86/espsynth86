#include "SynthTutorial13.h"

SynthTutorial13::SynthTutorial13(Inputs* inputs)
{
	// Create wavetable and bit reducer modules
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModuleBitReducer *bit_reducer = new ModuleBitReducer();

	// Control the wavetable selection using MOD
	// Control the frequency using SR
	wavetable_osc->wavetable_input  = inputs->mod;
	wavetable_osc->frequency_input  = inputs->sr;
  
  	// Bit reduce the output of the wavetable oscillator
  	// Use param1 to control the bit rate
	bit_reducer->audio_input = wavetable_osc;
	bit_reducer->bit_input = inputs->param1;

	// Output the audio from the bit reducer
	this->last_module = bit_reducer;
}