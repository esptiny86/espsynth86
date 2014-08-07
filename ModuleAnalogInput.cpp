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

    // The poteniometers sometimes won't be able to supply a pefect "0" value,
    // due to tolerance issues.  This code adjust the input to give us a little
    // wiggle room to get the full range.  However, as a side effect, it reduces
    // the overall knob range.

    map(this->value,10,4095,0,4095);
    this->value = constrain(this->value,0,4094);

    return(this->value);
}

// I'm not really sure why I have to redefine this 
// method and not just call the version in the base
// class?  My C++ is obviously a bit rusty.

uint16_t ModuleAnalogInput::compute()
{ 
	return(this->value);
}
