// =============================================================================
//
// Name: SynthTutorial12
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of the counter module
//
// SR  - controls the sample rate of the wavetable oscillator
// MOD - not used
// [1] - not used
// [2] - not used
// [3] - not used
// GATE - not used
//
// =============================================================================

#ifndef SynthTutorial12_h
#define SynthTutorial12_h

#include "Synth.h"

class SynthTutorial12 : public Synth
{
  public:
    SynthTutorial12(Inputs *inputs); 
};

#endif