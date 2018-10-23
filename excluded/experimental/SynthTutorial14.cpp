#include "SynthTutorial14.h"

SynthTutorial14::SynthTutorial14(Inputs* inputs)
{
  // Create the modules/macros
  ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
  MacroGatedLPF *macro_gated_lpf = new MacroGatedLPF();

  // Patch up ocillator
  wavetable_osc->frequency_input = inputs->sr;
  wavetable_osc->wavetable_input = inputs->mod; 
  
  // Patch up macro for a gated Lowpass Filter
  macro_gated_lpf->envelope_generator->trigger_input = inputs->gate;
  macro_gated_lpf->lowpass_filter->audio_input = wavetable_osc;

  this->last_module = macro_gated_lpf;
}