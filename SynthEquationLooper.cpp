#include "SynthEquationLooper.h"

SynthEquationLooper::SynthEquationLooper(Inputs *inputs, Equations *equations)
{
	ModuleEquationLooper *equation_looper = new ModuleEquationLooper(equations);

	equation_looper->equation_input    = inputs->mod;
	equation_looper->sample_rate_input = inputs->sr;
	equation_looper->loop_start_input  = inputs->param1;
	equation_looper->loop_length_input = inputs->param2;
	equation_looper->param3_input      = inputs->param3;
	equation_looper->gate_input        = inputs->gate;

	this->last_module = equation_looper;
}
