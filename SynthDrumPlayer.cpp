#include "defines.h"
#include "SynthDrumPlayer.h"

SynthDrumPlayer::SynthDrumPlayer(Inputs* inputs)
{
  // Uses 3 different drum modules

  ModuleDrumSequencer *drum_sequencer = new ModuleDrumSequencer();
  ModuleSamplePlayer *kick = new ModuleSamplePlayer();
  ModuleSamplePlayer *snare = new ModuleSamplePlayer();
  ModuleSamplePlayer *hihat = new ModuleSamplePlayer();
  ModuleMixer3 *mixer = new ModuleMixer3();
  ModuleWaveFolder *wave_folder = new ModuleWaveFolder();

  drum_sequencer->clock_input = inputs->gate;

  drum_sequencer->kick_pattern_input = inputs->param1;
  drum_sequencer->snare_pattern_input = inputs->param2;
  drum_sequencer->hihat_pattern_input = inputs->param3;

  kick->trigger_input = drum_sequencer->kick_output;
  kick->sample_rate_input = inputs->sr;
  kick->sample_selection_input = new ModuleConstant(0);

  snare->trigger_input = drum_sequencer->snare_output;
  snare->sample_rate_input = inputs->sr;
  snare->sample_selection_input = new ModuleConstant(1);

  hihat->trigger_input = drum_sequencer->hihat_output;;
  hihat->sample_rate_input = inputs->sr;
  hihat->sample_selection_input = new ModuleConstant(2);

  mixer->input_1 = kick;
  mixer->input_2 = snare;
  mixer->input_3 = hihat;

  wave_folder->audio_input = mixer;
  wave_folder->lower_clipping_level_input = inputs->mod;
  wave_folder->upper_clipping_level_input = inputs->mod;

  this->last_module = wave_folder;
}
