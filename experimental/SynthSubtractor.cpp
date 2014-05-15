#include "Arduino.h"
#include "Defines.h"
#include "SynthSubtractor.h"

SynthSubtractor::SynthSubtractor(Module* inputs[])
{

  ModuleClock *master_clock = new ModuleClock(120, HALF_NOTE_CLOCK_DIVISION);

  int sequence[] = { 100, 4090, 50, 500, 3000, 400, 3500, 2500 };
  ModuleSequencer *sequencer = new ModuleSequencer(sequence);
  sequencer->clock_input = master_clock;
  
  // Patch up ocillator
  // osc.frequency_input = sequencer;      // Control the oscillator's requency using the SR knob
  osc.frequency_input = sequencer;
  osc.wavetable_input = new ModuleConstant(0); // Select the first wavetable
  
  // Patch up LFO
  // lfo.frequency_input = inputs[PARAM2_INPUT];  // Control the frequency using the [2] knob
  // lfo.wavetable_input = new ModuleConstant(0); // select the first wavetable
  
  // Patch up ADSR
  adsr.trigger_input = master_clock;  
  
  // Patch up lowpass filter
  lowpass_filter.audio_input = &osc;           // Route the audio from the oscillator into the filter
  lowpass_filter.cutoff_input = &adsr;         // Control the filter cutoff using the LFO
  lowpass_filter.resonance_input = new ModuleConstant(0);  // Set the resonance to 0
  
  // Patch up VCA
  // vca.cv_input = inputs[PARAM1_INPUT];
  vca.cv_input = &adsr;
  vca.audio_input = &lowpass_filter;           // Route the audio from the lowpass filter into the VCA

  this->last_module = &vca;
}