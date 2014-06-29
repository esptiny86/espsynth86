/*
 *  +----------------------+
 *  | ModuleFreeze         |
 *  |----------------------|
 *  > audio_input          |
 *  > freeze_input         |
 *  > length_input         |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
//
// Example usage:
//
//

#ifndef ModuleFreeze_h
#define ModuleFreeze_h

#include "Arduino.h"
#include "Module.h"

class ModuleFreeze : public Module
{
  
  public:
    ModuleFreeze();
    uint16_t compute();
    
    // Inputs
    Module *audio_input;
    Module *freeze_input;   
    Module *length_input; 

  private:
    
    int buffer_index;
    uint16_t buffer_output;
};

#endif
