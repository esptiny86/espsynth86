// =============================================================================
//
// Name: SynthEquationLooper
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Plays 'bytebeat' equations as audio.  This synth offers less 
// control over the equation parameters, but allows you to control 
// playback_position and loop_length
//
// SR  - controls the sample rate of the equation playback
// MOD - selects equation to playback
// [1] - controls the loop playback position
// [2] - controls the loop length
// [3] - modifies the equation parameter p1, which variates the sound
// GATE - disables looping (meaning, the equation will playback continuously)
//
// =============================================================================

#ifndef SynthEquationLooper_h
#define SynthEquationLooper_h

#include "Synth.h"

class SynthEquationLooper : public Synth
{
  public:
    SynthEquationLooper(Inputs *inputs, EquationBank *equation_bank); 
};

#endif
