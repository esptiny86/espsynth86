/*
 *   +----------------------+
 *   | ModuleConstant       |
 *   |----------------------|
 *   |                      |
 *   |               output >
 *   +----------------------+
 *
 */
// =============================================================================
// 
// ModuleConstant is used to supply constant values to the inputs of other
// modules.
//
// Example usage:
//
//   ModuleWavetable *wavetable = new ModuleWavetable(equations_wavetable);
//
//	 wavetable->equation_input = new ModuleConstant(3);
//	 wavetable->frequency_input = sequencer;
//
//	 this->last_module = wavetable;
//

#ifndef ModuleConstant_h
#define ModuleConstant_h

#include "Arduino.h"
#include "Module.h"

class ModuleConstant : public Module
{
  
  public:
    
    // Methods
    ModuleConstant();
    ModuleConstant(int value);
    uint16_t compute();
    
    void setValue(uint32_t value);
    uint32_t getValue();
    
    // Variables
    uint32_t value;
};

#endif
