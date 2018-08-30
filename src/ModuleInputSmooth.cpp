#include "Arduino.h"
#include "ModuleInputSmooth.h"
#include "Defines.h"

ModuleInputSmooth::ModuleInputSmooth(Module *parent_module)
{
	this->parent_module = parent_module;
	this->value = 0;

    index = 0;         // the index of the current reading
    total = 0;         // the running total
    average = 0;       // the average 

	for (int i = 0; i < 8; i++)
	{
		readings[i] = 0;
	}
}

uint16_t ModuleInputSmooth::compute()
{
	// subtract the last reading:
	total = total - readings[index]; 

	// read from the input  
	readings[index] = parent_module->compute();

	// add the reading to the total:
	total = total + readings[index];

	// advance to the next position in the array:  
	index = index + 1;

	// if we're at the end of the array, then wrap around to the beginning
	if (index >= 8) index = 0;

	// calculate the average:
	// average = total / 8;
	average = total >> 3;

	return(average);
}