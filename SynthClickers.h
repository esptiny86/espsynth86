// =============================================================================
//
// Name: SynthClickers
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: LFO driven clock divider fed into a drum player.  The output
// sounds a bit like a bouncing ball.
//
// SR  - sample rate of the drum sound
// MOD - drum selection input
// [1] - LFO frequency
// [2] - LFO wavetable
// [3] - not used
// GATE - (optional) supplies clock signal to the clock divider
//
// =============================================================================


#ifndef SynthClickers_h
#define SynthClickers_h

#include "Synth.h"

class SynthClickers : public Synth
{
  public:
    SynthClickers(Inputs *inputs); 
};

#endif