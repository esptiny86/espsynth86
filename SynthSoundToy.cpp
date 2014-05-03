#include "SynthSoundToy.h"

SynthSoundToy::SynthSoundToy(Inputs* inputs)
{
  ModuleSoundToy *sound_toy = new ModuleSoundToy();
  
  sound_toy->sound_input     = inputs->mod;
  sound_toy->frequency_input = inputs->sr;
  sound_toy->trigger_input   = inputs->gate;
  
  this->last_module = sound_toy;
}
