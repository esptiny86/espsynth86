#include "SynthPatterns.h"

SynthPatterns::SynthPatterns(Inputs* inputs)
{
	ModuleQuantizer *quantizer = new ModuleQuantizer();	
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModulePatternGenerator *pattern_generator = new ModulePatternGenerator();
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
  	ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
	ModuleENV *envelope_generator = new ModuleENV();
	ModuleSampleAndHold *sample_and_hold = new ModuleSampleAndHold();
  	ModuleDelay *delay = new ModuleDelay();

	ext_clock->clock_input = inputs->gate;

	pattern_generator->cv_pattern_input = inputs->param1;
	pattern_generator->gate_pattern_input = inputs->param2;
	pattern_generator->gate_density_input = inputs->param3;
	pattern_generator->clock_input = ext_clock;
	pattern_generator->length_input = new ModuleConstant(16);

	sample_and_hold->sample_input = pattern_generator;
	sample_and_hold->trigger_input = pattern_generator->gate_output;

	quantizer->scale_input = new ModuleConstant(1);
	quantizer->cv_input = sample_and_hold;

	wavetable_osc->wavetable_input  = inputs->mod;
	wavetable_osc->frequency_input  = quantizer;

	envelope_generator->slope_input = new ModuleConstant(0);
	envelope_generator->frequency_input = new ModuleConstant(1000);
	envelope_generator->trigger_input = pattern_generator->gate_output;

	lowpass_filter->audio_input = wavetable_osc;
	lowpass_filter->cutoff_input = envelope_generator;
	lowpass_filter->resonance_input = new ModuleConstant(0);

	delay->audio_input = lowpass_filter;
	delay->mix_input = new ModuleConstant(4000);
	delay->feedback_input = new ModuleConstant(3000);
	delay->length_input = inputs->sr;

	this->last_module = delay;

}