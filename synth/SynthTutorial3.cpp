#include "SynthTutorial3.h"

SynthTutorial3::SynthTutorial3(Inputs* inputs)
{
  ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();

  // Patch up ocillator
  wavetable_osc->frequency_input = inputs->sr;
  wavetable_osc->wavetable_input = inputs->mod;

  // Patch up filter
  lowpass_filter->audio_input = wavetable_osc;
  lowpass_filter->cutoff_input = inputs->param1;
  lowpass_filter->resonance_input = inputs->param2;

  this->last_module = lowpass_filter;
}