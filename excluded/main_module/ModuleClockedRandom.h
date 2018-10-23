/*
 *   +-------------------------+
 *   | ModuleClockedRandom     |
 *   |-------------------------|
 *   > clock_input             |
 *   |                         |
 *   |                  output >
 *   +-------------------------+
 *
*/
// =============================================================================
//
// ModuleClockedRandom is a clocked random number generator.  The output ranges
// from 0 to 4095.
//
// Example usage:
//
//    ModuleWavetableOsc *osc = new ModuleWavetableOsc();
//    ModuleClockedRandom *clocked_random = new ModuleClockedRandom();
//    ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
//
//    ext_clock->clock_input = inputs->gate;
//
//    clocked_random->clock_input = ext_clock;
//
//    osc->frequency_input = clocked_random;
//
//    this->last_module = osc;
//

#ifndef ModuleClockedRandom_h
#define ModuleClockedRandom_h

#include "Arduino.h"
#include "Module.h"
#include "Rand.h"

class ModuleClockedRandom : public Module
{
  
  public:
  
    ModuleClockedRandom();
    uint16_t compute();
    
    // Inputs
    Module *clock_input;

  private:
  
    boolean clocked;
    uint32_t old_clock;
    uint32_t latched_output;

    Rand rand;
};

#endif
