/*
 *  +----------------------+
 *  | ModuleExtClock       |
 *  |----------------------|
 *  > clock_input          |
 *  |               output >
 *  +----------------------+
 *
 *  ------------------------------------------------------------------------------
 *  When an external clock signal is present at clock_input, that signal
 *  is passed through to the output, and the internal clock generator is suspended.  
 *  This module is great for creating synths that can run off of either an 
 *  internally generated clock or externally supplied clock signal.
 *  ------------------------------------------------------------------------------
 *
 *  The ext clock module produces a square wave with a 50% duty cycle starting low.
 *           _____       _____
 *          |     |     |     |
 *     _____|     |_____|     |  etc...
 *
 *  The clock speed is controlled via a BPM (beats per minute) value supplied during
 *  instantiation, like: 
 * 
 *    ModuleExtClock *ext_clock = new ModuleExtClock(120);
 *    ext_clock->clock_input = inputs->gate;
 *    drum_sequencer->clock_input = ext_clock; 
 *
 *
 *  The output is 96 pulses per quarter note.  A second parameter can be supplied
 *  in the constructor to act as a clock divider.  To have the clock output
 *  quarter note pulses, we divide the 96 pulses-per-quarter-note by 96:
 *
 *    ModuleExtClock *ext_clock = new ModuleExtClock(120,96);
 *    ext_clock->clock_input = inputs->gate;
 *    drum_sequencer->clock_input = ext_clock; 
 *
 *  Helpful clock divisions have been defined in defines.h.  
 *
 * 
 *  ModuleExtClock *module_ext_clock = new ModuleExtClock(120, 48);                          // produce 1/8th note gates at 120 BPM
 *  ModuleExtClock *module_ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);  // produce 1/8th note gates at 120 BPM
 *  ModuleExtClock *module_ext_clock = new ModuleExtClock(100, QUARTER_NOTE_CLOCK_DIVISION); // produce 1/4th note gates at 100 BPM
 *  ModuleExtClock *module_ext_clock = new ModuleExtClock(100, WHOLE_NOTE_CLOCK_DIVISION);   // produce whole note gates at 100 BPM
 *
 */
 
#ifndef ModuleExtClock_h
#define ModuleExtClock_h

#include "Arduino.h"
#include "Module.h"

class ModuleExtClock : public Module
{
  public:
    ModuleExtClock(uint8_t bpm);
    ModuleExtClock(uint8_t bpm, uint16_t clock_division);
    uint16_t compute();

    // Inputs
    Module *clock_input;  


  private:
    uint32_t rate;
    uint32_t counter;
    uint8_t bpm;
    uint16_t bpm_ppqn[255];
    uint16_t bpm_half_ppqn[255];
    boolean ext_clocked;    
    uint32_t ext_clock_counter = 88400;
};

#endif
