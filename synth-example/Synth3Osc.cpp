#include "Arduino.h"
#include "Defines.h"
#include "Synth3Osc.h"

Synth3Osc::Synth3Osc(Inputs* inputs)
{
  ModuleOscParam *osc_param = new ModuleOscParam();
  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
  ModuleWavetableOsc *osc1 = new ModuleWavetableOsc();
  ModuleWavetableOsc *osc2 = new ModuleWavetableOsc();
  ModuleWavetableOsc *osc3 = new ModuleWavetableOsc();
  ModuleVCA *vca1 = new ModuleVCA();  
  ModuleVCA *vca2 = new ModuleVCA(); 
  ModuleVCA *vca3 = new ModuleVCA(); 
  ModuleMixer3 *mixer = new ModuleMixer3(); 
  
  osc_param->waveform_input = inputs->mod;
  osc_param->pitch_input = inputs->sr;
  osc_param->fine_input = inputs->param1;
  
  osc1->wavetable_input = osc_param->osc1_waveform;
  osc2->wavetable_input = osc_param->osc2_waveform;
  osc3->wavetable_input = osc_param->osc3_waveform;
  
  osc1->frequency_input = osc_param->osc1_pitch;
  osc2->frequency_input = osc_param->osc2_pitch;
  osc3->frequency_input = osc_param->osc3_pitch;
  
  vca1->audio_input = osc1;
  vca2->audio_input = osc2;
  vca3->audio_input = osc3;
  vca1->cv_input = osc_param->vca1_volume;
  vca2->cv_input = osc_param->vca2_volume;
  vca3->cv_input = osc_param->vca3_volume;
  
  mixer->input_1 = vca1;
  mixer->input_2 = vca2;
  mixer->input_3 = vca3;
        
  // Patch up lowpass filter
  lowpass_filter->audio_input = mixer;
  lowpass_filter->cutoff_input = inputs->param2;
  lowpass_filter->resonance_input = inputs->param3;
  
  this->last_module = lowpass_filter;
}
