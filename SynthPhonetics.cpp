#include "SynthPhonetics.h"

SynthPhonetics::SynthPhonetics(Inputs *inputs)
{
	ModuleVocalizer *vocalizer = new ModuleVocalizer();

	vocalizer->pitch_input         = inputs->sr;
	vocalizer->formant_scale_input = inputs->mod;
	vocalizer->param1_input        = inputs->param1;
	vocalizer->param2_input        = inputs->param2;
	vocalizer->param3_input        = inputs->param3;

	this->last_module = vocalizer;
}