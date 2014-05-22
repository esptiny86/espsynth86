/*
 *  +----------------------+
 *  | ModuleOutput         |
 *  |----------------------|
 *  |               output >
 *  +----------------------+
 *
 *
 */

#ifndef ModuleOutput_h
#define ModuleOutput_h

#include "Module.h"

class ModuleOutput : public Module
{
  public:
    ModuleOutput(Module *parent_module);
    uint32_t compute();
    int value;
    
  private:
    Module *parent_module;
    
};

#endif