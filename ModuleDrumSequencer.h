/*
 *  +----------------------+
 *  | ModuleDrumSequencer  |
 *  |----------------------|
 *  > clock_input          |
 *  > sequence_input       |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleDrumSequencer is a simple gate sequencer for drums.  It contains three
// banks of 8 patterns each.  The banks are as follows:
//
// Bank #0: Best for sequencing kick drum sounds
// Bank #1: Best for sequencing snare drum sounds
// Bank #2: Best for sequencing hihat drum sounds
//
// The bank is selected by passing in the bank number into the ModuleDrumSequencer
// constructor.  The bank cannot be changed in realtime.  The pattern, however,
// can be controlled using the pattern_input.  The sequence playback position
// is incremented whenever there's a gate signal at the clock_input.
//
// Example usage: A very simple kick drum sequencer
//
//   ModuleDrumSequencer *kick_drum_sequencer = new ModuleDrumSequencer(0);
//
//   kick_drum_sequencer->pattern_input = inputs->mod;
//   kick_drum_sequencer->clock_input = inputs->gate;
//
//   this->last_module = kick_drum_sequencer;
//

#ifndef ModuleDrumSequencer_h
#define ModuleDrumSequencer_h

#include "Arduino.h"
#include "Module.h"

class ModuleDrumSequencer : public Module
{
  
  public:
    ModuleDrumSequencer(int bank);
    uint32_t compute();
    
    // Inputs
    Module *clock_input;
    Module *pattern_input;
    
  private:
    int bank; 
    int step;
    int patterns[3][8];  // 3 banks, 8 patterns per bank
    uint32_t old_clock;
    boolean clocked;
    uint32_t my_output;
};

#endif
