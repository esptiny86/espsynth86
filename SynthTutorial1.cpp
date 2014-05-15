#include "SynthTutorial1.h"

SynthTutorial1::SynthTutorial1(Inputs* inputs)
{
  ModuleWavetableOsc *osc = new ModuleWavetableOsc();
  osc->wavetable_input  = new ModuleConstant(1);
  osc->frequency_input  = inputs->sr;
  
  this->last_module = osc;
}