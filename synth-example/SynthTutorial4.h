// =============================================================================
//
// Name: SynthTutorial4
// Type: CV Output
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of ModuleENV.  A wavetable oscillator is passed
// through a lowpass filter.  The filter's cutoff is controlled by the output
// of an envelope generator (ModuleENV).  The shape of the envelope is selectable.
// The envelope generator is triggered by the GATE input.
//
// SR  - Wavetable Oscillator sample rate (aka pitch)
// MOD - Wavetable selection
// [1] - Slope selection input (see GlobalSlopes.cpp)
// [2] - Filter cutoff
// [3] - Filter resonance
// GATE - Triggers the ModuleENV
//
// =============================================================================

#ifndef SynthTutorial4_h
#define SynthTutorial4_h

#include "Synth.h"

class SynthTutorial4 : public Synth
{
  public:
    SynthTutorial4(Inputs *inputs); 
};

#endif