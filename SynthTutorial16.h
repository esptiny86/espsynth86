// =============================================================================
//
// Name: SynthTutorial16
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of ModuleWaveShaper.  The waveshaper is still
// experimental.
//
// SR  - Sample rate input
// MOD - Wavetable selection
// [1] - Wet/Dry mix for waveshaper
// [2] - not used
// [3] - not used
// GATE - not used
//
// =============================================================================

#ifndef SynthTutorial16_h
#define SynthTutorial16_h

#include "Synth.h"

class SynthTutorial16 : public Synth
{
  public:
    SynthTutorial16(Inputs *inputs); 
};

#endif