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
// SR  - 
// MOD - 
// [1] - 
// [2] - 
// [3] - 
// GATE - 
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