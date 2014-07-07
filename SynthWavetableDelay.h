// =============================================================================
//
// Name: SynthWavetableDelay
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: A wavetable oscillator put through a short audio delay.
//
// SR  - Sample rate of the wavetable oscillator
// MOD - Wavetable selection
// [1] - Mix (dry/wet) of the delay effect
// [2] - Delay feedback
// [3] - Delay buffer length
// GATE - not used
//
// =============================================================================

#ifndef SynthWavetableDelay_h
#define SynthWavetableDelay_h

#include "Synth.h"

class SynthWavetableDelay : public Synth
{
  public:
    SynthWavetableDelay(Inputs *inputs); 
};

#endif