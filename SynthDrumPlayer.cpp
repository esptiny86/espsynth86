#include "Defines.h"
#include "SynthDrumPlayer.h"

SynthDrumPlayer::SynthDrumPlayer(Inputs* inputs)
{
  // Uses 3 different drum modules

  ModuleEqDrum *kick = new ModuleEqDrum();
  kick->trigger_input = inputs->param1;
  kick->sample_rate_input = inputs->sr;
  kick->drum_selection_input = new ModuleConstant(1); // 0 = gritty kick, 1=tech kick

  ModuleEqDrum *snare = new ModuleEqDrum();
  snare->trigger_input = inputs->param2;
  snare->sample_rate_input = inputs->sr;
  snare->drum_selection_input = new ModuleConstant(3); // 3 = noise snare drum
  
  ModuleEqDrum *hihat = new ModuleEqDrum();
  hihat->trigger_input = inputs->param3;
  hihat->sample_rate_input = inputs->sr;
  hihat->drum_selection_input = new ModuleConstant(6); // 6 = hihat
  
  ModuleMixer3 *mixer = new ModuleMixer3();
  mixer->input_1 = kick;
  mixer->input_2 = snare;
  mixer->input_3 = hihat;
  
  this->last_module = mixer;
}
