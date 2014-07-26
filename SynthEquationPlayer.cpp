#include "SynthEquationPlayer.h"

SynthEquationPlayer::SynthEquationPlayer(Inputs *inputs, EquationBank *equation_bank)
{
	ModuleEquationPlayer *equation_player = new ModuleEquationPlayer(equation_bank);

	equation_player->equation_input    = inputs->mod->smooth;
	equation_player->sample_rate_input = inputs->sr->smooth;
	equation_player->param1_input      = inputs->param1->smooth;
	equation_player->param2_input      = inputs->param2->smooth;
	equation_player->param3_input      = inputs->param3->smooth;
	equation_player->reset_input       = inputs->gate;

	this->last_module = equation_player;
}
