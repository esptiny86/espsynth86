// =============================================================================
//
// Name: SynthDrumPlayer
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Plays sequenced drum patterns using three different drum
// sequencers driving three equation based drum sounds.  
// The parameter [1], [2], and [3] inputs select the drum pattern.
// 
//
// SR  - controls the sample rate of the equation playback
// MOD - not used
// [1] - selects the pattern used for the kick drum's sequencer
// [2] - selects the pattern used for the snare drum's sequencer
// [3] - selects the pattern used for the hihat's sequencer
// GATE - steps each of the drum sequencers
//
// =============================================================================

#ifndef SynthDrumPlayer_h
#define SynthDrumPlayer_h

#include "Synth.h"

class SynthDrumPlayer : public Synth
{
  public:
    SynthDrumPlayer(Inputs *inputs); 
};

#endif
