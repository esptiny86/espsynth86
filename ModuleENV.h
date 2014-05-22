/*
 *  +----------------------+
 *  | ModuleENV            |
 *  |----------------------|
 *  > gate_input           |
 *  > frequency_input      |
 *  > slope_input          |
 *  |                      |
 *  |               output >
 *  |      inverted_output >
 *  |           end_output >
 *  +----------------------+
 */
 //
 // TODO: Write detailed documentation here
 //
 
#ifndef ModuleENV_h
#define ModuleENV_h

#include "Arduino.h"
#include "Module.h"
#include "ModuleOutput.h"

#define ENV_INACTIVE 0
#define ENV_PLAYING 1


class ModuleENV : public Module
{
  
  public:
    ModuleENV();

    // Inputs
    Module *frequency_input;
    Module *slope_input;
    Module *trigger_input;

    // Outputs
    ModuleOutput *output;
    ModuleOutput *inverted_output;
    ModuleOutput *end_output;    
    
  private:
  
    // Functions
    uint32_t compute();  

    // Variables
    uint32_t slope_index;
    uint32_t frequency;
    uint16_t slope;
    uint32_t increment;
    bool triggered;
    int state;
    uint32_t env_output;
    
    // 10.22 fixed point number (using the upper 10 bits for addressing the indexes 
    // up to 1024 (we only need 600), and an additional 22 bits (0-4194304) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_10_22_index;
    uint32_t increment_by;
};

#endif
