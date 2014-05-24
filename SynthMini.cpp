#include "Arduino.h"
#include "defines.h"
#include "SynthMini.h"

SynthMini::SynthMini(Inputs* inputs)
{
  ModuleWavetableOsc *osc = new ModuleWavetableOsc();
  ModuleVCA *vca = new ModuleVCA();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();

  // Patch up ocillator
  osc->frequency_input = inputs->sr;
  osc->wavetable_input = inputs->mod; 
  
  // Patch up lowpass filter
  lowpass_filter->audio_input = osc;
  lowpass_filter->cutoff_input = inputs->param1;
  lowpass_filter->resonance_input = inputs->param2;
  
  // Patch up VCA
  vca->cv_input = inputs->param3;
  vca->audio_input = lowpass_filter;

  this->last_module = vca;
}