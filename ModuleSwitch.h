/*
 *  +----------------------+
 *  | ModuleSwitch         |
 *  |----------------------|
 *  > select_input         |
 *  > a_input              |
 *  > b_input              |
 *  |               output >
 *  +----------------------+
 *
 *
 */
// =============================================================================
// 
// ModuleSwitch routes either a_input or b_input to the output depending on the
// value at select_input.  If select_input is greater than MID_CV, intput_b
// is routed to the output.  Otherwise input_a is routed to the output.
//
// TODO: add example usage

 
#ifndef ModuleSwitch_h
#define ModuleSwitch_h

#include "Module.h"

class ModuleSwitch : public Module
{
  public:
    ModuleSwitch();
    uint32_t compute();
    
    // Inputs
    Module *select_input;
    Module *a_input;
    Module *b_input;
};

#endif