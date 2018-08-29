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
// ModuleSmooth is used for smoothing audio.  Does it work?  Mayyybbeee.. 
// It actually seems to add some overtones to audio input.  So, perhaps there's
// a bug in my implementation, but I'm keeping it around because it's interesting.
//
// I think that the original implementation of this algorithm was for reducing
// noise in a signal.  If you're trying to reduce noise on CV inputs, don't 
// use this module.  Instead, add '->smooth' when reading an analog input. 
// For example:
//
// lfo->frequency_input = inputs->param1->smooth;
//
// Smoothing algorithm based on: http://terpconnect.umd.edu/~toh/spectrum/Smoothing.html
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
    uint16_t compute();
    
    // Inputs
    Module *audio_input;
    Module *mix_input;   
    
  private:
    
    uint16_t buffer[6];
    uint16_t mix;  // ranged from 0 to 4095, where 0 == dry, 4095 == wet
    uint16_t smooth_output;
};

#endif
