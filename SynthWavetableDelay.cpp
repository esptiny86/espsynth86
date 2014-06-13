#include "SynthWavetableDelay.h"

SynthWavetableDelay::SynthWavetableDelay(Inputs* inputs)
{
  
  ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
  ModuleDelay *delay = new ModuleDelay();

  wavetable_osc->wavetable_input  = inputs->mod;
  wavetable_osc->frequency_input  = inputs->sr;
  
  delay->audio_input = wavetable_osc;
  delay->mix_input = inputs->param1;
  delay->feedback_input = inputs->param2;
  delay->length_input = inputs->param3;

  this->last_module = delay;

}