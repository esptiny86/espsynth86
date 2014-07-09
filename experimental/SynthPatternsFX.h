// =============================================================================
//
// Name: SynthPatternsFX
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: 
//
// SR  - delay effects mix
// MOD - wavetable selecation
// [1] - CV Pattern Select
// [2] - Gate Pattern Select
// [3] - Gate Density
// GATE - (optional) clock control
//
// =============================================================================

#ifndef SynthPatternsFX_h
#define SynthPatternsFX_h

#include "Synth.h"

class SynthPatternsFX : public Synth
{
  public:
    SynthPatternsFX(Inputs *inputs); 
};

#endif
