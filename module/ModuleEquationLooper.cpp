#include "Arduino.h"
#include "ModuleEquationLooper.h"
#include "defines.h"

ModuleEquationLooper::ModuleEquationLooper(EquationBank *equation_bank)
{
  fixed_point_20_12_index = 0;
  this->equation_bank = equation_bank;

  // Initialize all inputs
  this->sample_rate_input = NULL;
  this->loop_start_input = NULL;
  this->loop_length_input = NULL;
  this->equation_input = NULL;
  this->param3_input = NULL;
  this->gate_input = NULL;  
}

uint16_t ModuleEquationLooper::compute()
{
  // Read inputs
  // For loop_start and loop_length, I'm dropping some of the least significant 
  // bits in order to remove any noise from the incoming signal.
  
  equation = this->readInput(equation_input, 0, equation_bank->number_of_equations);
  increment_by = this->readInput(sample_rate_input) << 1;                         // range: 0 - 4095
  loop_length = (this->readInput(loop_length_input, CONVERT_TO_9_BIT)+1) * 120;  // range: (1 - 512) * 120
  loop_start = this->readInput(loop_start_input, CONVERT_TO_9_BIT) * 800;    // range: (0 - 511) * 800
  p3 = this->readInput(param3_input, CONVERT_TO_8_BIT);
  gate = this->readInput(gate_input);

  fixed_point_20_12_index += increment_by;
  
  // shift off th 12 bits used for fractional numbers, which leaves us with a 20 bit number
  playback_position = loop_start + (fixed_point_20_12_index >> 12); 
  
  if(gate < MID_CV) // Gating the module disables looping
  {
    // If the playback position is at the loop end, then restart playback
    if(playback_position >= (loop_start + loop_length))
    {
      playback_position = 0;
      fixed_point_20_12_index = 0;
    }
  }
  
  // Play the selected equation
  return(this->equation_bank->compute(equation, playback_position, 1, 1, p3));
  
}