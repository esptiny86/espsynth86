Equation Composer
=================

Welcome to the Equation Composer code.  For general usage, or instructions on adding your own equations, modules, or synths, see http://www.microbemodular.com/products/equation-composer.  If you'd prefer to jump in and start reading the code, try <a href="https://github.com/clone45/EquationComposer/blob/master/EquationComposer.ino">EquationComposer.ino</a>.

In most cases, the code is grouped by file prefix.

- EquationBank[..] files contain equations that are used for the equation playback (bytebeat) style synths.
- Global[..] files contain global data used throughout the code.  These are often 'const' data types, meaning that they're stored in the Arduino Due's program memory.  Also, see defines.h.
- Module[..] files define the building blocks of the synths.
- Synth[..] files "wire together" the modules and produce the sound.  Synths are selectable via the PRG knob on the EquationComposer.
 
Let's take a look at a sample synth:

#### SynthWavetableDelay.cpp:

```
SynthWavetableDelay::SynthWavetableDelay(Inputs* inputs)
{
	// Create modules
	ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
	ModuleDelay *delay = new ModuleDelay();

	// Wire up the wavetable oscillator
	wavetable_osc->wavetable_input  = inputs->mod;
	wavetable_osc->frequency_input  = inputs->sr;

	// Put the wavetable oscillator through a delay
	delay->audio_input = wavetable_osc;
	delay->mix_input = inputs->param1;
	delay->feedback_input = inputs->param2;
	delay->length_input = inputs->param3;

	// Output the audio of the delay
	this->last_module = delay;
}
```

This is a typical synth.  Here, the audio of a wavetable synthesizer is being sent into an audio delay, then output.  This synth is composed of two modules, the <a href="https://github.com/clone45/EquationComposer/blob/master/ModuleWavetableOsc.h">ModuleWavetableOsc</a> and <a href="https://github.com/clone45/EquationComposer/blob/master/ModuleDelay.h">ModuleDelay</a>.  

Documentation explaining what each synth does is located in the synth's .h file.  For example, SynthWavetableDelay.h contains the following documentation:

```
// =============================================================================
//
// Name: SynthWavetableDelay
// Type: Audio
// Written by: Bret Truchan, 2014
//
// Description: A wavetable oscillator put through a short audio delay.
//
// SR - Sample rate of the wavetable oscillator
// MOD - Wavetable selection
// [1] - Mix (dry/wet) of the delay effect
// [2] - Delay feedback
// [3] - Delay buffer length
// GATE - not used
//
// =============================================================================
````


To learn more about each *module*, see the <a href="http://www.microbemodular.com/products/equation-composer/programming/module-reference">module reference</a>. Alternatively, each module's .h file contains documentation explaining the module's inputs and outputs, along with sample code for using the module. For example, ModuleDelay.h contains the following documentation:

```

/*
* +----------------------+
* | ModuleDelay |
* |----------------------|
* > audio_input |
* > mix_input |
* > feedback_input |
* > length_input |
* | output >
* +----------------------+
*
*/
// =============================================================================
//
// ModuleDelay is an extremely short audio delay effect with control over
// mix, feedback, and buffer length. All inputs should range from 0 to 4095.
//
// Example usage:
//
// ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
// ModuleDelay *delay = new ModuleDelay();
//
// wavetable_osc->wavetable_input = inputs->mod;
// wavetable_osc->frequency_input = inputs->sr;
//
// delay->audio_input = wavetable_osc;
// delay->mix_input = inputs->param1;
// delay->feedback_input = inputs->param2;
// delay->length_input = inputs->param3;
//
// this->last_module = delay;
//
```

