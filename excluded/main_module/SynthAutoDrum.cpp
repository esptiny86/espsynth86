#include "defines.h"
#include "SynthAutoDrum.h"

SynthAutoDrum::SynthAutoDrum(Inputs* inputs)
{
  ModuleClock *clock = new ModuleClock(90, QUARTER_NOTE_CLOCK_DIVISION);
  ModuleDrumSequencer *drum_sequencer = new ModuleDrumSequencer();

  drum_sequencer->clock_input = clock;
  drum_sequencer->kick_pattern_input = inputs->param1->smooth;
  drum_sequencer->snare_pattern_input = inputs->param2->smooth;
  drum_sequencer->hihat_pattern_input = inputs->param3->smooth;

  ModuleEqDrum *kick = new ModuleEqDrum();
  kick->trigger_input = drum_sequencer->kick_output;
  kick->sample_rate_input = inputs->sr;
  kick->drum_selection_input = new ModuleConstant(0);

  ModuleEqDrum *snare = new ModuleEqDrum();
  snare->trigger_input = drum_sequencer->snare_output;
  snare->sample_rate_input = inputs->sr;
  snare->drum_selection_input = new ModuleConstant(3);
  
  ModuleEqDrum *hihat = new ModuleEqDrum();
  hihat->trigger_input = drum_sequencer->hihat_output;
  hihat->sample_rate_input = inputs->sr;
  hihat->drum_selection_input = new ModuleConstant(6);
  
  ModuleMixer3 *mixer = new ModuleMixer3();
  mixer->input_1 = kick;
  mixer->input_2 = snare;
  mixer->input_3 = hihat;

  this->last_module = mixer;
}
