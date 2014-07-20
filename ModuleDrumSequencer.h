/*
 *  +----------------------+
 *  | ModuleDrumSequencer  |
 *  |----------------------|
 *  > clock_input          |
 *  |                      |
 *  > kick_pattern_input   |
 *  > snare_pattern_input  |
 *  > hat_pattern_input    |
 *  |                      |
 *  |          kick_output >
 *  |         snare_output >
 *  |           hat_output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleDrumSequencer is a simple gate sequencer for drums.  It contains three 
// different pattern generators, one for kick, snare, and hihat.
//
// TODO: create example
//

#ifndef ModuleDrumSequencer_h
#define ModuleDrumSequencer_h

#include "Arduino.h"
#include "Module.h"
#include "ModuleOutput.h"


class ModuleDrumSequencer : public Module
{
  
  public:
    ModuleDrumSequencer();
    uint16_t compute();
    
    // Inputs
    Module *clock_input;
    Module *kick_pattern_input;
    Module *snare_pattern_input;
    Module *hihat_pattern_input;
    
    // Outputs
    ModuleOutput *kick_output;
    ModuleOutput *snare_output;
    ModuleOutput *hihat_output;    

  private:
    uint8_t step;
    uint16_t patterns[3][8];  // 3 banks, 8 patterns per bank
    boolean clocked;
};

#endif
