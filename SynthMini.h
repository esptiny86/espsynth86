// =============================================================================
//
// Name: SynthMini
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Simple wavetable mini single voice synth.  External control over
// wavetable selection, sample rate, low-pass filter cutoff and resonance,
// and amplitude.
//
// SR  - sample rate
// MOD - wavetable selecation
// [1] - Lowpass Filter cutoff
// [2] - Lowpass Filter resonance
// [3] - Amplitude
// GATE - not used
//
// =============================================================================

#ifndef SynthMini_h
#define SynthMini_h

#include "Synth.h"

class SynthMini : public Synth
{
  public:
    SynthMini(Inputs *inputs); 
};

#endif
