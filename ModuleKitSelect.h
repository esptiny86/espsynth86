/*
 *   +----------------------+
 *   | ModuleKitSelect      |
 *   |----------------------|
 *   > kit_selection_input  |
 *   |                      |
 *   |           kick_output>
 *   |          snare_output>
 *   |          hihat_output>
 *   +----------------------+
 *
 */
// =============================================================================
// 
// ModuleKitSelect is a helper module for SynthDrumPlayer that outputs three
// values depending on the kit selection input.
//

#ifndef ModuleKitSelect_h
#define ModuleKitSelect_h

#include "Arduino.h"
#include "Module.h"
#include "ModuleOutput.h"

class ModuleKitSelect : public Module
{
  
  public:
    ModuleKitSelect();
    uint16_t compute();

    // The number in the kits array are the indexes of
    // the sounds in ModuleSamplePlayer.php

    uint8_t kits[3][3] = {
        { 
          0,1,2
        },
        {
          3,4,5
        },
        {
          6,7,8
        }    
    };


    // Inputs
    Module *kit_selection_input;

    // Outputs
    ModuleOutput *kick_output;
    ModuleOutput *snare_output;
    ModuleOutput *hihat_output;
};

#endif
