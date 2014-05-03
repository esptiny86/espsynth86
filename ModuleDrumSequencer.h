/*
 *  +----------------------+
 *  | ModuleDrumSequencer  |
 *  |----------------------|
 *  > clock_input          |
 *  > sequence_input       |
 *  |               output >
 *  +----------------------+
 */
 
#ifndef ModuleDrumSequencer_h
#define ModuleDrumSequencer_h

#include "Arduino.h"
#include "Module.h"

class ModuleDrumSequencer : public Module
{
  
  public:
    ModuleDrumSequencer(int bank);
    uint32_t compute();
    
    // Inputs
    Module *clock_input;
    Module *pattern_input;
    
  private:
    int bank; 
    int step;
    int patterns[3][8];  // 3 banks, 8 patterns per bank
    uint32_t old_clock;
    boolean clocked;
    uint32_t my_output;
};

#endif
