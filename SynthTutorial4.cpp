#include "SynthTutorial4.h"

SynthTutorial4::SynthTutorial4(Inputs* inputs)
{
  ModuleWavetableOsc *osc = new ModuleWavetableOsc();
  ModuleVCA *vca = new ModuleVCA();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
  ModuleENV *envelope_generator = new ModuleENV();

  envelope_generator->slope_input = inputs->param2;
  envelope_generator->trigger_input = inputs->gate;
  envelope_generator->frequency_input = inputs->param1;

  // Patch up ocillator
  osc->frequency_input = inputs->sr;
  osc->wavetable_input = inputs->mod; 
  
  // Patch up lowpass filter
  lowpass_filter->audio_input = osc;
  lowpass_filter->cutoff_input = envelope_generator;
  lowpass_filter->resonance_input = inputs->param3;

  this->last_module = lowpass_filter;
}