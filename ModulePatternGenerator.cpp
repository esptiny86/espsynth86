#include "Arduino.h"
#include "ModulePatternGenerator.h"
#include "defines.h"

ModulePatternGenerator::ModulePatternGenerator()
{
	this->step = 0;
	this->old_clock = 0;
	this->first_iteration = true;
	this->latched_cv_output = 0;
	this->latched_gate_output = 0;

	// Initialize all inputs
	this->clock_input = NULL;
	this->cv_pattern_input = NULL;
	this->gate_pattern_input = NULL;
	this->gate_density_input = NULL;  
	this->length_input = NULL; 

	// Instantiate all outputs
	this->output = new ModuleOutput(this);
	this->gate_output = new ModuleOutput(this);    
}

uint16_t ModulePatternGenerator::compute()
{

	uint32_t pattern_length = this->readInput(this->length_input, CONVERT_TO_6_BIT);
	uint32_t cv_pattern = this->readInput(this->cv_pattern_input, CONVERT_TO_9_BIT);
	uint32_t gate_pattern = this->readInput(this->gate_pattern_input, CONVERT_TO_9_BIT);
	uint32_t gate_density = this->readInput(this->gate_density_input);
	uint32_t clock = this->readInput(clock_input);

	if(first_iteration) 
	{
		first_iteration = false;
		
		cv_rand.seed(cv_pattern);
		gate_rand.seed(gate_pattern + 10);

		latched_cv_output = cv_rand.random();

		if(gate_rand.random() < gate_density)
		{
			latched_gate_output = MAX_CV;
		}
		else
		{
			latched_gate_output = 0;
		}
	}

	// Step the sequencer on the rising edge 
	if((clock > MID_CV) && (old_clock <= MID_CV))
	{
		step++;
		if(step >= pattern_length)
		{
			step = 0;
			cv_rand.seed(cv_pattern);
			gate_rand.seed(gate_pattern + 10);
		}

		latched_cv_output = cv_rand.random();

		if(gate_rand.random() < gate_density)
		{
			latched_gate_output = MAX_CV;
		}
		else
		{
			latched_gate_output = 0;
		}	
	}

	// Falling clock
	else if((clock < MID_CV) && (old_clock >= MID_CV))
	{
		latched_gate_output = 0;
	}

	old_clock = clock;

	this->output->value = latched_cv_output;
	this->gate_output->value = latched_gate_output;

	return(latched_cv_output);
}