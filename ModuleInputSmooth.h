
// =============================================================================
//
// This is not a module that you use to build a synth.  It gives you the
// ability to smooth inputs:
//
// Before:
// equation_player->equation_input = inputs->mod;
//
// After
// equation_player->equation_input = inputs->mod->smooth;
//

#ifndef ModuleInputSmooth_h
#define ModuleInputSmooth_h

#include "Module.h"

class ModuleInputSmooth : public Module
{
  private:
    uint16_t compute();

  public:
    ModuleInputSmooth(Module *parent_module);
    
    // Variables
    Module *parent_module;
    uint32_t value; // The value of the input    

    // Smoothing variables
    uint16_t readings[8];  // the readings from the analog input
    uint16_t index;         // the index of the current reading
    uint16_t total;         // the running total
    uint16_t average;       // the average    
};

#endif
