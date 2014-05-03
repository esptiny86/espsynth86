#include "SynthArp1.h"

SynthArp1::SynthArp1(Inputs* inputs)
{
  ModuleLFO *lfo = new ModuleLFO();
  lfo->frequency_input = inputs->param2;
  // lfo->wavetable_input = new ModuleConstant(0);
  
  ModuleClock *clock = new ModuleClock(120);
  
  ModuleVCClockDivider *vc_clock_divider = new ModuleVCClockDivider();
  vc_clock_divider->clock_input = clock;
  vc_clock_divider->clock_division_input = lfo;
  
  // Create a counter that counts from 0 to 1, then repeats.
  ModuleCounter *counter = new ModuleCounter(1); 
  counter->clock_input = vc_clock_divider;
  
  ModuleArpeggio *arp = new ModuleArpeggio();
  arp->clock_input = vc_clock_divider;
  arp->root_note_input = inputs->sr;
  arp->pattern_input = inputs->param1;
  
  // Patch up ocillator
  ModuleOsc *osc1 = new ModuleOsc();
  osc1->frequency_input = arp;
  osc1->wavetable_input = counter;

  this->last_module = osc1;
}
