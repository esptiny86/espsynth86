/*
 *  +----------------------+
 *  | ModuleReverb         |
 *  |----------------------|
 *  > audio_input          |
 *  > mix_input            |
 *  > feedback_input       |
 *  > length_input         |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
//

#ifndef ModuleReverb_h
#define ModuleReverb_h

#include "Arduino.h"
#include "Module.h"

class ModuleReverb : public Module
{
  
  public:
    ModuleReverb();
    uint16_t compute();
    
    // Inputs
    Module *audio_input;
    Module *mix_input;   
    Module *feedback_input; 

  private:
    
    uint16_t buffer_index;
    uint32_t reverb_output;
};

#endif
