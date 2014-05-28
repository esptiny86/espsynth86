/*
 *  +----------------------+
 *  | ModuleMap            |
 *  |----------------------|
 *  > input                |
 *  |               output >
 *  +----------------------+
 *
 *
 */
// =============================================================================
// 
// Maps an incoming voltage to a value between A and B, where A and B area 
// supplied as parameters to this module's constructor
//
// TODO: add example usage

 
#ifndef ModuleMap_h
#define ModuleMap_h

#include "Module.h"

class ModuleMap : public Module
{
  public:
    ModuleMap(uint32_t low, uint32_t high);
    uint32_t compute();
    
    // Inputs
    Module *input;

    uint32_t low;
    uint32_t high;
};

#endif