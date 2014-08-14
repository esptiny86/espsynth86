/*
 *  +----------------------+
 *  | ModuleCounter        |
 *  |----------------------|
 *  > clock_input          |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleCounter is used for counting up from 0 to a target number (inclusive).  
// Once the target number has been reached, the output loops back to 0. 
// The target number is passed into ModuleCounter's constructor.   The counter
// is incremented in response to a positive clock pulse at the clock input.
//
// Here's an example which uses a counter to cycle through the first 6 
// equations of the wavetable module:
//
//   ModuleCounter *counter = new ModuleCounter(5);  // count from 0 to 5
//   ModuleClock *bpm_clock = new ModuleClock(120, EIGHTH_NOTE_CLOCK_DIVISION);  // clock at 120BPM
//   ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
//
//   counter->clock_input = bpm_clock;
//   wavetable_osc->wavetable_input = counter;
//   wavetable_osc->frequency_input  = inputs->sr;
//
//   this->last_module = wavetable_osc;

 
#ifndef ModuleCounter_h
#define ModuleCounter_h

// #include "Arduino.h"
#include "Module.h"

class ModuleCounter : public Module
{
  public:
    ModuleCounter(int target);
    uint16_t compute();
    
    // Inputs
    Module *clock_input;      
    
  private:
    int value;
    int target;
    uint32_t my_output;
    boolean clocked;
    
};

#endif
