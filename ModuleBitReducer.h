/*
 *  +----------------------+
 *  | ModuleBitReducer     |
 *  |----------------------|
 *  > audio_input          |
 *  > bit_input            |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleBitReducer is an audio effect for reducing the number of bits used
// to represent the audio information, which results in a low-fi, crunchy,
// digital distortion.
//
// Example usage:
//
//   ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
//   ModuleBitReducer *bit_reducer = new ModuleBitReducer();
//
//   wavetable_osc->wavetable_input  = inputs->mod;
//   wavetable_osc->frequency_input  = inputs->sr;
//  
//   bit_reducer->audio_input = wavetable_osc;
//   bit_reducer->bit_input = inputs->param1;
//
//   this->last_module = bit_reducer;

#ifndef ModuleBitReducer_h
#define ModuleBitReducer_h

#include "Arduino.h"
#include "Module.h"

class ModuleBitReducer : public Module
{
  
  public:
    ModuleBitReducer();
    uint32_t compute();
    
    // Inputs
    Module *audio_input;
    Module *bit_input;
};

#endif
