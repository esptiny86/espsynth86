#include "Arduino.h"
#include "ModuleENV.h"
#include "defines.h"
#include "GlobalSlopes.h"

ModuleENV::ModuleENV()
{
	fixed_point_10_22_index = 0;

	this->triggered = false;
	this->state = ENV_INACTIVE; 
	this->env_output = 0;

	// Initialize all module inputs to NULL
	this->trigger_input = NULL;
	this->frequency_input = NULL;  
	this->slope_input = NULL;

	// Instantiate all outputs
	this->output = new ModuleOutput(this);
	this->inverted_output = new ModuleOutput(this);
	this->end_output = new ModuleOutput(this);
}

uint16_t ModuleENV::compute()
{
	uint32_t trigger = readInput(this->trigger_input);

	this->end_output->value = 0;

	if((trigger >= MID_CV) && !triggered)
	{
		triggered = true;
		state = ENV_PLAYING;
		fixed_point_10_22_index = 0;
	}

	if(trigger < MID_CV)
	{
		triggered = false;
	}

	if(state != ENV_INACTIVE)
	{
		// Read frequency input
		frequency = this->readInput(frequency_input);

		increment = map(frequency,0,4095,129236,6057);

		if((fixed_point_10_22_index + increment) > (512 << 22))
		{
			state = ENV_INACTIVE;
			fixed_point_10_22_index = 0;
			this->end_output->value = MAX_CV;
		}
		else
		{
			// Calculate the index into the slope  
			fixed_point_10_22_index += increment;
		}
	}

	if(state == ENV_PLAYING)
	{
		// Read the slope input and map it to the appropriate range
		slope = this->readInput(slope_input, 0, NUMBER_OF_SLOPES);
		slope = constrain(slope, 0, NUMBER_OF_SLOPES - 1);

		slope_index = fixed_point_10_22_index >> 22; // This should yeald a value between 0 and WAVE_SAMPLES

		// This output will range from 0 to 4095 (which is a 12-bit value)
		// The wavetable values range from 0 to 256, and the additional math
		// below scales them between 0 and 4095.  

		env_output = SLOPES[slope][slope_index] << 4;
	}

	this->output->value = env_output;
	this->inverted_output->value = 4095 - env_output;

	return(env_output);
}
