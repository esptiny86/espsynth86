// =============================================================================
//
// Name: SynthEqWave
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: A wavetable synth, where the wavetables are small slices of 
// bytebeat equations.
//
// SR  - controls the sample rate of the wavetable playback
// MOD - selects equation to playback
// [1] - sets the position in the equation where the wavetable begins
// [2] - modifies the equation parameter p1, which variates the sound
// [3] - modifies the equation parameter p2, which variates the sound
// GATE - no function (yet)
//
// =============================================================================

#ifndef SynthEqWave_h
#define SynthEqWave_h

#include "Synth.h"

class SynthEqWave : public Synth
{
  public:  
    SynthEqWave(Inputs *inputs, Equations *equations); 
};

#endif