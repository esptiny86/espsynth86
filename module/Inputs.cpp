#include "Inputs.h"
#include "defines.h"

Inputs::Inputs()
{
	prg = new ModuleAnalogInput(PIN_PRG);
	sr = new ModuleAnalogInput(PIN_SR);
	mod = new ModuleAnalogInput(PIN_MOD);
	param1 = new ModuleAnalogInput(PIN_PARAM_1);
	param2 = new ModuleAnalogInput(PIN_PARAM_2);
	param3 = new ModuleAnalogInput(PIN_PARAM_3);
	gate = new ModuleDigitalInput(PIN_GATE);
}

void Inputs::read()
{
	prg->read();
	sr->read();
	mod->read();
	param1->read();
	param2->read();
	param3->read();
	gate->read();
}