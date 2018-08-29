/*
 *   +-------------------------+
 *   | ModuleChords            |
 *   |-------------------------|
 *   > root_note_input         |
 *   > chord_input             |
 *   |                         |
 *   |           note_1_output >
 *   |           note_2_output >
 *   |           note_3_output >
 *   +-------------------------+
 *
*/
// =============================================================================
// 
// A three-note chord generation module.  Three note values are output, which
// would typically be wired to the inputs of oscillators.  There are 32 Chords 
// available, which are defined in Chords.cpp.
//
// Example usage:
//
//    ModuleWavetableOsc *wavetable_osc1 = new ModuleWavetableOsc();
//    ModuleWavetableOsc *wavetable_osc2 = new ModuleWavetableOsc();
//    ModuleWavetableOsc *wavetable_osc3 = new ModuleWavetableOsc();
//
//    ModuleQuantizer *quantizer = new ModuleQuantizer();
//    ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
//    ModuleChords *chords = new ModuleChords();
//    ModuleMixer3 *mixer_3 = new ModuleMixer3();
//
//    quantizer->cv_input = inputs->sr;
//    quantizer->scale_input = inputs->param1;
//
//    chords->root_note_input = quantizer;
//    chords->chord_input = inputs->mod;
//
//    wavetable_osc1->wavetable_input  = new ModuleConstant(0);
//    wavetable_osc1->frequency_input  = chords->note_1_output;
//
//    wavetable_osc2->wavetable_input = inputs->param2;
//    wavetable_osc2->frequency_input  = chords->note_2_output;
//
//    wavetable_osc3->wavetable_input = inputs->param3;
//    wavetable_osc3->frequency_input  = chords->note_3_output;
//
//    mixer_3->input_1 = wavetable_osc1;
//    mixer_3->input_2 = wavetable_osc2;
//    mixer_3->input_3 = wavetable_osc3;
//
//    this->last_module = mixer_3;
//
 
#ifndef ModuleChords_h
#define ModuleChords_h

#include "Arduino.h"
#include "Module.h"
#include "ModuleOutput.h"
 
class ModuleChords : public Module
{
  
  public:
  
    ModuleChords();
    uint16_t compute();
    
    // Inputs
    Module *root_note_input;
    Module *chord_input;

    // Outputs
    ModuleOutput *note_1_output;
    ModuleOutput *note_2_output;
    ModuleOutput *note_3_output;
};

#endif
