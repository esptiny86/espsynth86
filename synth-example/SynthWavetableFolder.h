// =============================================================================
//
// Name: SynthWavetableFolder
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

#ifndef SynthWavetableFolder_h
#define SynthWavetableFolder_h

#include "Synth.h"

class SynthWavetableFolder : public Synth
{
  public:
    SynthWavetableFolder(Inputs *inputs); 
};

#endif