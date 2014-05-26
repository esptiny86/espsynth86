#include "SynthTutorial6.h"

SynthTutorial6::SynthTutorial6(Inputs* inputs)
{
  ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
  ModuleLFO *lfo = new ModuleLFO();

  // Patch up ocillator
  wavetable_osc->frequency_input = inputs->sr;
  wavetable_osc->wavetable_input = inputs->mod; 
  
  // Path up LFO
  lfo->wavetable_input = inputs->param1;
  lfo->frequency_input = inputs->param2;

  // Patch up filter
  lowpass_filter->audio_input = wavetable_osc;
  lowpass_filter->cutoff_input = lfo;

  this->last_module = lowpass_filter;
}