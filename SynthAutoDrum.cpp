#include "Defines.h"
#include "SynthAutoDrum.h"

SynthAutoDrum::SynthAutoDrum(Module* inputs[])
{
  // Create master clock
  
  // This isn't working.  Fast LFOs cause the module to become unresponsive.  I need to troubleshoot why.
  
  /*
  ModuleLFO *lfo = new ModuleLFO();
  lfo->frequency_input = inputs[MOD_INPUT];
  lfo->wavetable_input = new ModuleConstant(0);
  
  ModuleDrumSequencer *kick_drum_sequencer = new ModuleDrumSequencer(0);  // bank 0 == kick drum patterns
  kick_drum_sequencer->clock_input = lfo;
  kick_drum_sequencer->pattern_input = inputs[PARAM1_INPUT];

  ModuleDrumSequencer *snare_drum_sequencer = new ModuleDrumSequencer(1); // bank 1 == snare drum patterns
  snare_drum_sequencer->clock_input = lfo;
  snare_drum_sequencer->pattern_input = inputs[PARAM2_INPUT];

  ModuleDrumSequencer *hihat_drum_sequencer = new ModuleDrumSequencer(2); // bank 2 == hihat drum patterns
  hihat_drum_sequencer->clock_input = lfo;
  hihat_drum_sequencer->pattern_input = inputs[PARAM3_INPUT];

  ModuleEqDrum *kick = new ModuleEqDrum();
  kick->trigger_input = kick_drum_sequencer;
  kick->sample_rate_input = inputs[SR_INPUT];
  kick->drum_selection_input = new ModuleConstant(1);

  ModuleEqDrum *snare = new ModuleEqDrum();
  snare->trigger_input = snare_drum_sequencer;
  snare->sample_rate_input = inputs[SR_INPUT];
  snare->drum_selection_input = new ModuleConstant(3);
  
  ModuleEqDrum *hihat = new ModuleEqDrum();
  hihat->trigger_input = hihat_drum_sequencer;
  hihat->sample_rate_input = inputs[SR_INPUT];
  hihat->drum_selection_input = new ModuleConstant(6);
  
  ModuleMixer3 *mixer = new ModuleMixer3();
  mixer->input_1 = kick;
  mixer->input_2 = snare;
  mixer->input_3 = hihat;
  
  this->last_module = mixer;  
*/
  

  ModuleClock *clock = new ModuleClock(90, QUARTER_NOTE_CLOCK_DIVISION);
  
  ModuleDrumSequencer *kick_drum_sequencer = new ModuleDrumSequencer(0);  // bank 0 == kick drum patterns
  kick_drum_sequencer->clock_input = clock;
  kick_drum_sequencer->pattern_input = inputs[PARAM1_INPUT];

  ModuleDrumSequencer *snare_drum_sequencer = new ModuleDrumSequencer(1); // bank 1 == snare drum patterns
  snare_drum_sequencer->clock_input = clock;
  snare_drum_sequencer->pattern_input = inputs[PARAM2_INPUT];

  ModuleDrumSequencer *hihat_drum_sequencer = new ModuleDrumSequencer(2); // bank 2 == hihat drum patterns
  hihat_drum_sequencer->clock_input = clock;
  hihat_drum_sequencer->pattern_input = inputs[PARAM3_INPUT];

  ModuleEqDrum *kick = new ModuleEqDrum();
  kick->trigger_input = kick_drum_sequencer;
  kick->sample_rate_input = inputs[SR_INPUT];
  kick->drum_selection_input = new ModuleConstant(0);

  ModuleEqDrum *snare = new ModuleEqDrum();
  snare->trigger_input = snare_drum_sequencer;
  snare->sample_rate_input = inputs[SR_INPUT];
  snare->drum_selection_input = new ModuleConstant(3);
  
  ModuleEqDrum *hihat = new ModuleEqDrum();
  hihat->trigger_input = hihat_drum_sequencer;
  hihat->sample_rate_input = inputs[SR_INPUT];
  hihat->drum_selection_input = new ModuleConstant(6);
  
  ModuleMixer3 *mixer = new ModuleMixer3();
  mixer->input_1 = kick;
  mixer->input_2 = snare;
  mixer->input_3 = hihat;
  
  this->last_module = mixer;

}
