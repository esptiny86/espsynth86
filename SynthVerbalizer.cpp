#include "SynthVerbalizer.h"

SynthVerbalizer::SynthVerbalizer(Inputs *inputs)
{
	ModuleWords *words = new ModuleWords();
 
	words->sound_input = inputs->mod;
	words->param1_input = inputs->param1;
	words->param2_input = inputs->param2;
	words->param3_input = inputs->param3;
	words->pitch_input = inputs->sr;

	this->last_module = words;
}