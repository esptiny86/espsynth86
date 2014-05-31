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
 
#ifndef ModuleClockedRandom_h
#define ModuleClockedRandom_h

#include "Arduino.h"
#include "Module.h"
#include "Rand.h"

class ModuleClockedRandom : public Module
{
  
  public:
  
    ModuleClockedRandom();
    uint32_t compute();
    
    // Inputs
    Module *clock_input;

  private:
  
    boolean clocked;
    uint32_t old_clock;
    uint32_t latched_output;

    Rand rand;
};

#endif
