#include "Arduino.h"
#include "ModuleADSR.h"
#include "Defines.h"
#include "Slopes.h"

#define SAMPLE_RATE 44100.0
#define SAMPLES_PER_CYCLE 512
#define SAMPLES_PER_CYCLE_FIXEDPOINT (SAMPLES_PER_CYCLE<<20)
#define TICKS_PER_CYCLE (float)((float)SAMPLES_PER_CYCLE_FIXEDPOINT/(float)SAMPLE_RATE)

ModuleADSR::ModuleADSR()
{
	fixed_point_10_22_index = 0;
/*
	for(uint32_t i=0; i < 128; i++)
	{
		float frequency = ((pow(2.0,(i-69.0)/12.0)) * 66.0);
		increments[i] = frequency * TICKS_PER_CYCLE;
	}
*/
	this->triggered = false;
	this->state = ADSR_INACTIVE; 
	this->adsr_output = 0;

	// Initialize all module inputs to NULL
	this->trigger_input = NULL;
	this->frequency_input = NULL;  
	this->slope_input = NULL;
}

uint32_t ModuleADSR::compute()
{
	uint32_t trigger = readInput(this->trigger_input);

	if((trigger >= MID_CV) && !triggered)
	{
		triggered = true;
		state = ADSR_ATTACK;
		fixed_point_10_22_index = 0;
	}

	if(trigger < MID_CV)
	{
		triggered = false;
	}

	if(state != ADSR_INACTIVE)
	{
		// Read frequency input
		frequency = this->readInput(frequency_input);

		increment = map(frequency,0,4095,129236,6057);

		if((fixed_point_10_22_index + increment) > (WAVE_SAMPLES << 22))
		{
			state = ADSR_INACTIVE;
			fixed_point_10_22_index = 0;

			return(adsr_output);
		}
		else
		{
			// Calculate the index into the slope  
			fixed_point_10_22_index += increment;
		}
	}
	else
	{
		return(0);
	}

	// Read the wavetable input and map it to the appropriate range
	slope = this->readInput(slope_input, 0, NUMBER_OF_SLOPES);
	slope = constrain(slope, 0, NUMBER_OF_SLOPES - 1);

	slope_index = fixed_point_10_22_index >> 22; // This should yeald a value between 0 and WAVE_SAMPLES

	// This output will range from 0 to 4095 (which is a 12-bit value)
	// The wavetable values range from 0 to 256, and the additional math
	// below scales them between 0 and 4095.  

	adsr_output = SLOPES[slope][slope_index] << 4;

	return(adsr_output);
}
