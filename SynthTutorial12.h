// =============================================================================
//
// Name: SynthTutorial12
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of wavetable phase input.
//
// SR  - controls the sample rate of both wavetable oscillators
// MOD - wavetable #2 phase input
// [1] - wavetable selection #1
// [2] - wavetable selection #2
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