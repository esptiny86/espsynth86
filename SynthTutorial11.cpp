#include "SynthTutorial11.h"

SynthTutorial11::SynthTutorial11(Inputs* inputs)
{
  ModuleWavetableOsc *wavetable_osc1 = new ModuleWavetableOsc();
  ModuleWavetableOsc *wavetable_osc2 = new ModuleWavetableOsc();
  ModuleMixer2 *mixer = new ModuleMixer2();

  wavetable_osc1->wavetable_input  = inputs->param1;
  wavetable_osc2->wavetable_input  = inputs->param2;

  wavetable_osc1->frequency_input  = inputs->sr;
  wavetable_osc2->frequency_input  = inputs->sr;

  wavetable_osc2->phase_input  = inputs->mod;

  mixer->input_1 = wavetable_osc1;
  mixer->input_2 = wavetable_osc2;

  this->last_module = mixer;
}