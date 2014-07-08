// =============================================================================
//
// Name: Synth3Osc
// Type: Audio
// Written by: Gaetan Ro, 2014
// 
// Description: Synth3Osc is a 3 osc synth with 2 main oscillators which can be 
// detuned a sub oscillator, and a low-pass filter.
// 
// The MOD input controls the oscillator configuration. There are 16 configurations. 
// For example, the first 4 configurations are:
//
// MOD 	osc1 	  osc2      sub osc
// ----------------------------------------
// 0 	sine 	  sine      sine (50% vol)
// 1 	sine 	  sawtooth 	sine (50% vol)
// 2 	sawtooth  sawtooth 	sine (50% vol)
// 3 	sawtooth  square 	sine (50% vol)
//
// Param1 is the detuning between the first 2 oscillators.  In the middle of the 
// potentiometer there is no detune, in the far right, the second oscillator is 
// a quarter tone higher, and far left is a quarter tone lower.
//
// Param2 is the cutoff for the lowpass filter
//
// Param3 is the resonance for the lowpass filter
//
// Input summary:
//
// SR  - Sample Rate (pitch)
// MOD - Selects the oscillator configuraton 
// [1] - Detune
// [2] - Lowpass Cutoff
// [3] - Lowpass Resonance
// GATE - Not used
//
// =============================================================================

#ifndef Synth3Osc_h
#define Synth3Osc_h

#include "Arduino.h"
#include "Synth.h"

class Synth3Osc : public Synth
{
  public:
  
    Synth3Osc(Inputs* inputs); 
};

#endif
