/*
 *  +----------------------+
 *  | ModuleClock          |
 *  |----------------------|
 *  |                      |
 *  |               output >
 *  +----------------------+
 *
 *
 *  The clock module produces a square wave with a 50% duty cycle starting low.
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
 *  Helpful clock divisions have been defined in defines.h.  Here are some examples:
 * 
 *  ModuleClock *module_clock = new ModuleClock(120, 48);                          // produce 1/8th note gates at 120 BPM
 *  ModuleClock *module_clock = new ModuleClock(120, EIGHTH_NOTE_CLOCK_DIVISION);  // produce 1/8th note gates at 120 BPM
 *  ModuleClock *module_clock = new ModuleClock(100, QUARTER_NOTE_CLOCK_DIVISION); // produce 1/4th note gates at 100 BPM
 *  ModuleClock *module_clock = new ModuleClock(100, WHOLE_NOTE_CLOCK_DIVISION);   // produce whole note gates at 100 BPM
 *
 */
 
#ifndef ModuleClock_h
#define ModuleClock_h

#include "Arduino.h"
#include "Module.h"

class ModuleClock : public Module
{
  public:
    ModuleClock(uint16_t bpm);
    ModuleClock(uint16_t bpm, int clock_division);
    uint16_t compute();
    
  private:
    uint32_t rate;
    uint32_t counter;
    uint32_t bpm;
    uint16_t bpm_ppqn[255];
    uint16_t bpm_half_ppqn[255];
};

#endif
