#include "SynthChords.h"

SynthChords::SynthChords(Inputs* inputs)
{
  	
  	// Create modules
	ModuleWavetableOsc *wavetable_osc1 = new ModuleWavetableOsc();
	ModuleWavetableOsc *wavetable_osc2 = new ModuleWavetableOsc();
	ModuleWavetableOsc *wavetable_osc3 = new ModuleWavetableOsc();
	ModuleQuantizer *quantizer = new ModuleQuantizer();
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
	ModuleChords *chords = new ModuleChords();
	ModuleMixer3 *mixer_3 = new ModuleMixer3();
	ModuleRotatingRouter3 *rotating_router_3 = new ModuleRotatingRouter3();

	// Quantize the sr input, which will be used as the root 
	// note.  Use the param1 input to select the scale.
	quantizer->cv_input = inputs->sr;
	quantizer->scale_input = inputs->param1;

	// Wire the quantizer output into the chord module's root
	// note input.  Use the mod input to select the chord.
	chords->root_note_input = quantizer;
	chords->chord_input = inputs->mod->smooth;

	// Set up the rotating router to rotate through the
	// 3 notes of the chord when triggered via the gate input.
	rotating_router_3->rotate_input = inputs->gate;
	rotating_router_3->input_1 = chords->note_1_output;
	rotating_router_3->input_2 = chords->note_2_output;
	rotating_router_3->input_3 = chords->note_3_output;

	// Set the wavetable and frequency inputs of the three
	// wavetable oscillators.
	wavetable_osc1->wavetable_input  = new ModuleConstant(0);
	wavetable_osc1->frequency_input  = rotating_router_3->output_1;

	wavetable_osc2->wavetable_input = inputs->param2->smooth;
	wavetable_osc2->frequency_input  = rotating_router_3->output_2;

	wavetable_osc3->wavetable_input = inputs->param3->smooth;
	wavetable_osc3->frequency_input  = rotating_router_3->output_3;

	// Mix the three wavetable oscillators
	mixer_3->input_1 = wavetable_osc1;
	mixer_3->input_2 = wavetable_osc2;
	mixer_3->input_3 = wavetable_osc3;

	// Output the value of the mixer
	this->last_module = mixer_3;
}