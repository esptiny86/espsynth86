/*
 *   +----------------------+
 *   | ModuleEquationShot   |
 *   |----------------------|
 *   > sample_rate_input    |
 *   > equation_input       |
 *   > position_input       |
 *   > param3_input         |
 *   > reset_input          |
 *   |                output>
 *   +----------------------+
 *
 */
// =============================================================================
// 
//


#ifndef ModuleEquationShot_h
#define ModuleEquationShot_h

#include "Arduino.h"
#include "Module.h"
#include "Equations.h"

class ModuleEquationShot : public Module
{
  
  public:
    ModuleEquationShot(Equations *equations);
    uint16_t compute();
    
    // Inputs
    Module *sample_rate_input;
    Module *equation_input;    
    Module *start_position_input;
    Module *param3_input;
    Module *reset_input;
    
  private:

    uint16_t equation;
    uint16_t rate;
    uint16_t position; 
    uint16_t p3;    
    uint16_t reset;
    uint16_t old_reset;
   
    Equations *equations;

    // 20.12 fixed point number (using the upper 20 bits for holding the usable
    // numbers and an additional 12 bits for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_20_12_index;
    uint32_t increment_by;
    uint32_t playback_position;
};

#endif
