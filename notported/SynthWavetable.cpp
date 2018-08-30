#include "SynthWavetable.h"

SynthWavetable::SynthWavetable(Inputs *inputs)
{
  ModuleWavetableOsc *osc = new ModuleWavetableOsc();

  osc->wavetable_input = inputs->mod;
  osc->frequency_input = inputs->sr;

  this->last_module = osc;
}
