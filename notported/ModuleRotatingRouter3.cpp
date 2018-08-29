#include "Arduino.h"
#include "ModuleRotatingRouter3.h"
#include "defines.h"

ModuleRotatingRouter3::ModuleRotatingRouter3()
{
	this->triggered = false;
	this->trigger = 0;
	this->rotation = 0;

	// Initialize all module inputs to NULL
	this->rotate_input = NULL;
	this->input_1 = NULL;
	this->input_2 = NULL;
	this->input_3 = NULL;

	// Instantiate all outputs
	this->output_1 = new ModuleOutput(this);
	this->output_2 = new ModuleOutput(this);
	this->output_3 = new ModuleOutput(this);
}

uint16_t ModuleRotatingRouter3::compute()
{
	uint32_t trigger = readInput(this->rotate_input);

	if((trigger >= MID_CV) && !triggered)
	{
		triggered = true;
		rotation ++;
		if (rotation == 3) rotation = 0;
	}

	if(trigger < MID_CV)
	{
		triggered = false;
	}

	switch(rotation)
	{
		case 0:
			this->output_1->value = this->readInput(this->input_1);
			this->output_2->value = this->readInput(this->input_2);
			this->output_3->value = this->readInput(this->input_3);
			break;
		case 1:
			this->output_1->value = this->readInput(this->input_2);
			this->output_2->value = this->readInput(this->input_3);
			this->output_3->value = this->readInput(this->input_1);
			break;
		case 2:
			this->output_1->value = this->readInput(this->input_3);
			this->output_2->value = this->readInput(this->input_1);
			this->output_3->value = this->readInput(this->input_2);
			break;
	}

	return(this->output_1->value);
}