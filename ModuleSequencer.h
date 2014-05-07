/*
 *  +----------------------+
 *  | ModuleSequencer      |
 *  |----------------------|
 *  > clock_input          |
 *  |                      |
 *  |               output >
 *  +----------------------+
 *
 *
 */
// =============================================================================
// 
// ModuleSequencer is a simple 8 step CV sequencer.  Clocking the sequencer
// steps through the 8 steps.  The sequence itself is passed into the module's
// constructor.
//
// Example usage:
//
//   int sequence[] = { 0, 100, 2300, 4000, 1400, 500, 70, 4092 };
//
//	 ModuleSequencer *sequencer = new ModuleSequencer(sequence);
//	 ModuleWavetable *wavetable = new ModuleWavetable(equations_wavetable);
//
//	 sequencer->clock_input = inputs->gate;
//
//	 wavetable->equation_input = inputs->mod;
//	 wavetable->frequency_input = sequencer;
//
//	 this->last_module = wavetable;
//
 
#ifndef ModuleSequencer_h
#define ModuleSequencer_h

#include "Arduino.h"
#include "Module.h"

class ModuleSequencer : public Module
{
  
  public:
    ModuleSequencer(int values[]);
    uint32_t compute();
    
    // Inputs
    Module *clock_input;
    
  private:
    int step;
    int sequence[8];
    uint32_t old_clock;
};

#endif
