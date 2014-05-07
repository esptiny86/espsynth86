// =============================================================================
//
// Name: SynthTutorial2
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Sequencer driving a wavetable oscillator
//
// SR  - controls the sample rate of the oscillator
// MOD - not used
// [1] - not used
// [2] - not used
// [3] - not used
// GATE - not used
//
// =============================================================================

#ifndef SynthTutorial2_h
#define SynthTutorial2_h

#include "Synth.h"

class SynthTutorial2 : public Synth
{
  public:
    SynthTutorial2(Inputs *inputs, EquationsWavetable *equations_wavetable); 
};

#endif