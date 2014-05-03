#include "Defines.h"
#include "SynthDrumPlayer.h"

SynthDrumPlayer::SynthDrumPlayer(Module* inputs[])
{
  // Uses 3 different drum modules

  ModuleEqDrum *kick = new ModuleEqDrum();
  kick->trigger_input = inputs[PARAM1_INPUT];
  kick->sample_rate_input = inputs[SR_INPUT];
  kick->drum_selection_input = new ModuleConstant(1); // 0 = gritty kick, 1=tech kick

  ModuleEqDrum *snare = new ModuleEqDrum();
  snare->trigger_input = inputs[PARAM2_INPUT];
  snare->sample_rate_input = inputs[SR_INPUT];
  snare->drum_selection_input = new ModuleConstant(3); // 3 = noise snare drum
  
  ModuleEqDrum *hihat = new ModuleEqDrum();
  hihat->trigger_input = inputs[PARAM3_INPUT];
  hihat->sample_rate_input = inputs[SR_INPUT];
  hihat->drum_selection_input = new ModuleConstant(6); // 6 = hihat
  
  ModuleMixer3 *mixer = new ModuleMixer3();
  mixer->input_1 = kick;
  mixer->input_2 = snare;
  mixer->input_3 = hihat;
  
  this->last_module = mixer;
}
