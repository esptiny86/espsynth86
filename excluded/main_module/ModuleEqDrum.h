/*
 *  +----------------------+
 *  | ModuleEqDrum         |
 *  |----------------------|
  * > sample_rate_input    |
 *  > drum_selection_input |
 *  > trigger_input        |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleEqDrum is a bytebeat player focused on drum sounds.  Only one sound can
// be played back simultaneously.  The drum_selection_input selects which of
// the equations to use for playback.  Unlike many of the other bytebeat playback
// modules, this one playsback the equation in "one-shot-mode", which is triggered
// by a gate signal at the trigger_input.  The sample rate affects the pitch of
// the drum sounds.
//
//
// Example usage:
//
//   ModuleEqDrum *drum_sound = new ModuleEqDrum();
//
//   drum_sound->sample_rate_input    = inputs->sr;
//   drum_sound->drum_selection_input = inputs->mod;
//   drum_sound->trigger_input        = inputs->gate;
//
//   this->last_module = drum_sound;
//

#ifndef ModuleEqDrum_h
#define ModuleEqDrum_h

#include "Arduino.h"
#include "Module.h"
#include "FixedPointMath.h"

class ModuleEqDrum : public Module
{
  
  public:
    ModuleEqDrum();
    uint16_t compute();
    uint32_t stop_playback();

    // Inputs
    Module *sample_rate_input;    
    Module *drum_selection_input;
    Module *trigger_input;
    
    
  private:
    uint32_t drum_selection;
    uint32_t trigger;    
    boolean triggered;
    boolean playing;

    uint32_t t;           // Accumulator used in equations 
    uint32_t w;           // The final output of the equation
   
    // 20.12 fixed point number (using the upper 20 bits for holding the usable
    // numbers and an additional 12 bits for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_20_12_index;
    uint32_t increment_by;
    
    FixedPointMath fixed_point_math;
};

#endif
