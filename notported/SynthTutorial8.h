// =============================================================================
//
// Name: SynthTutorial8
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Example usage of the Quantizer module.  The output of an LFO
// is used to control the pitch of a wavetable oscillator.
//
// SR  - Controls the speed of the LFO
// MOD - Wavetable selection
// [1] - Selects the scale for quantization
// [2] - Selects the wavetable for the LFO
// [3] - not used
// GATE - not used
//
// =============================================================================

#ifndef SynthTutorial8_h
#define SynthTutorial8_h

#include "Synth.h"

class SynthTutorial8 : public Synth
{
  public:
    SynthTutorial8(Inputs *inputs); 
};

#endif