
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

  v0.1   24.August.2018  ChrisMicro  initial version

  It is mandatory to keep the list of authors in this code.
  Please add your name if you improve/extend something

*/

#include <Arduino.h>
#include <i2s.h>
#include <i2s_reg.h>
#include "AnalogMultiplexer.h"
#include "synthx.h" // change this for other synth patch
#include "ESP8266WiFi.h" // wifi header only needed to turn it off

//#include <OSCMessage.h>
//#include <OSCBundle.h>
//#include <OSCData.h>

extern "C" {
#include "user_interface.h"
}


#define SAMPLINGFREQUENCY 44100

// multipexer select pins
#define MULTIPLEXED_ANALOG_INPUT A0
#define MUX_A D1
#define MUX_B D2
#define MUX_C D3

AnalogMultiplexerPin multiplexer;

SynthTest mysynth;


void setup()
{
  WiFi.forceSleepBegin(); // turn of wifi to reduce power consumption

  delay(1);
  system_update_cpu_freq(160); // run MCU core with full speed

  i2s_begin();
  i2s_set_rate(SAMPLINGFREQUENCY);

  // synthesizer input parameters
  // usually connected to potis
  // range: 0..1024
  // this parameters can be set on the fly in the slow loop

multiplexer.setup(MUX_A, MUX_B, MUX_C, MULTIPLEXED_ANALOG_INPUT);


}


void slowLoop()
{
  static uint8_t count = 0;
  mysynth.param[count].setValue(multiplexer.read(count,8));
  count++;
  if (count > 7) count = 0;
}


void loop()
{
  static int16_t cycle = 0;
  static uint16_t counter = 0;
  uint16_t dacValue;

  dacValue = mysynth.run(cycle++);
  i2s_write_sample(dacValue ^ 0x8000);

  counter++;

  if (counter > SAMPLINGFREQUENCY/250)
  {
    counter = 0;
    slowLoop();
  }


}
