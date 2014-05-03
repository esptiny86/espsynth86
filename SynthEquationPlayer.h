// =============================================================================
//
// Name: SynthEquationPlayer
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Plays 'bytebeat' equations as audio.  Three parameters of each
// equation can be tweaked to variate the output.
//
// SR  - controls the sample rate of the equation playback
// MOD - selects equation to playback
// [1] - modifies the equation parameter p1
// [2] - modifies the equation parameter p2
// [3] - modifies the equation parameter p3
// GATE - resets the playback position
//
// =============================================================================

#ifndef SynthEquationPlayer_h
#define SynthEquationPlayer_h

#include "Synth.h"

class SynthEquationPlayer : public Synth
{
  public:
    SynthEquationPlayer(Inputs *inputs, Equations *equations); 
};

#endif
