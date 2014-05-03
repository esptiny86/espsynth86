#include "SynthMumbler.h"

SynthMumbler::SynthMumbler(Inputs *inputs)
{
	ModuleSpeechSound *speech_sound = new ModuleSpeechSound();

	speech_sound->pitch_input         = inputs->sr;
	speech_sound->sound_input         = inputs->mod;
	speech_sound->formant_scale_input = inputs->param2;

	this->last_module = speech_sound;
}
