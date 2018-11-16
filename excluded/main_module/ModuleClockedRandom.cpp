#include "Arduino.h"
#include "ModuleClockedRandom.h"
#include "Defines.h"

ModuleClockedRandom::ModuleClockedRandom()
{
  this->old_clock = 0;
  this->latched_output = 0;

  // Initialize all inputs
  this->clock_input = NULL;

  rand.seed(1);
}

uint16_t ModuleClockedRandom::compute()
{
	uint32_t clock = this->readInput(clock_input);

	// Step the sequencer on the rising edge 
	if((clock > MID_CV) && (old_clock < MID_CV)) latched_output = rand.random();

	old_clock = clock;

	return(latched_output);
}