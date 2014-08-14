#include "SynthTutorial12.h"

SynthTutorial12::SynthTutorial12(Inputs* inputs)
{
  // Create modules
  ModuleCounter *counter = new ModuleCounter(5);  // count from 0 to 5
  ModuleClock *bpm_clock = new ModuleClock(120, EIGHTH_NOTE_CLOCK_DIVISION);  // clock at 120BPM
  ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();

  // Use the clock to increment the counter
  counter->clock_input = bpm_clock;

  // Wire the counter to the wavetable selection
  wavetable_osc->wavetable_input = counter;
  wavetable_osc->frequency_input  = inputs->sr;

  // Output the wavetable oscillator
  this->last_module = wavetable_osc;
}