// =============================================================================
//
// Name: SynthTutorial14
// Type: CV Output
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of the ModuleRotatingRouter3
//
// SR  - Sample rate input
// MOD - not used
// [1] - Wavetable #1 selection
// [2] - Wavetable #2 selection
// [3] - Wavetable #3 selection
// GATE - Rotates the router to cycle through the wavetable selections
//
// =============================================================================

#ifndef SynthTutorial14_h
#define SynthTutorial14_h

#include "Synth.h"

class SynthTutorial14 : public Synth
{
  public:
    SynthTutorial14(Inputs *inputs); 
};

#endif