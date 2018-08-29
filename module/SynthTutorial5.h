// =============================================================================
//
// Name: SynthTutorial5
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: Demonstration using ModuleSwitch.  This is an unusual example
// where the output of two wavetable oscillators are rapidly switched between
// using the output of a third wavetable oscillator.  
// 
// A more traditional usage might be to switch between control voltages, 
// like LFOs or sequencer output.
// 
// SR  - Frequency input of oscillator #2
// MOD - Oscillator #3 wavetable selection
// [1] - Frequency output of oscillator #3, which controls the switching
// [2] - Wavetable selection of oscillator #1
// [3] - Frequency of oscillator #2
// GATE - Wavetable selection of oscillator #3
//
// =============================================================================

#ifndef SynthTutorial5_h
#define SynthTutorial5_h

#include "Synth.h"

class SynthTutorial5 : public Synth
{
  public:
    SynthTutorial5(Inputs *inputs); 
};

#endif