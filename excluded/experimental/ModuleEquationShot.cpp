#include "Arduino.h"
#include "ModuleEquationShot.h"
#include "defines.h"

ModuleEquationShot::ModuleEquationShot(Equations *equations)
{
  fixed_point_20_12_index = 0;
  this->equations = equations;

  // Initialize all inputs
  this->sample_rate_input = NULL;
  this->equation_input = NULL;
  this->start_position_input = NULL;  
  this->param3_input = NULL;
  this->reset_input = NULL;  
}

uint16_t ModuleEquationShot::compute()
{
  // Read inputs
  // For loop_start and loop_length, I'm dropping some of the least significant 
  // bits in order to remove any noise from the incoming signal.
  
  equation = this->readInput(equation_input, 0, NUMBER_OF_EQUATIONS);
  increment_by = this->readInput(sample_rate_input) << 1;
  position = this->readInput(start_position_input) << 2;
  p3 = this->readInput(param3_input, CONVERT_TO_8_BIT);
  reset = this->readInput(reset_input);

  fixed_point_20_12_index += increment_by;
  
  // shift off th 12 bits used for fractional numbers, which leaves us with a 20 bit number
  playback_position = position + (fixed_point_20_12_index >> 12); 
  
  if((reset >= MID_CV) && (old_reset < MID_CV))
  {
    playback_position = 0;
    fixed_point_20_12_index = 0;
  }

  old_reset = reset;
  
  // Play the selected equation
  return(this->equations->compute(equation, playback_position, 1, 1, p3));
  
}