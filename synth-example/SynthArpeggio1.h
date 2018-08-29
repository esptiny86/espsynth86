// =============================================================================
//
// Name: SynthArpeggio1
// Type: Audio
// Written by: Gaétan ROELENS, 2014
// 
// Description: 
//
// SR  - Root note
// MOD - Wavetable
// [1] - Arpeggiation pattern
// [2] - VCA decay time
// [3] - Delay mix
// GATE - (optional) Clocks the arpeggiator and triggers the envelope generator
//        that feeds the VCA
//
// =============================================================================

#ifndef SynthArpeggio1_h
#define SynthArpeggio1_h

#include "Synth.h"

class SynthArpeggio1 : public Synth
{
  public:
    SynthArpeggio1(Inputs *inputs); 
};

#endif
