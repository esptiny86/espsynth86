#include "SynthTutorial4.h"

SynthTutorial4::SynthTutorial4(Inputs* inputs)
{
  ModuleWavetableOsc *osc = new ModuleWavetableOsc();
  ModuleVCA *vca = new ModuleVCA();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
  ModuleADSR *adsr = new ModuleADSR();

  adsr->slope_input = inputs->param2;
  adsr->trigger_input = inputs->gate;
  adsr->frequency_input = inputs->param1;

  // Patch up ocillator
  osc->frequency_input = inputs->sr;
  osc->wavetable_input = inputs->mod; 
  
  // Patch up lowpass filter
  lowpass_filter->audio_input = osc;
  lowpass_filter->cutoff_input = adsr;
  lowpass_filter->resonance_input = inputs->param3;
  


  this->last_module = lowpass_filter;
}