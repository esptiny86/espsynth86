#include "SynthPatternsFX.h"

SynthPatternsFX::SynthPatternsFX(Inputs* inputs)
{
	// Instantiate all of the modules
	ModuleQuantizer *quantizer = new ModuleQuantizer();	
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModulePatternGenerator *pattern_generator = new ModulePatternGenerator();
	ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
  	ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
	ModuleENV *envelope_generator = new ModuleENV();
	ModuleSampleAndHold *sample_and_hold = new ModuleSampleAndHold();
	ModuleDelay *delay = new ModuleDelay();
	ModuleWaveFolder *wave_folder = new ModuleWaveFolder();

	// The ext_clock input will use the gate input if there is
	// one, otherwise default to an internal 120 BPM clock.
	ext_clock->clock_input = inputs->gate;

	// Control the pattern generator from the param inputs
	pattern_generator->cv_pattern_input = inputs->sr->smooth;
	pattern_generator->gate_pattern_input = new ModuleConstant(1000);
	pattern_generator->gate_density_input = new ModuleConstant(2000);
	pattern_generator->clock_input = ext_clock;
	pattern_generator->length_input = new ModuleConstant(16);

	// Sample + Hold the pattern generator CV output with
	// the pattern generator gate output.
	sample_and_hold->sample_input = pattern_generator;
	sample_and_hold->trigger_input = pattern_generator->gate_output;

	// Quantize the output.  The SR input selects the scale
	quantizer->scale_input = new ModuleConstant(2);
	quantizer->cv_input = sample_and_hold;

	// Wire up the wavetable oscillator
	wavetable_osc->wavetable_input  = inputs->mod;
	wavetable_osc->frequency_input  = quantizer;

	// Wire up a basic envelope generator to control the LPF
	envelope_generator->slope_input = new ModuleConstant(1);
	envelope_generator->frequency_input = new ModuleConstant(3000);
	envelope_generator->trigger_input = pattern_generator->gate_output;

	// Wire up the lowpass filter with no resonance
	lowpass_filter->audio_input = wavetable_osc;
	lowpass_filter->cutoff_input = envelope_generator;
	lowpass_filter->resonance_input = new ModuleConstant(1000);

	delay->audio_input = lowpass_filter;
	delay->mix_input = inputs->param3;
	delay->length_input = new ModuleConstant(4094);
	delay->feedback_input = new ModuleConstant(3500);

	wave_folder->audio_input = delay;
	wave_folder->lower_clipping_level_input = inputs->param1;
	wave_folder->upper_clipping_level_input = inputs->param2;

	this->last_module = wave_folder;
}