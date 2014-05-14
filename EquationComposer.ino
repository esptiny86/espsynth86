/*
 ___  __        __  ___ _  __           ___  __        __   __   ___  ___  __  
|___ |  | |  | |__|  |  | |  | |\ |    |    |  | |\/| |__] |  | [__  |___ |__/ 
|___ |_\| |__| |  |  |  | |__| | \|    |___ |__| |  | |    |__| ___] |___ |  \ 
// =============================================================================
       
Copyright 2014 Bret Truchan

  The Equation Composer source code is free software: you can redistribute it 
  and/or modify it under the terms of the GNU General Public License as 
  published by the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
                                                                       
Based on:
  http://rcarduino.blogspot.com/2012/12/arduino-due-dds-part-1-sinewaves-and.html
  Equation playback based on techniques documented by Viznut

Credits:
  Circuit design, parts selection, and manufacturing oversight by John Staskevich
  Front panel design by Hannes Pasqualini
  Sound design by Sunshine Audio and Bret Truchan
  Some equations gathered from around the net for which there was no attribution
  Includes some libraries from Mozzi (http://sensorium.github.io/Mozzi/)
  Additional programming by Gaétan Ro
  Thanks to Ivan Seidel Gomes for creating the Due Timer library
  Significant parts of the circuitry come directly from the Arduino Due Reference Design
  Special thanks to Josh from Toppobrillo for his support and mentoring

Equation testing tools:
  http://wurstcaptures.untergrund.net/music/
  http://entropedia.co.uk/generative_music/
  http://dev.fritzu.com/bbx/
  
  Note: When using any bytebeat tool, make sure to set the output rate to 44,100  

TODO:
  - change map function to not map constant inputs
  - create add/subtract module
  - consider splitting ModuleLFO into: ModuleLFO(int rate) and ModuleVCLFO() 
  - use better datatypes than the uint32_t that I use everywhere out of laziness
  
Programming notes
  - Do _not_ put a delay() immediately before polling the analog inputs as it can
    cause inaccuracies in the voltage readings.  (Perhaps a bug in the Arduino
    implementation of delay()?)
  
  
// =========================== - 80 column - ===================================
12345678901234567890123456789012345678901234567890123456789012345678901234567890

*/


#include "defines.h"

// Setting the debug flag to 1 turns off the timer functions.  This causes the
// code to run slowly, and at that slow frequency the module is inaudible.  
// However, it does allow for us to add Serial.println() calls within the code, 
// which normally woudn't work because the interrupt code gets called at
// a higher frequency than the serial port can function.
//
// So, in other words, if you want to use Serial.println(), uncomment this line
// but don't expect to hear any audio output from the module.
//
// #define DEBUG 1


// Equations.h is a class that holds a majority of the equations used in this 
// module.  If you want to add an equation, Equations.cpp is the place to do it.
#include "Equations.h"

// EquationsWavetable.h holds a small batch of equations that produce waveforms
// that are similar to wavetables.
#include "EquationsWavetable.h"

// More traditional array-based wavetables
#include "Wavetables.h"

// Include each synth
#include "SynthArp1.h"
#include "SynthAutoDrum.h"
#include "SynthDrumPlayer.h"
#include "SynthEquationPlayer.h"
#include "SynthEquationLooper.h"
#include "SynthEqWave.h"
#include "SynthSoundToy.h"
#include "SynthSubtractor.h"
#include "SynthPassthroughTest.h"
#include "SynthPhonetics.h"
#include "SynthVerbalizer.h"
#include "SynthWavetable.h"

#include "SynthTutorial1.h"
#include "SynthTutorial2.h"
#include "SynthTutorial3.h"
#include "SynthDrumSelektor.h"

#include "DueTimer.h"

  
// Global variables

// Create an inputs object, which contains a bunch of input modules and serves
// as a convienient wrapper class.
Inputs *inputs = new Inputs();

// Since there are a lot of equations to share among modules, they've
// been put into their own class, which is passed through to the 
// modules that need access to them.
// * Equations contains all of the core equations (the fun stuff)
// * EquationsWavetable contains simpler equations good for generating wavetables
Equations *equations = new Equations();
EquationsWavetable *equations_wavetable = new EquationsWavetable();


// Instantiate synths which are selectable via the PRG knob
// Any new synth must be added to this list

#define NUMBER_OF_SYNTHS 5

Synth *active_synths[] {
  new SynthEquationPlayer(inputs, equations),
  new SynthEquationLooper(inputs, equations),
  new SynthEqWave(inputs, equations),
  new SynthDrumSelektor(inputs),
  new SynthWavetable(inputs)
};



// The 'cycle' variable increments every time the 44100Hz interrupt is called.
// Modules use this counter to determine if their output has already been calculated
// or not during the interrupt cycle.  If it has, then the module won't bother
// calculating its output until the next cycle.  This is important for situations
// where one module's output is fed into the inputs of two different modules.  Without
// this type of "output caching", in this situation, the parent module's code
// would be run twice unnecessarily.
double cycle = 0;

// Currently selected synth
int synth = 0;


void setup()
{
    
  // A note about using Serial.println() for testing:
  // Testing using Serial.println() is difficult because you can't put a 
  // Serial.println() in the code that's called by the timer interrupt.  The only 
  // way I've been able to use Serial.println() is by temporarily removing the 
  // timer and by calling the TC4_Handler() function myself from within the main loop.
  // Using the DEBUG flag does just that.  It disabled the interrupt and instead
  // calls TC4_Handler from the main loop().
  
  #ifdef DEBUG
    Serial.begin(9600);
  #endif
  
  // Set the Due's analog read resolution
  analogReadResolution(ANALOG_READ_RESOLUTION);
  
  // Enable the DAC
  analogWrite(DAC1,0);

  // Set the pinmode for digital pins.  This is not required for the analog inputs.
  pinMode(PIN_GATE, INPUT);

  // Configure the interrupt(s) if NOT in debug mode.  
  // Notice that's ifndef (with an 'n'), not ifdef.
  #ifndef DEBUG
    Timer0.attachInterrupt(audioRateInterrupt).setFrequency(44100).start();
  #endif
  
}

void loop()
{  
  // In the main loop, the analog and digital inputs are read. The values are 
  // stored in the global input modules as well as being returned.  It wouldn't
  // make sense to poll the Arduino inputs in the timer function TC4_Handler()
  // because that function gets called at a higher frequency than the analog
  // inputs can be read (I'm assuming!).  That's why they're polled here, in
  // the main loop, at a reasonable rate.

  inputs->read();

  synth = map(inputs->prg->getValue(), 0, MAX_CV, 0, NUMBER_OF_SYNTHS);

  // If in debug mode, then call the audio_rate_interrupt manually
  #ifdef DEBUG
    audioRateInterrupt();
  #endif
}

// This method gets called at around 44100 Hz
void audioRateInterrupt()
{
  // I'm using dacc_write_conversion_data() because it writes 12-bit data to
  // the DAC as opposed to 8-bit resolution that analogWrite() does.
  dacc_write_conversion_data(DACC_INTERFACE, active_synths[synth]->run(cycle));
  
  // Increment the global time.  This variable is used by modules in their
  // output caching code. (see Module.cpp)
  cycle++;
}

