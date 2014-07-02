/*
 *  +----------------------+
 *  | ModuleFreeze         |
 *  |----------------------|
 *  > audio_input          |
 *  > freeze_input         |
 *  > length_input         |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleFreeze is an audio effect for "freezing audio", which, in this case,
// means capturing a slice of the audio and looping it.  The code for ModuleFreeze
// is based on the ModuleDelay code and shares the same buffer, which means 
// that using both in a synth will cause strange behavior.
// 
// The freeze_input is a gate input.  When high, the freeze effect is on.
// length_input controls the slice length of the frozen audio.
//
// Example usage:
//
//    ModuleEqDrum *drum_sound = new ModuleEqDrum();
//    ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
//    ModuleFreeze *freeze = new ModuleFreeze();
//
//    ext_clock->clock_input = inputs->gate;
//
//    drum_sound->sample_rate_input = inputs->sr;
//    drum_sound->drum_selection_input = inputs->mod;
//    drum_sound->trigger_input = ext_clock;
//
//    freeze->audio_input = drum_sound;
//    freeze->freeze_input = inputs->param1;
//    freeze->length_input = inputs->param2;
//
//    this->last_module = freeze;
//

#ifndef ModuleFreeze_h
#define ModuleFreeze_h

#include "Arduino.h"
#include "Module.h"

class ModuleFreeze : public Module
{
  
  public:
    ModuleFreeze();
    uint16_t compute();
    
    // Inputs
    Module *audio_input;
    Module *freeze_input;   
    Module *length_input; 

  private:
    
    int buffer_index;
    uint16_t buffer_output;
};

#endif
