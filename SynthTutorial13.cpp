#include "SynthTutorial13.h"

SynthTutorial13::SynthTutorial13(Inputs* inputs)
{
  ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
  ModuleBitReducer *bit_reducer = new ModuleBitReducer();

  wavetable_osc->wavetable_input  = inputs->mod;
  wavetable_osc->frequency_input  = inputs->sr;
  
  bit_reducer->audio_input = wavetable_osc;
  bit_reducer->bit_input = inputs->param1;

  this->last_module = bit_reducer;
}