#include "SynthWavetable.h"

SynthWavetable::SynthWavetable(Inputs *inputs)
{
  ModuleOsc *osc = new ModuleOsc();

  osc->wavetable_input = inputs->mod;
  osc->frequency_input = inputs->sr;

  this->last_module = osc;
}
