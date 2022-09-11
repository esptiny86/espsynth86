#include "ModuleAnalogInput.h"
#include "Defines.h"

ModuleAnalogInput::ModuleAnalogInput(int input_pin)
{
	this->value = 0;
	this->pin = input_pin;
}

uint32_t ModuleAnalogInput::read()
{
    // Force the ADC to settle down and concentrate, otherwise the
    // previous analogRead(..) commands on other pins will cause
    // 'crosstalk' between the input values
    analogRead(this->pin); 
    analogRead(this->pin);

    // Drop the lowest bit to reduce noise, which is present on all inputs to a 
    // certain extent.  This causes our maximum value to be 4094
    this->value = (analogRead(this->pin) >> 1) << 1;

    // The poteniometers sometimes won't be able to supply a pefect "0" value,
    // due to tolerance issues.  This code adjusts the input to give us a little
    // wiggle room to get the full range.  However, as a side effect, it reduces
    // the overall knob range.
    //
    // The map(..) function below can return negative values.  It's important 
    // to constrain those right away.  Don't try to assign those negative numbers
    // the this->value, which is unsigned and will overflow.

    this->value = constrain(map(this->value,24,4095,0,4095),0,4094);

    /*  Code for testing inputs via Serial Monitor

        if(this->pin == PIN_PRG)
        {
            Serial.print("PRG: ");
            Serial.print(this->value);
        }

        if(this->pin == PIN_SR)
        {
            Serial.print(" SR: ");
            Serial.print(this->value);
        }

        if(this->pin == PIN_MOD)
        {
            Serial.print(" MOD: ");
            Serial.println(this->value);
        }

    */

    return(this->value);
}

// I'm not really sure why I have to redefine this 
// method and not just call the version in the base
// class?  My C++ is obviously a bit rusty.

uint16_t ModuleAnalogInput::compute()
{ 
	return(this->value);
}
