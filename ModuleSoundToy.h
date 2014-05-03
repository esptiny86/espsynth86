#ifndef ModuleSoundToy_h
#define ModuleSoundToy_h

#include "Module.h"

class ModuleSoundToy : public Module
{
  public:
    ModuleSoundToy();
    uint32_t compute();
	
    uint32_t exp_fix0912(uint32_t in);
    uint32_t sin_fix1212(uint32_t in);
    uint32_t cos_fix1212(uint32_t in);
    uint32_t square_fix1212(uint32_t in);
    uint32_t saw_fix1212(uint32_t x, uint32_t a);

    Module *trigger_input;
    Module *frequency_input;
    Module *sound_input;    
    
  private:
  
    float y;
    uint32_t output;
    uint32_t t;
    uint32_t trigger;
    uint32_t old_trigger;
    uint32_t sound;
    
    uint16_t Sine[1024];
    uint16_t Exp[4095];
    uint32_t frequency; // = 440;   
    uint32_t value;
    
    // 20.12 fixed point number (using the upper 20 bits for holding the usable
    // numbers and an additional 12 bits (0-4095) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_20_12_index;
    uint32_t increment_by;    
};
    
#endif



    

