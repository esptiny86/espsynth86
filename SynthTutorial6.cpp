#include "SynthTutorial6.h"

SynthTutorial6::SynthTutorial6(Inputs* inputs)
{
  // Create the modules
  ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
  ModuleLFO *lfo = new ModuleLFO();

  // Patch up oscillator
  wavetable_osc->frequency_input = inputs->sr;
  wavetable_osc->wavetable_input = inputs->mod; 
  
  // Path up LFO
  lfo->wavetable_input = inputs->param1;
  lfo->frequency_input = inputs->param2;

  // Wire the oscillator into the lowpass filter
  // Use the LFO to modulate the LPF's cutoff
  lowpass_filter->audio_input = wavetable_osc;
  lowpass_filter->cutoff_input = lfo;
  lowpass_filter->resonance_input = inputs->param3;

  // Output the audio of the lowpass filter
  this->last_module = lowpass_filter;
}