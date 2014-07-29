// =============================================================================
//
// Name: SynthWavetableBitFolder
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: A wavetable oscillator routed through a lowpass filter, 
// followed by a wave folder.
//
// SR  - Sample rate of the wavetable oscillator
// MOD - Wavetable selection
// [1] - Wave folding level
// [2] - Lowpass filter cutoff
// [3] - Lowpass filter resonance
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