// =============================================================================
//
// Name: SynthTutorial6
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Simple LFO example.  A wavetable oscillator is being filtered
// by a lowpass filter.  The filter's cutoff is being modulated by the LFO.
//
//
// SR  - Wavetable Oscillator sample rate (pitch)
// MOD - Wavetable selection
// [1] - LFO wavetable selection
// [2] - LFO frequency
// [3] - Lowpass filter resonance input
// GATE - not used
//
// =============================================================================

#ifndef SynthTutorial6_h
#define SynthTutorial6_h

#include "Synth.h"

class SynthTutorial6 : public Synth
{
  public:
    SynthTutorial6(Inputs *inputs); 
};

#endif