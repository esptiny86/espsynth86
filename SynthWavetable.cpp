#include "SynthWavetable.h"

SynthWavetable::SynthWavetable(Inputs *inputs, EquationsWavetable *equations)
{
  ModuleWavetable *wavetable = new ModuleWavetable(equations);

  wavetable->equation_input  = inputs->mod;
  wavetable->frequency_input = inputs->sr;
  
  this->last_module = wavetable;
}
