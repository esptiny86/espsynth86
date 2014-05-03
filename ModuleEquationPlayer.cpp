#include "Arduino.h"
#include "ModuleEquationPlayer.h"
#include "Defines.h"

ModuleEquationPlayer::ModuleEquationPlayer(Equations *equations)
{
  t = 0;  // Set the counter to 0
  p1 = 0;
  p2 = 0;
  p3 = 0;
  old_reset = false;  
  reset = 0;
  fixed_point_32_32_index = 0;

  this->equations = equations;

  // Initialize all inputs
  this->equation_input = NULL;
  this->sample_rate_input = NULL;
  this->param1_input = NULL;
  this->param2_input = NULL;
  this->param3_input = NULL;
  this->reset_input = NULL;
  this->mod_input = NULL;  
}

uint32_t ModuleEquationPlayer::compute()
{

  // Read inputs
  equation = this->readInput(equation_input);
  increment_by = this->readInput(sample_rate_input);       // range: 0 - 4095
  p1 = this->readInput(param1_input, CONVERT_TO_8_BIT);    // range: 0 - 255 (2^8)
  p2 = this->readInput(param2_input, CONVERT_TO_8_BIT);    // range: 0 - 255 (2^8)
  p3 = this->readInput(param3_input, CONVERT_TO_8_BIT);    // range: 0 - 255 (2^8)
  reset = this->readInput(reset_input);

  increment_by = increment_by << 21;

  // If the reset input transitions from low to high, then reset fixed_point_20_12_index 
  // to 0, which effectively restarts the sound.  MID_CV is defined in defines.h
  if((reset >= MID_CV) && !old_reset) 
  {
    old_reset = true;
    fixed_point_32_32_index = 0;
  }  
  
  if(reset < MID_CV) old_reset = false;
  
  
  fixed_point_32_32_index += increment_by;
  
  // Shift off the 32 bits used for the fractional part, which leaves us with a 32 bit number
  // for 't', which is used as the main counter used in the equations.
  t = fixed_point_32_32_index >> 32; 
  
  // Play the selected equation
  return(this->equations->compute(equation, t, p1, p2, p3));
}