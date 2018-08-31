/*
   Tiny Synth v5
 
   David Johnson-Davies - www.technoblogy.com - 6th November 2017
   ATtiny85 @ 8MHz (internal oscillator; BOD disabled)
   
   CC BY 4.0
   Licensed under a Creative Commons Attribution 4.0 International license: 
   http://creativecommons.org/licenses/by/4.0/
*/
 
#ifndef ModuleTinySynth_h
#define ModuleTinySynth_h

#include "Module.h"
#include "ModuleOutput.h"

class ModuleTinySynth : public Module
{
  public:
    ModuleTinySynth(const char * ample);
    Module *trigger_input;
    uint16_t compute();


    ModuleOutput *ch1;
    ModuleOutput *ch2;
    ModuleOutput *ch3;
    ModuleOutput *ch4;

  private:
    bool clocked;
    uint32_t counter;

    int Scale[15] = {0,13717,14532,15397,16312,17282,0,18310,19398,20552,21774,23069,24440,25894,0};

    const int Silence = 0;
    const int Error = 0;  // Error LED on PB0

    unsigned int Acc[4] = {Silence, Silence, Silence, Silence};
    unsigned int Freqs[4] = {0, 0, 0, 0 };

    const char *Tune;

    //Globals persist throughout tune
    unsigned int NextTick = 0;
    int TunePtr = 0;
    int Octave = 0, LastIndex = 0, Duration = 4;


    // Global tick counter
    unsigned int GlobalTicks = 0;
    uint32_t phase = 0;
    uint8_t wavetable_index = 0;


};

#endif
