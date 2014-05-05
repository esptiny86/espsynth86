/*
 *  +----------------------+
 *  | ModuleWavetable      |
 *  |----------------------|
 *  > frequency_input      |
 *  > wavetable_input      |
 *  |               output >
 *  +----------------------+
 */


#ifndef ModuleWavetable_h
#define ModuleWavetable_h

#include "Arduino.h"
#include "Module.h"
#include "EquationsWavetable.h"
 
class ModuleWavetable : public Module
{
  
  public:
    ModuleWavetable(EquationsWavetable *equations);
    uint32_t compute();
    
    // Inputs
    Module *frequency_input;
    Module *equation_input;
    
  private:
    uint32_t increments[128];
    EquationsWavetable *equations;

    // 10.22 fixed point number (using the upper 10 bits for addressing the indexes 
    // up to 1024 (we only need 600), and an additional 22 bits (0-4194304) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_10_22_index;
    
    // uint32_t wavetable_offset;
    //uint32_t wavetable_offset_multiplier;
};

#endif
