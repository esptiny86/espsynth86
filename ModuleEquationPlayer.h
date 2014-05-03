#ifndef ModuleEquationPlayer_h
#define ModuleEquationPlayer_h

#include "Arduino.h"
#include "Module.h"
#include "Equations.h"

class ModuleEquationPlayer : public Module
{
  
  public:
    ModuleEquationPlayer(Equations *equations);
    uint32_t compute();
    
    // Inputs
    Module *equation_input;
    Module *sample_rate_input;
    Module *param1_input;
    Module *param2_input;
    Module *param3_input;
    Module *reset_input;
    Module *mod_input;
    
  private:
    int equation;
    uint32_t t;           // Accumulator used in equations 
    
    uint32_t p1;
    uint32_t p2;
    uint32_t p3;
    
    Equations *equations;

    uint32_t reset;
    uint32_t old_reset;
    
    // 20.12 fixed point number (using the upper 20 bits for holding the usable
    // numbers and an additional 12 bits (0-4095) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint64_t fixed_point_32_32_index;
    uint64_t increment_by;
    
    uint32_t SquareRoot(uint32_t a_nInput);
    uint32_t exp_fix0912(uint32_t in);
    uint32_t sin_fix1212(uint32_t in);
    uint32_t cos_fix1212(uint32_t in);
    uint32_t square_fix1212(uint32_t in);
    uint32_t saw_fix1212(uint32_t x,uint32_t a);
    
};

#endif
