#include "Defines.h"
#include "SynthLooper.h"

SynthLooper::SynthLooper(Inputs* inputs)
{
  ModuleLooper *looper = new ModuleLooper();
  ModuleFreeze *freeze = new ModuleFreeze();
  ModuleWaveFolder *wave_folder = new ModuleWaveFolder();

  // Wire up looper inputs
  looper->sample_input = inputs->mod;
  looper->sample_rate_input = inputs->sr;
  looper->slice_input = inputs->param3;
  looper->trigger_input = inputs->gate;

  // Send the looper through a freeze effect
  freeze->audio_input = looper;
  freeze->length_input = inputs->param1;

  // Wire the output of the freeze effect into a wave folder
  wave_folder->audio_input = freeze;
  wave_folder->lower_clipping_level_input = inputs->param2;
  wave_folder->upper_clipping_level_input = inputs->param2;

  this->last_module = wave_folder;
}