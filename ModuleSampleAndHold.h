/*
 *  +----------------------+
 *  | ModuleSampleAndHold  |
 *  |----------------------|
 *  > trigger_input        |
 *  > sample_input         |
 *  |               output >
 *  +----------------------+
 *
 *
 */
// =============================================================================
// 
// ModuleSampleAndHold acts like a traditional analog Sample&Hold module.  
// A rising clock signal at trigger_input samples the value at sample_input and
// outputs it.
//
// Example pending.
//

 
#ifndef ModuleSampleAndHold_h
#define ModuleSampleAndHold_h

#include "Module.h"

class ModuleSampleAndHold : public Module
{
  public:
    ModuleSampleAndHold();
    uint32_t compute();
    
    // Inputs
    Module *trigger_input;      
    Module *sample_input;      
    
  private:
    uint32_t sampled_value;
    boolean triggered;
};

#endif