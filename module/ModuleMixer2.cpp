#include "ModuleMixer2.h"
#include "defines.h"

ModuleMixer2::ModuleMixer2()
{
    this->ch1 = NULL;
    this->ch2 = NULL;
}

uint16_t ModuleMixer2::compute()
{
	// Read inputs
    uint32_t value_1 = this->readInput(ch1);
    uint32_t value_2 = this->readInput(ch2);

	return((value_1 + value_2)>>1);
}
