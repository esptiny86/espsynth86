// =============================================================================
//
// Name: SynthWavetableBitFolder
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: A wavetable oscillator put through a short audio delay.
//
// SR  - Sample rate of the wavetable oscillator
// MOD - Wavetable selection
// [1] - Bit reduction
// [2] - Wave folding level
// [3] - Lowpass filter cutoff
// GATE - not used
//
// =============================================================================

#ifndef SynthWavetableBitFolder_h
#define SynthWavetableBitFolder_h

#include "Synth.h"

class SynthWavetableBitFolder : public Synth
{
  public:
    SynthWavetableBitFolder(Inputs *inputs); 
};

#endif