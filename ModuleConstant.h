/*
 *   +----------------------+
 *   | ModuleConstant       |
 *   |----------------------|
 *   |                      |
 *   |               output >
 *   +----------------------+
 *
 */
 
#ifndef ModuleConstant_h
#define ModuleConstant_h

#include "Arduino.h"
#include "Module.h"

class ModuleConstant : public Module
{
  
  public:
    
    // Methods
    ModuleConstant(int value);
    uint32_t compute();
    
    void setValue(uint32_t value);
    uint32_t getValue();
    
    // Variables
    uint32_t value;
};

#endif
