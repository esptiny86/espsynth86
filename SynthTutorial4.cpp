#include "SynthTutorial4.h"

SynthTutorial4::SynthTutorial4(Inputs* inputs)
{
  ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
  ModuleVCA *vca = new ModuleVCA();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
  ModuleENV *envelope_generator = new ModuleENV();

  envelope_generator->slope_input = inputs->param2;
  envelope_generator->trigger_input = inputs->gate;
  envelope_generator->frequency_input = inputs->param1;

  // Patch up ocillator
  wavetable_osc->frequency_input = inputs->sr;
  wavetable_osc->wavetable_input = inputs->mod; 
  
  // Patch up filter
  lowpass_filter->audio_input = wavetable_osc;
  lowpass_filter->cutoff_input = envelope_generator;
  lowpass_filter->resonance_input = inputs->param3;

  this->last_module = lowpass_filter;
}