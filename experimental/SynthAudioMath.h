// =============================================================================
//
// Name: SynthEquationLooper
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Routes audio into equations, where the audio replaces the usual
// 't' incrementing variable.  This was an experiment to see if the equations
// could act as effects units for the audio.  On some patches you could hear
// the audio, but it was extrordinarily distorted.  Running waveforms into 
// the audio input also didn't sound good.  I'm moving this module into the
// 'experimental' folder.
//
// SR  - plug an audio signal into the SR inputs
// MOD - selects equation to playback
// [1] - modifies the equation parameter p1
// [2] - modifies the equation parameter p2
// [3] - modifies the equation parameter p3
//
// =============================================================================

#ifndef SynthAudioMath_h
#define SynthAudioMath_h

#include "Synth.h"

class SynthAudioMath : public Synth
{
  public:
    SynthAudioMath(Inputs *inputs, Equations *equations); 
};

#endif
