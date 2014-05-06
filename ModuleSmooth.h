/*
 *  +----------------------+
 *  | ModuleSmooth         |
 *  |----------------------|
 *  > audio_input          |
 *  > mix_input            |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleSmooth is used for smoothing out input.  Does it work?  Mayyybbeee.. 
// It actually seems to add some overtones to audio input.  So, perhaps there's
// a bug in my implementation, but I'm keeping it around because it's interesting.
//
// It's based on this: http://terpconnect.umd.edu/~toh/spectrum/Smoothing.html
//
// Here's an example which uses a counter to cycle through the first 6 
// equations of the wavetable module:
//
// mix_input: 0 == dry, 4095 == wet
//
// Example usage:
//
//   ModuleWavetable *wavetable = new ModuleWavetable(equations);
//   ModuleSmooth *smooth = new ModuleSmooth();
//
//   wavetable->equation_input  = inputs->mod;
//   wavetable->frequency_input = inputs->sr;
//  
//   smooth->audio_input = wavetable;
//   smooth->mix_input = inputs->param1;
//
//   this->last_module = smooth;
//

#ifndef ModuleSmooth_h
#define ModuleSmooth_h

#include "Arduino.h"
#include "Module.h"

class ModuleSmooth : public Module
{
  
  public:
    ModuleSmooth();
    uint32_t compute();
    
    // Inputs
    Module *audio_input;
    Module *mix_input;   
    
  private:
    
    uint32_t buffer[6];
    int mix;  // ranged from 0 to 4095, where 0 == dry, 4095 == wet
    uint32_t smooth_output;
};

#endif
