// =============================================================================
//
// Name: SynthChords
// Type: Audio
// Written by: Bret Truchan, 2014
// 
// Description: A wavetable based chord generator.  See GlobalChords.php 
// for a list of included chords.
//
// SR  - Base note of the chord
// MOD - Chord selection
// [1] - Scale Selection
// [2] - Wavetable #2 selection
// [3] - Wavetable #3 selection
// GATE - not used
//
// =============================================================================

#ifndef SynthChords_h
#define SynthChords_h

#include "Synth.h"

class SynthChords : public Synth
{
  public:
    SynthChords(Inputs *inputs); 
};

#endif