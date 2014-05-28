/*
 *  +----------------------+
 *  | ModuleExtClock       |
 *  |----------------------|
 *  > clock_input          |
 *  |               output >
 *  +----------------------+
 *
 *  -----------------------------------------------------------------------------
 *  This module differs from the ModuleClock as it will stop generating
 *  clock pulses when a clock signal is detected at ext_input.  When an external
 *  clock signal is present, it is passed through to the output and the internal
 *  clock generator is suspended.
 *  -----------------------------------------------------------------------------
 *
 *  The ext clock module produces a square wave with a 50% duty cycle starting low.
 *           _____       _____
 *          |     |     |     |
 *     _____|     |_____|     |  etc...
 *
 *  The clock speed is controlled via a BPM (beats per minute) value supplied during
 *  instantiation, like: 
 * 
 *    int beats_per_minute = 120;
 *    ModuleClock *module_clock = new ModuleClock(beats_per_minute);
 *
 *  The output is 96 pulses per quarter note.  A second parameter can be supplied
 *  in the constructor to act as a clock divider.  To have the clock output
 *  quarter note pulses, we divide the 96 pulses-per-quarter-note by 96:
 *
 *  ModuleClock *module_clock = new ModuleClock(120, 96);
 *
 *  Helpful clock divisions have been defined in defines.h.  
 *

 * 
 *  ModuleClock *module_clock = new ModuleClock(120, 48);                          // produce 1/8th note gates at 120 BPM
 *  ModuleClock *module_clock = new ModuleClock(120, EIGHTH_NOTE_CLOCK_DIVISION);  // produce 1/8th note gates at 120 BPM
 *  ModuleClock *module_clock = new ModuleClock(100, QUARTER_NOTE_CLOCK_DIVISION); // produce 1/4th note gates at 100 BPM
 *  ModuleClock *module_clock = new ModuleClock(100, WHOLE_NOTE_CLOCK_DIVISION);   // produce whole note gates at 100 BPM
 *
 */
 
#ifndef ModuleExtClock_h
#define ModuleExtClock_h

#include "Arduino.h"
#include "Module.h"

class ModuleExtClock : public Module
{
  public:
    ModuleExtClock(uint32_t bpm);
    ModuleExtClock(uint32_t bpm, int clock_division);
    uint32_t compute();

    // Inputs
    Module *clock_input;  


  private:
    uint32_t rate;
    uint32_t counter;
    uint32_t bpm;
    uint32_t bpm_ppqn[255];
    uint32_t bpm_half_ppqn[255];
    uint32_t ext_clocked;    
    uint32_t ext_clock_counter;
};

#endif
