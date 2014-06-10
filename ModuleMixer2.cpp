#include "ModuleMixer2.h"
#include "defines.h"

ModuleMixer2::ModuleMixer2()
{
	this->input_1 = NULL;
	this->input_2 = NULL;	
}

uint32_t ModuleMixer2::compute()
{
	// Read inputs
	uint32_t value_1 = this->readInput(input_1);
	uint32_t value_2 = this->readInput(input_2);

	return((value_1 + value_2)>>1);
}
