// =============================================================================
//
// Name: SynthArppegiator
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Plays arppegiating notes based on an internal clock which is
// modulated by an LFO.  The wavetable used for playback is also modulated 
// at the rate of the clock output.
//
// SR  - selects the root note
// MOD - 
// [1] - selects the arpeggiation pattern
// [2] - controls the speed of the LFO
// [3] - 
// GATE - 
//
// =============================================================================

#ifndef SynthArp1_h
#define SynthArp1_h

#include "Synth.h"

class SynthArp1 : public Synth
{
  public:
    SynthArp1(Inputs *inputs); 
};

#endif
