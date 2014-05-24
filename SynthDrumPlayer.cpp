#include "defines.h"
#include "SynthDrumPlayer.h"

SynthDrumPlayer::SynthDrumPlayer(Inputs* inputs)
{
  // Uses 3 different drum modules

  ModuleDrumSequencer *drum_sequencer = new ModuleDrumSequencer();

  ModuleEqDrum *kick = new ModuleEqDrum();
  ModuleEqDrum *snare = new ModuleEqDrum();
  ModuleEqDrum *hihat = new ModuleEqDrum();
  ModuleMixer3 *mixer = new ModuleMixer3();

  drum_sequencer->clock_input = inputs->gate;

  drum_sequencer->kick_pattern_input = inputs->param1;
  drum_sequencer->snare_pattern_input = inputs->param2;
  drum_sequencer->hihat_pattern_input = inputs->param3;

  kick->trigger_input = drum_sequencer->kick_output;
  kick->sample_rate_input = inputs->sr;
  kick->drum_selection_input = new ModuleConstant(0);

  snare->trigger_input = drum_sequencer->snare_output;
  snare->sample_rate_input = inputs->sr;
  snare->drum_selection_input = new ModuleConstant(3);

  hihat->trigger_input = drum_sequencer->hihat_output;;
  hihat->sample_rate_input = inputs->sr;
  hihat->drum_selection_input = new ModuleConstant(7);

  mixer->input_1 = kick;
  mixer->input_2 = snare;
  mixer->input_3 = hihat;


  this->last_module = mixer;
}
