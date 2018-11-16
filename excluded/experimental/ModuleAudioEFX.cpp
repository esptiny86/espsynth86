#include "Arduino.h"
#include "ModuleAudioEFX.h"
#include "Defines.h"

ModuleAudioEFX::ModuleAudioEFX(Equations *equations)
{
  audio = 0;  // Set the counter to 0
  p1 = 0;
  p2 = 0;
  p3 = 0;

  this->equations = equations;

  // Initialize all inputs
  this->equation_input = NULL;
  this->audio_input = NULL;
  this->param1_input = NULL;
  this->param2_input = NULL;
  this->param3_input = NULL;
  this->reset_input = NULL;
  this->mod_input = NULL;  
}

uint32_t ModuleAudioEFX::compute()
{

  // Read inputs
  equation = this->readInput(equation_input);
  audio = this->readInput(audio_input);
  p1 = this->readInput(param1_input, CONVERT_TO_8_BIT);    // range: 0 - 255 (2^8)
  p2 = this->readInput(param2_input, CONVERT_TO_8_BIT);    // range: 0 - 255 (2^8)
  p3 = this->readInput(param3_input, CONVERT_TO_8_BIT);    // range: 0 - 255 (2^8)

  // Play the selected equation
  return(this->equations->compute(equation, audio, p1, p2, p3));
}