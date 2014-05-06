#include "SynthWavetable.h"

SynthWavetable::SynthWavetable(Inputs *inputs, EquationsWavetable *equations)
{
  ModuleWavetable *wavetable = new ModuleWavetable(equations);
  ModuleSmooth *smooth = new ModuleSmooth();

  wavetable->equation_input  = inputs->mod;
  wavetable->frequency_input = inputs->sr;
  
  smooth->audio_input = wavetable;
  smooth->mix_input = inputs->param1;

  this->last_module = smooth;
}
