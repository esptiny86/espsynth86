// =============================================================================
//
// Name: SynthTutorial3
// Type: CV Output
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of the lowpass filter.  This synth is a simple
// wavetable oscillator with controllable pitch, wavetable, filter cutoff,
// and filter resonance.
//
// SR  - Wavetable Oscillator sample rate (aka pitch)
// MOD - Wavetable selection
// [1] - Filter cutoff
// [2] - Filter resonance
// [3] - not used
// GATE - not used
//
// =============================================================================

#ifndef SynthTutorial3_h
#define SynthTutorial3_h

#include "Synth.h"

class SynthTutorial3 : public Synth
{
  public:
    SynthTutorial3(Inputs *inputs); 
};

#endif