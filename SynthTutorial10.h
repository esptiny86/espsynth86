// =============================================================================
//
// Name: SynthTutorial10
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of the clocked random module.  Uses two clocked
// random number generators to control the note and wavetable selection of 
// a wavetable oscillator.
//
// SR  - not used
// MOD - not used
// [1] - scale selection
// [2] - not used
// [3] - not used
// GATE - (optional) clocks the pattern generator
//
// =============================================================================

#ifndef SynthTutorial10_h
#define SynthTutorial10_h

#include "Synth.h"

class SynthTutorial10 : public Synth
{
  public:
    SynthTutorial10(Inputs *inputs); 
};

#endif