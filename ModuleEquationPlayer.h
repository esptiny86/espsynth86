/*
 *   +----------------------+
 *   | ModuleEquationPlayer |
 *   |----------------------|
 *   > equation_input       |
 *   > sample_rate_input    |
 *   > param1_input         |
 *   > param2_input         |
 *   > param3_input         |
 *   > reset_input          |
 *   |                output>
 *   +----------------------+
 *
 */
// =============================================================================
// 
// ModuleEquationPlayer is a simple bytebeat equation player with control over
// equation selection, sample rate, and equation parameters.  The reset input
// is used reset playback from the beginning.
//
// Equations are passed in to the ModuleEquationPlayer via the constructor.
//
// Example usage:
//
//   ModuleEquationPlayer *equation_player = new ModuleEquationPlayer(equations);
//  
//   equation_player->equation_input    = inputs->mod;
//   equation_player->sample_rate_input = inputs->sr;
//   equation_player->param1_input      = inputs->param1;
//   equation_player->param2_input      = inputs->param2;
//   equation_player->param3_input      = inputs->param3;
//   equation_player->reset_input       = inputs->gate;
//
//    this->last_module = equation_player;
//

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
    
  private:
    int equation;
    uint32_t t;
    
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

};

#endif
