
/*
  synthesizer with potis

  Due to the fact that the ESP8266 has only one ADC a external
  multiplexer ( CD4051 ) is used to get more ADC channels.
  The multiplexer selection channels are connected to the ESP-Pins.
  Pinout see definitions below in the code.

  This sketch uses the Eqation composer files originally from
  Microbe modular
  http://www.microbemodular.com/products/equation-composer

  ************************************************************************
  This sketch is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  ********************* list of outhors **********************************

  v0.1   24.August   2018  ChrisMicro  initial version
  v0.2   30.August   2018  badgeek,    multiplexer moved to library
  v0.3   06.Novembe  2018  ChrisMicro, I2S format addapted to PT8211 I2S DAC
  v0.4   12.November 2018  ChrisMicro, I2S now supports more DACs

  It is mandatory to keep the list of authors in this code.
  Please add your name if you improve/extend something

*/

#include <Arduino.h>
#include "I2S.h"
#include "AnalogMultiplexer.h"
#include "synthx.h" // change this for other synth patch
#include "ESP8266WiFi.h" // wifi header only needed to turn it off

#define SAMPLINGFREQUENCY 44100

// multipexer select pins
#define MULTIPLEXED_ANALOG_INPUT A0
#define MUX_A D1
#define MUX_B D2
#define MUX_C D3

uint16_t potc[] = {1, 1, 1, 1, 1, 1, 1, 1};

AnalogMultiplexerPin multiplexer;

SynthTest mysynth;


I2SClass I2S;


void setup()
{
  WiFi.forceSleepBegin(); // turn of wifi to reduce power consumption

  delay(1);
  system_update_cpu_freq(160); // run MCU core with full speed

/* i2s_mode
  
  I2S audio dacs from different manufacturers need dedicated setups.

  i2s mode                     DAC
  =========================    ============================
  I2S_PHILIPS_MODE             MAS98357a,UDA1334A  
  I2S_RIGHT_JUSTIFIED_MODE,    PT8211
  I2S_PDM_MODE                 pulse density mode for direct RC-low 
                               pass connection at pin and no hardware DAC

 */
  I2S.begin(I2S_LEFT_JUSTIFIED_MODE, SAMPLINGFREQUENCY, 16);

  // synthesizer input parameters
  // usually connected to potis
  // range: 0..1024
  // this parameters can be set on the fly in the slow loop
  multiplexer.setup(MUX_A, MUX_B, MUX_C, MULTIPLEXED_ANALOG_INPUT);
}


void slowLoop()
{

  potc[0] =  multiplexer.read(0, 10) >> 0;

  if (potc[0] < 360) {
    mysynth.param[1].setValue(multiplexer.read(1, 8) >> 0);
    mysynth.param[2].setValue(multiplexer.read(2, 8) >> 0);
  } else {
    mysynth.param[3].setValue(multiplexer.read(1, 8) >> 0);
    mysynth.param[4].setValue(multiplexer.read(2, 8) >> 0);
  }

}

void loop()
{
  static uint16_t counter = 0;
  static int16_t cycle = 0;
  int16_t value;
  int16_t dacLeft, dacRight;

  //get new synthesizer sample and
  //convert to zero line centered signed value
  value = (int32_t)mysynth.run(cycle++) - 0x8000; 

  dacLeft = value;
  dacRight = value;
  
  I2S.write(dacLeft, dacRight);

  counter++;

  if (counter > SAMPLINGFREQUENCY / 250)
  {
    counter = 0;
    slowLoop();
  }


}


