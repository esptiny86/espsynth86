#include "Arduino.h"
#include "Defines.h"
#include "SynthMumbler.h"

SynthMumbler::SynthMumbler(Inputs* inputs)
{
  ModuleSpeechSound *speech_sound = new ModuleSpeechSound();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
  ModuleRotatingRouter3 *rotating_router_3 = new ModuleRotatingRouter3();
  
  speech_sound->formant_scale_input = inputs->mod;
  
  rotating_router_3->rotate_input = inputs->gate;
  rotating_router_3->input_1 = inputs->param1;
  rotating_router_3->input_2 = new ModuleConstant(1000);
  rotating_router_3->input_3 = new ModuleConstant(15);

  speech_sound->phase1_input = rotating_router_3->output_1;
  speech_sound->phase2_input = rotating_router_3->output_2;
  speech_sound->phase3_input = rotating_router_3->output_3;
  
  speech_sound->pitch_input = inputs->sr;
  
  // Patch up lowpass filter
  lowpass_filter->audio_input = speech_sound;
  lowpass_filter->cutoff_input = inputs->param3;
  lowpass_filter->resonance_input = inputs->param2;
  
  this->last_module = lowpass_filter;
}
