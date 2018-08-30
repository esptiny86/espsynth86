/*
 *  +----------------------+
 *  | ModuleFreeze         |
 *  |----------------------|
 *  > audio_input          |
 *  > length_input         |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleFreeze is an audio effect for "freezing audio" by capturing a slice of 
// audio and looping it.  The code for ModuleFreeze is based on the ModuleDelay 
// code and shares the same audio buffer.  As a side effect, using both a 
// ModuleDelay and ModuleFreeze in the same synth may cause strange behavior.
// 
// The length_input controls the slice length of the frozen audio.  When the 
// length input is less than 100, the freeze effect is turned off.  This allows
// full control over the freeze effect with one input.
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
//    freeze->length_input = inputs->param1;
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
    Module *length_input; 

  private:
    
    int buffer_index;
    uint16_t buffer_output;
};

#endif
