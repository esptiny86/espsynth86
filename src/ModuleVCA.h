/*
 *  +----------------------+
 *  | ModuleVCA            |
 *  |----------------------|
 *  > audio_input          |
 *  > cv_input             |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// ModuleVCA is an audio amplifier.  The volume of the output is controlled via 
// the cv_input.  See http://synthesizeracademy.com/voltage-controlled-amplifier-vca/
//
// Example usage:
//
//  ModuleWavetableOsc *osc = new ModuleWavetableOsc();
//  ModuleVCA *vca = new ModuleVCA();
//  ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
//
//  // Patch up ocillator
//  osc->frequency_input = inputs->sr;
//  osc->wavetable_input = inputs->mod; 
//  
//  // Patch up lowpass filter
//  lowpass_filter->audio_input = osc;
//  lowpass_filter->cutoff_input = inputs->param1;
//  lowpass_filter->resonance_input = inputs->param2;
//  
//  // Patch up VCA
//  vca->cv_input = inputs->param3;
//  vca->audio_input = lowpass_filter;
//
//  this->last_module = vca;

#ifndef ModuleVCA_h
#define ModuleVCA_h

#include "Module.h"

class ModuleVCA : public Module
{
  public:
  	ModuleVCA();
    uint16_t compute();

    // Inputs
    Module *audio_input;  
    Module *cv_input;  
};

#endif
