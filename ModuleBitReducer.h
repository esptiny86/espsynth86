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
//

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
