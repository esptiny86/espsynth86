// =============================================================================
//
// Name: SynthTutorial9
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of the pattern generator module
//
// SR  - not used
// MOD - wavetable sound selection
// [1] - scale selection
// [2] - pattern selection
// [3] - not used
// GATE - (optional) clocks the pattern generator
//
// =============================================================================

#ifndef SynthTutorial9_h
#define SynthTutorial9_h

#include "Synth.h"

class SynthTutorial9 : public Synth
{
  public:
    SynthTutorial9(Inputs *inputs); 
};

#endif