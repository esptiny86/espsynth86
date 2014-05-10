#include "Defines.h"
#include "SynthDrumPlayer.h"

SynthDrumPlayer::SynthDrumPlayer(Inputs* inputs)
{
  // Uses 3 different drum modules

  ModuleDrumSequencer *kick_drum_sequencer = new ModuleDrumSequencer(0);
  ModuleDrumSequencer *snare_drum_sequencer = new ModuleDrumSequencer(1);
  ModuleDrumSequencer *hihat_drum_sequencer = new ModuleDrumSequencer(2);
  ModuleEqDrum *kick = new ModuleEqDrum();
  ModuleEqDrum *snare = new ModuleEqDrum();
  ModuleEqDrum *hihat = new ModuleEqDrum();
  ModuleMixer3 *mixer = new ModuleMixer3();

  kick_drum_sequencer->clock_input = inputs->gate;
  snare_drum_sequencer->clock_input = inputs->gate;
  hihat_drum_sequencer->clock_input = inputs->gate;

  kick_drum_sequencer->pattern_input = inputs->param1;
  snare_drum_sequencer->pattern_input = inputs->param2;
  hihat_drum_sequencer->pattern_input = inputs->param3;

  kick->trigger_input = kick_drum_sequencer;
  kick->sample_rate_input = inputs->sr;
  kick->drum_selection_input = new ModuleConstant(1); // 0 = gritty kick, 1=tech kick

  snare->trigger_input = snare_drum_sequencer;
  snare->sample_rate_input = inputs->sr;
  snare->drum_selection_input = new ModuleConstant(3); // 3 = noise snare drum

  hihat->trigger_input = hihat_drum_sequencer;
  hihat->sample_rate_input = inputs->sr;
  hihat->drum_selection_input = new ModuleConstant(7); // 7 = tuned hat

  mixer->input_1 = kick;
  mixer->input_2 = snare;
  mixer->input_3 = hihat;


  this->last_module = hihat;
}
