// =============================================================================
//
// Name: SynthTutorial15
// Type: CV Output
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of ModuleWaveFolder
//
// SR  - Sample rate input
// MOD - Wavetable selection
// [1] - Folding Upper Level
// [2] - Folding Lower Level
// [3] - not used
// GATE - not used
//
// =============================================================================

#ifndef SynthTutorial15_h
#define SynthTutorial15_h

#include "Synth.h"

class SynthTutorial15 : public Synth
{
  public:
    SynthTutorial15(Inputs *inputs); 
};

#endif