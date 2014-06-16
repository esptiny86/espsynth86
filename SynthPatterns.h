// =============================================================================
//
// Name: SynthPatterns
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: 
//
// SR  - sample rate
// MOD - wavetable selecation
// [1] - CV Pattern Select
// [2] - Gate Pattern Select
// [3] - Gate Density
// GATE - (optional) clock control
//
// =============================================================================

#ifndef SynthPatterns_h
#define SynthPatterns_h

#include "Synth.h"

class SynthPatterns : public Synth
{
  public:
    SynthPatterns(Inputs *inputs); 
};

#endif
