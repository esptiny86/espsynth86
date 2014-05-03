#include "SynthEquationPlayer.h"

SynthEquationPlayer::SynthEquationPlayer(Inputs *inputs, Equations *equations)
{
	ModuleEquationPlayer *equation_player = new ModuleEquationPlayer(equations);
  
	equation_player->equation_input    = inputs->mod;
	equation_player->sample_rate_input = inputs->sr;
	equation_player->param1_input      = inputs->param1;
	equation_player->param2_input      = inputs->param2;
	equation_player->param3_input      = inputs->param3;
	equation_player->reset_input       = inputs->gate;

	this->last_module = equation_player;
}
