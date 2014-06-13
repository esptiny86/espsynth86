// =============================================================================
//
// Name: SynthWavetableDelay
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration of ModuleAddNote
//
// SR  - 
// MOD - 
// [1] - 
// [2] - 
// [3] - not used
// GATE - not used
//
// =============================================================================

#ifndef SynthWavetableDelay_h
#define SynthWavetableDelay_h

#include "Synth.h"

class SynthWavetableDelay : public Synth
{
  public:
    SynthWavetableDelay(Inputs *inputs); 
};

#endif