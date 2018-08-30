/*
 *  +----------------------+
 *  | ModuleOutput         |
 *  |----------------------|
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// Unlike most other modules, the ModuleOutput is NOT created inside of a synth.  
// Instead, it is created inside another module if that module requires multiple 
// outputs.
//
// If you're only creating synths and not building your own modules, you don't 
// have to worry about creating output modules.  If you are building your own 
// modules which have mutiple outputs, see the tutorial in the online documentation
// for creating modules.
//
// Typically, when creating a synth's code, you can wire together modules 
// like so:
//
//   some_module.some_input = some_other_module
//
// But if some_other_module has multiple outputs, you can specify the output like:
//
//   some_module.some_intput = some_other_module.specific_output
//


#ifndef ModuleOutput_h
#define ModuleOutput_h

#include "Module.h"

class ModuleOutput : public Module
{
  public:
    ModuleOutput(Module *parent_module);
    uint16_t compute();
    uint16_t value;
    
  private:
    Module *parent_module;
    
};

#endif