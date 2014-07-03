#include "SynthChords.h"

SynthChords::SynthChords(Inputs* inputs)
{
  	
	ModuleWavetableOsc *wavetable_osc1 = new ModuleWavetableOsc();
	ModuleWavetableOsc *wavetable_osc2 = new ModuleWavetableOsc();
	ModuleWavetableOsc *wavetable_osc3 = new ModuleWavetableOsc();

	ModuleQuantizer *quantizer = new ModuleQuantizer();
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
	ModuleChords *chords = new ModuleChords();
	ModuleMixer3 *mixer_3 = new ModuleMixer3();
	ModuleRotatingRouter3 *rotating_router_3 = new ModuleRotatingRouter3();

	quantizer->cv_input = inputs->sr;
	quantizer->scale_input = inputs->param1;

	chords->root_note_input = quantizer;
	chords->chord_input = inputs->mod;

	rotating_router_3->rotate_input = inputs->gate;
	rotating_router_3->input_1 = chords->note_1_output;
	rotating_router_3->input_2 = chords->note_2_output;
	rotating_router_3->input_3 = chords->note_3_output;

	wavetable_osc1->wavetable_input  = new ModuleConstant(0);
	wavetable_osc1->frequency_input  = rotating_router_3->output_1;

	wavetable_osc2->wavetable_input = inputs->param2;
	wavetable_osc2->frequency_input  = rotating_router_3->output_2;

	wavetable_osc3->wavetable_input = inputs->param3;
	wavetable_osc3->frequency_input  = rotating_router_3->output_3;


	mixer_3->input_1 = wavetable_osc1;
	mixer_3->input_2 = wavetable_osc2;
	mixer_3->input_3 = wavetable_osc3;
/*
	mixer_3->input_1 = rotating_router_3->output_1;
	mixer_3->input_2 = rotating_router_3->output_2;
	mixer_3->input_3 = rotating_router_3->output_3;
*/
	this->last_module = mixer_3;

}