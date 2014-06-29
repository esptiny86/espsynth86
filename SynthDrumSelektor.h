// =============================================================================
//
// Name: SynthDrumSelektor
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: CV selectable drum pattern player simliar to the Analogue 
// Solution SP-8, but using equation generated drum sounds.
//
// SR  - Controls sample rate of drum sound
// MOD - CV selection of drum sound
// [1] - Freeze trigger input
// [2] - Freeze length input
// [3] - not used
// GATE - Triggers drum sound
//
// =============================================================================

#ifndef SynthDrumSelektor_h
#define SynthDrumSelektor_h

#include "Synth.h"

class SynthDrumSelektor : public Synth
{
  public:
    SynthDrumSelektor(Inputs *inputs); 
};

#endif