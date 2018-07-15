#include "ModuleMixer3.h"
#include "defines.h"

ModuleMixer3::ModuleMixer3()
{
    this->ch1 = NULL;
    this->ch2 = NULL;
    this->ch3 = NULL;
}

uint16_t ModuleMixer3::compute()
{
	// Read inputs
    uint32_t value_1 = this->readInput(ch1);
    uint32_t value_2 = this->readInput(ch2);
    uint32_t value_3 = this->readInput(ch3);

	return((value_1 + value_2 + value_3)/3);
}
