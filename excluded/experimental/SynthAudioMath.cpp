#include "SynthAudioMath.h"

SynthAudioMath::SynthAudioMath(Inputs *inputs, Equations *equations)
{
	ModuleAudioEFX *audio_efx = new ModuleAudioEFX(equations);
  
	audio_efx->equation_input = inputs->mod;
	audio_efx->audio_input    = inputs->sr;
	audio_efx->param1_input   = inputs->param1;
	audio_efx->param2_input   = inputs->param2;
	audio_efx->param3_input   = inputs->param3;
	audio_efx->reset_input    = inputs->gate;

	this->last_module = audio_efx;
}