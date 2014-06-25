/*
 *  +----------------------+
 *  | ModuleMixer2         |
 *  |----------------------|
 *  > input_1              |
 *  > input_2              |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// 2 input mixer.
//
// Example usage:
//
// Examples pending.  See ModuleMixer3.h.


#ifndef ModuleMixer2_h
#define ModuleMixer2_h

#include "Module.h"

class ModuleMixer2 : public Module
{
    public:    
  	ModuleMixer2();
    uint16_t compute();  

    // Inputs
    Module *input_1;
    Module *input_2;
};

#endif
