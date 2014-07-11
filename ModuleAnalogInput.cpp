#include "ModuleAnalogInput.h"
#include "defines.h"

ModuleAnalogInput::ModuleAnalogInput(int input_pin)
{
	this->value = 0;
	this->pin = input_pin;
}

uint32_t ModuleAnalogInput::read()
{
 
    // Drop the lowest bit to reduce noise, which is present on all inputs to a 
    // certain extent.  This causes our maximum value to be 4094
    this->value = (analogRead(this->pin) >> 1) << 1;

    return(this->value);
}

// I'm not really sure why I have to redefine this 
// method and not just call the version in the base
// class?  My C++ is obviously a bit rusty.

uint16_t ModuleAnalogInput::compute()
{ 
	return(this->value);
}
