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
 *  The speed is controlled via a BPM (beats per minute) value supplied during
 *  initialization:
 * 
 *    int beats_per_minute = 120;
 *    ModuleClock *module_clock = new ModuleClock(beats_per_minute);
 *    adsr.trigger_input = module_clock;
 *
 *  Here's another example:
 *
 *    ModuleADSR adsr;
 *    adsr.trigger_input = new ModuleClock(60);
 *
 */
 
#ifndef ModuleClock_h
#define ModuleClock_h

#include "Arduino.h"
#include "Module.h"

class ModuleClock : public Module
{
  public:
    ModuleClock(uint32_t bpm);
    ModuleClock(uint32_t bpm, int clock_division);
    uint32_t compute();
    
  private:
    uint32_t rate;
    uint32_t counter;
    uint32_t bpm;
    uint32_t bpm_ticks[255];
    uint32_t bpm_half_ticks[255];
};

#endif
