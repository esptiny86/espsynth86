/*
 *  +----------------------+
 *  | ModuleMixer3         |
 *  |----------------------|
 *  > input1               |
 *  > input2               |
 *  > input3               |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */

#ifndef ModuleMixer3_h
#define ModuleMixer3_h

#include "Module.h"

class ModuleMixer3 : public Module
{
    public:    
  	ModuleMixer3();
    uint32_t compute();  

    // Inputs
    Module *input_1;
    Module *input_2;
    Module *input_3;
};

#endif
