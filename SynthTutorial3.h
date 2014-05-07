// =============================================================================
//
// Name: SynthTutorial3
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Very simple kick drum sequencer
//
// SR  - not used
// MOD - Selects kick drum pattern
// [1] - not used
// [2] - not used
// [3] - not used
// GATE - Steps the kick drum sequencer
//
// =============================================================================

#ifndef SynthTutorial3_h
#define SynthTutorial3_h

#include "Synth.h"

class SynthTutorial3 : public Synth
{
  public:
    SynthTutorial3(Inputs *inputs); 
};

#endif