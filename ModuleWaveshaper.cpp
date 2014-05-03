
#include "Defines.h"
#include "ModuleWaveshaper.h"

ModuleWaveshaper::ModuleWaveshaper()
{
	// Initialize all inputs
	this->audio_input = NULL;
}

uint32_t ModuleWaveshaper::compute()
{
  // Read inputs
  uint32_t audio = this->readInput(audio_input);                            // audio range: 0 to 4095

  float x = ((audio + 1.0) / 2048.0) - 1.0;
  float amount = .6;
  float k = 2.0 * amount / (1.0 - amount);
  float y = (1.0 + k) * x / (1+k*abs(x));

  uint32_t my_output = (((y + 1.0) * 2048.0) - 1);

  return(my_output);
}

