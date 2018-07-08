#include "Arduino.h"
#include "ModuleEquationPlayer.h"
#include "defines.h"

ModuleEquationPlayer::ModuleEquationPlayer(EquationBank *equation_bank)
{
  t = 0;  // Set the counter to 0
  p1 = 0;
  p2 = 0;
  p3 = 0;
  old_reset = false;  
  reset = 0;
  fixed_point_32_32_index = 0;

  this->equation_bank = equation_bank;

  // Initialize all inputs
  this->equation_input = NULL;
  this->sample_rate_input = NULL;
  this->param1_input = NULL;
  this->param2_input = NULL;
  this->param3_input = NULL;
  this->reset_input = NULL;
}

uint16_t ModuleEquationPlayer::compute()
{

  // Read inputs
//  equation = this->readInput(equation_input, 0, equation_bank->number_of_equations);
//  increment_by = this->readInput(sample_rate_input);       // range: 0 - 4095
//  p1 = this->readInput(param1_input);    // range: 0 - 255 (2^8)
//  p2 = this->readInput(param2_input);    // range: 0 - 255 (2^8)
//  p3 = this->readInput(param3_input);    // range: 0 - 255 (2^8)
  equation = 1;
//  p1 = 100 + p1;
  p1 = 1;
  p2 = 10;
  p3 = 5;
//  increment_by = 1;
//  reset = this->readInput(reset_input);

//  increment_by = increment_by << 21;

  // If the reset input transitions from low to high, then reset fixed_point_20_12_index 
  // to 0, which effectively restarts the sound.  MID_CV is defined in defines.h
//  if((reset >= MID_CV) && !old_reset)
//  {
//    old_reset = true;
//    fixed_point_32_32_index = 0;
//  }
  
//  if(reset < MID_CV) old_reset = false;
  
  
//  fixed_point_32_32_index += increment_by;
  
  // Shift off the 32 bits used for the fractional part, which leaves us with a 32 bit number
  // for 't', which is used as the main counter used in the equations.
//  t = fixed_point_32_32_index >> 32;
    t++;
  // Play the selected equation
  return(this->equation_bank->compute(equation, t, p1, p2, p3)^0x8000);
}
