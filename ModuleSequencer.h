/*
 *  +----------------------+
 *  | ModuleSequencer      |
 *  |----------------------|
 *  > clock_input          |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
 
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
