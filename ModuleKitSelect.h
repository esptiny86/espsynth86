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

    uint8_t kits[3][3]; // 3 kits, 3 values each (kick, snare, hat)

    // Inputs
    Module *kit_selection_input;

    // Outputs
    ModuleOutput *kick_output;
    ModuleOutput *snare_output;
    ModuleOutput *hihat_output;
};

#endif
