/*
 *  +----------------------+
 *  | ModuleADSR           |
 *  |----------------------|
 *  > gate_input           |
 *  > frequency_input      |
 *  > slope_input          |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
 
#ifndef ModuleADSR_h
#define ModuleADSR_h

#include "Arduino.h"
#include "Module.h"

#define ADSR_INACTIVE 0
#define ADSR_ATTACK 1
#define ADSR_DECAY 2
#define ADSR_SUSTAIN 3
#define ADSR_RELEASE 4


class ModuleADSR : public Module
{
  
  public:
    ModuleADSR();

    // Inputs
    Module *frequency_input;
    Module *slope_input;
    Module *trigger_input;
    
  private:
  
    // Functions
    uint32_t compute();  

    // Variables
    uint32_t slope_index;
    uint32_t frequency;
    uint16_t slope;                    // The currenly selected wavetable
    // uint32_t increments[128];
    uint32_t increment;
    bool triggered;
    int state;
    uint32_t adsr_output;
    
    // 10.22 fixed point number (using the upper 10 bits for addressing the indexes 
    // up to 1024 (we only need 600), and an additional 22 bits (0-4194304) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_10_22_index;
    uint32_t increment_by;
};

#endif
