#include "SynthArp1.h"

SynthArp1::SynthArp1(Inputs* inputs, EquationsWavetable *equations)
{
  ModuleArpeggio *arp = new ModuleArpeggio();
  ModuleWavetable *wavetable_osc = new ModuleWavetable(equations);

  arp->clock_input      = inputs->gate;
  arp->root_note_input  = inputs->sr;
  arp->pattern_input    = inputs->param1;
  
  wavetable_osc->frequency_input = arp;
  wavetable_osc->equation_input = inputs->param2;

  this->last_module = wavetable_osc;
}
