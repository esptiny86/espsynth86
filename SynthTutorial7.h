// =============================================================================
//
// Name: SynthTutorial7
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Demonstrates the usage of the map module, which is used to
// reduce the range of an LFO so that it can modulate a clock divider's
// clock division input.  The final clock division output is used to trigger
// a drum sound.
//
// The basic idea is:
// clock ---> map(0-24) ---> clock divider ---> drum sound ---> output
// 
// SR  - Drum sound frequency
// MOD - Drum sound selection (from ModuleEqDrum)
// [1] - LFO frequency
// [2] - LFO wavetable
// [3] - not used
// GATE - (optional) Clock input to the clock divider
//
// =============================================================================

#ifndef SynthTutorial7_h
#define SynthTutorial7_h

#include "Synth.h"

class SynthTutorial7 : public Synth
{
  public:
    SynthTutorial7(Inputs *inputs); 
};

#endif