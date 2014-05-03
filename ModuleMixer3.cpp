#include "ModuleMixer3.h"
#include "Defines.h"

ModuleMixer3::ModuleMixer3()
{
	this->input_1 = NULL;
	this->input_2 = NULL;
	this->input_3 = NULL;	
}

uint32_t ModuleMixer3::compute()
{
	// Read inputs
	uint32_t value_1 = this->readInput(input_1);
	uint32_t value_2 = this->readInput(input_2);
	uint32_t value_3 = this->readInput(input_3);

	return((value_1 + value_2 + value_3)/3);
}
