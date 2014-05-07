/*
 *   +----------------------+
 *   | ModuleEquationLooper |
 *   |----------------------|
 *   > sample_rate_input    |
 *   > equation_input       |
 *   > loop_length_input    |
 *   > loop_start_input     |
 *   > param3_input         |
 *   > gate_input           |
 *   |                output>
 *   +----------------------+
 *
 */
// =============================================================================
// 
// ModuleEquationPlayer is a simple bytebeat equation player with control over
// equation selection, sample rate, and loop parameters.  It uses the same set
// of equations as the ModuleEquationPlayer, but only allows control over one
// variable of the equation.  (In hindsight, I could have allowed control 
// over all three parameters, as the param1, 2, and 3 inputs of this module
// could be controlled by other modules.)
//
// When the gate input is HIGH, equations will stop looping and will playback
// continuously.
//
// Equations are passed in to the ModuleEquationPlayer via the constructor.
//
// Example usage:
//
//    ModuleEquationLooper *equation_looper = new ModuleEquationLooper(equations);
//
//    equation_looper->equation_input    = inputs->mod;
//    equation_looper->sample_rate_input = inputs->sr;
//    equation_looper->loop_start_input  = inputs->param1;
//    equation_looper->loop_length_input = inputs->param2;
//    equation_looper->param3_input      = inputs->param3;
//    equation_looper->gate_input        = inputs->gate;
//
//    this->last_module = equation_looper;
//


#ifndef ModuleEquationLooper_h
#define ModuleEquationLooper_h

#include "Arduino.h"
#include "Module.h"
#include "Equations.h"

class ModuleEquationLooper : public Module
{
  
  public:
    ModuleEquationLooper(Equations *equations);
    uint32_t compute();
    
    // Inputs
    Module *sample_rate_input;
    Module *equation_input;    
    Module *loop_start_input;
    Module *loop_length_input;
    Module *param3_input;
    Module *gate_input;
    
  private:

    int equation;
    int rate;
    int gate;
    
    uint32_t loop_start; 
    uint32_t old_loop_start;
    uint32_t loop_length;
    uint32_t playback_position;
    uint32_t p3;
   
    Equations *equations;

    // 20.12 fixed point number (using the upper 20 bits for holding the usable
    // numbers and an additional 12 bits for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_20_12_index;
    uint32_t increment_by;
};

#endif
