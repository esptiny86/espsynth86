/*
 *  +----------------------+
 *  | ModuleAdd            |
 *  |----------------------|
 *  > input_1              |
 *  > input_2              |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// Adds the values at input_1 and input_2 and outputs the sum.  For audio
// signals, consider using ModuleMixer2 instead.
//


#ifndef ModuleAdd_h
#define ModuleAdd_h

#include "Module.h"

class ModuleAdd : public Module
{
    public:    
  	ModuleAdd();
    uint16_t compute();  

    // Inputs
    Module *input_1;
    Module *input_2;
};

#endif
