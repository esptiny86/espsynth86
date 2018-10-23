/*
 *  +----------------------+
 *  | ModuleLowpassFilter  |
 *  |----------------------|
 *  > audio_input          |
 *  > cutoff_input         |
 *  > resonance_input      |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// ModuleLowpassFilter is a 24db resonant lowpass (Moog style) with control over 
// cutoff and resonance.
//
// Example usage:
//
//   ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
//   ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
//
//   // Patch up ocillator
//   wavetable_osc->frequency_input = inputs->sr;
//   wavetable_osc->wavetable_input = inputs->mod;
//
//   // Patch up filter
//   lowpass_filter->audio_input = wavetable_osc;
//   lowpass_filter->cutoff_input = inputs->param1;
//   lowpass_filter->resonance_input = inputs->param2;
//
//   this->last_module = lowpass_filter;
//


#ifndef ModuleLowpassFilter_h
#define ModuleLowpassFilter_h

#include "Arduino.h"
#include "Module.h"

class ModuleLowpassFilter : public Module
{
  
  public:
    
    // Methods
    ModuleLowpassFilter();
    uint16_t compute();
    
    // Inputs
    Module *audio_input; 
    Module *cutoff_input;
    Module *resonance_input;
  
    long y1,y2,y3,y4,oldx,oldy1,oldy2,oldy3;                     
};

#endif
