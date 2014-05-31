#include "Arduino.h"
#include "ModulePatternGenerator.h"
#include "defines.h"

ModulePatternGenerator::ModulePatternGenerator()
{
  this->step = 0;
  this->old_clock = 0;
  this->first_iteration = true;
  this->latched_output = 0;

  // Initialize all inputs
  this->clock_input = NULL;
  this->pattern_input = NULL;
  this->length_input = NULL;   
}

uint32_t ModulePatternGenerator::compute()
{

	uint32_t pattern_length = this->readInput(this->length_input, CONVERT_TO_6_BIT);
	uint32_t pattern = this->readInput(this->pattern_input, CONVERT_TO_9_BIT);
	uint32_t clock = this->readInput(clock_input);

	if(first_iteration) 
	{
		first_iteration = false;
		rand.seed(pattern);
		latched_output = rand.random();
	}

	// Step the sequencer on the rising edge 
	if((clock > MID_CV) && (old_clock < MID_CV))
	{
		step++;
		if(step >= pattern_length)
		{
			step = 0;
			rand.seed(pattern);
		}

		latched_output = rand.random();
	}
	old_clock = clock;

	return(latched_output);
}