/*
 *   +----------------------+
 *   | ModuleQuantizer      |
 *   |----------------------|
 *   > cv_input             |
 *   > scale_input          |
 *   |               output >
 *   +----------------------+
 *
 */
// =============================================================================
// 
// TODO: description and documentation here
//


#ifndef ModuleQuantizer_h
#define ModuleQuantizer_h

#include "Arduino.h"
#include "Module.h"

class ModuleQuantizer : public Module
{
  
  public:
    ModuleQuantizer();
    uint32_t compute();
    
    // Inputs
    Module *cv_input;
    Module *scale_input;

};

#endif
