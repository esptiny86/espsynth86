// =============================================================================
//
// Name: SynthTutorial1
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Simple triangle wave oscillator.  The implementation of this
// synth can be seen in SynthTutorial1.cpp.
//
// SR  - controls the sample rate of the oscillator
// MOD - not used
// [1] - not used
// [2] - not used
// [3] - not used
// GATE - not used
//
// =============================================================================

#ifndef SynthTutorial1_h
#define SynthTutorial1_h

#include "Synth.h"

class SynthTutorial1 : public Synth
{
  public:
    SynthTutorial1(Inputs *inputs); 
};

#endif