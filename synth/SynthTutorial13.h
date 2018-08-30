// =============================================================================
//
// Name: SynthTutorial13
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of ModuleBitReducer.  A wavetable oscillator's
// output is bit-reduced.
//
// The bit reducer module hasn't turned out to be very useful.  I may eventually 
// rewrite it to get better "low-fi" effects.
//
// SR  - Sample rate of the wavetable oscillator
// MOD - Wavetable selection
// [1] - Bit rate of the bit reducer
// [2] - not used
// [3] - not used
// GATE - not used
//
// =============================================================================

#ifndef SynthTutorial13_h
#define SynthTutorial13_h

#include "Synth.h"

class SynthTutorial13 : public Synth
{
  public:
    SynthTutorial13(Inputs *inputs); 
};

#endif