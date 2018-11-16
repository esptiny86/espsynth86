
#include "Defines.h"
#include "ModuleWaveshaper.h"

ModuleWaveshaper::ModuleWaveshaper()
{
	// Initialize all inputs
	this->audio_input = NULL;
  this->amount_input = NULL;
}

uint32_t ModuleWaveshaper::compute()
{
  // Read inputs
  uint32_t audio = this->readInput(audio_input);
  uint32_t amount = this->readInput(amount_input); 

  uint32_t my_output = 0;

  if(amount < 3)
  {
    my_output = audio;
  }
  else
  {
    float f_amount = (float)amount / (float)2048;

    float x = ((audio + 1.0) / 2048.0) - 1.0;
    float k = 2.0 * f_amount / (1.0 - f_amount);
    float y = (1.0 + k) * x / (1+k*abs(x));

    my_output = (((y + 1.0) * 2048.0) - 1);
  }

  return(my_output);
}

