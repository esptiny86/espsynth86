/*

  synthesizer with potis

  Due to the fact that the ESP8266 has only one ADC a external
  multiplexer ( CD4051 ) is used to get more ADC channels.
  The multiplexer selection channels are connected to the ESP-Pins.
  Pinout see definitions below in the code.

  ESPSYNTH86: Affordable Open Source Audio Experimentation Device
  https://github.com/esptiny86/espsynth86

  This sketch uses the Eqation composer files originally from
  Microbe modular - http://www.microbemodular.com/products/equation-composer

  ************************************************************************
  This sketch is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  ********************* list of outhors **********************************

  v0.1   24.August.2018   ChrisMicro  initial version
  v0.2   xxOctober 2018   badgeek, multiplexer moved to library
  v0.3   5.November.2018  ChrisMicro, I2S format addapted to PT8211 I2S DAC
  v0.4   6.November 2018  dusjagr adding NEO-pixel, PDM and serial
  v0.5   6.November 2018  dusjagr adding OSC receiver
  v0.6   12.November 2018  badgeek strip down, osc receiver with/without bundle, lemur, vcv rack, list input, input manager prototype, readme

  It is mandatory to keep the list of authors in this code.
  Please add your name if you improve/extend something

*/

#include <Arduino.h>
#include <i2s.h>
#include <i2s_reg.h>
#include <WiFiUdp.h>
//#include <Adafruit_NeoPixel.h> 
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>

#include "ESP8266WiFi.h" // wifi header only needed to turn it off
#include "Vector.h"
#include "AnalogMultiplexer.h"
#include "synthx.h" // change this for other synth patch

#define SAMPLINGFREQUENCY 44100
#define MULTIPLEXED_ANALOG_INPUT A0

//esp86
// #define MUX_A D0
// #define MUX_B D1
// #define MUX_C D2

//proto badgeek
#define MUX_A D1
#define MUX_B D2
#define MUX_C D3

#define NOISE 4
#define PIN D7
#define NUM_LEDS 8
#define BRIGHTNESS 0
#define LOCAL_PORT 8888
#define OUT_PORT 9999
#define DEBUG_SERIAL
//FOR VCV RACK & LEMUR APP
#define USE_OSC_BUNDLE
//#define USE_LEMUR_APP

#define WIFI_SSID "RUMAH"
#define WIFI_PASS "rumah4321"

// A UDP instance to let us send and receive packets over UDP
WiFiUDP Udp;

const IPAddress outIp(192,168,1,36); // remote IP (not needed for receive) 192.168.43.219
 
Input_Manager inputManager;

unsigned int ledState = LOW; // LOW means led is *on*

char ssid[] = WIFI_SSID; // your network SSID (name)
char pass[] = WIFI_PASS; // your network password

//Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

extern "C" {
#include "user_interface.h"
}

//PDM From Jan Ostman
uint32_t i2sACC;
uint16_t err;

AnalogMultiplexerPin multiplexer;

SynthTest mysynth(&inputManager);


#ifdef DEBUG_SERIAL
void printInputList(Input_Manager * inputManager)
{
  Serial.println("Esptiny Available Input:"
  for(int i=0; i<inputManager->osc.size(); ++i) {
    Serial.print("Input OSC: ");
    Serial.println(inputManager->osc[i]->address);
  }
  for(int i=0; i<inputManager->pot.size(); ++i) {
    Serial.print("Input POT: ");
    Serial.println(inputManager->pot[i]->pot_index);
  } 
}
#endif

void setup()
{
  delay(1);
  system_update_cpu_freq(160); // run MCU core with full speed
  #ifdef DEBUG_SERIAL
  Serial.begin(115200);
  #endif
  
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  #ifdef DEBUG_SERIAL
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  printInputList(&inputManager);
  #endif
  
  i2s_begin();
  i2s_set_rate(SAMPLINGFREQUENCY);

  multiplexer.setup(MUX_A, MUX_B, MUX_C, MULTIPLEXED_ANALOG_INPUT);

  Udp.begin(LOCAL_PORT);
  
}


void slowLoop()
{  
  static uint8_t idx = 0;
  //skip if no pot input needed
  if (inputManager.pot.size() > 0)
  {
    //Read analog multiplexer
    inputManager.pot[idx]->setValue(multiplexer.read(inputManager.pot[idx]->pot_index,NOISE));
    //Round robin reading
    idx++;
    if (idx > (inputManager.pot.size()-1) ) idx = 0;    
  }
}

void loop()
{
  static int16_t cycle = 0;
  static uint16_t counter = 0;
  uint16_t dacValue;

  //- - - - - - - - - - - - DAC - - - - - - - - - - - - 
  dacValue = (int32_t)mysynth.run(cycle++)-0x8000;
  i2s_write_sample(dacValue << 1);  
  counter++;
  //- - - - - - - - - - - - DAC - - - - - - - - - - - - 


  #ifndef USE_OSC_BUNDLE
  //- - - - - - - - - - - - OSC - - - - - - - - - - - - 
  OSCMessage osc_msg_rcv;
  int size = Udp.parsePacket();
  if (size > 0) {
    while (size--) {
      osc_msg_rcv.fill(Udp.read());
    }
    if (!osc_msg_rcv.hasError()) {
      for(int i=0; i<inputManager.osc.size(); ++i) {
          if(osc_msg_rcv.fullMatch(inputManager.osc[i]->address, 0))
          {
            #ifdef DEBUG_SERIAL
            Serial.print(inputManager.osc[i]->address);
            Serial.print(" VAL: ");
            Serial.println(osc_msg_rcv.getInt(0));            
            #endif
            inputManager.osc[i]->setValue(osc_msg_rcv.getInt(0));
          }
      }
    } 
  }  
  //- - - - - - - - - - - - OSC - - - - - - - - - - - - 
  #else
  //- - - - - - - - - - OSC BUNDLE - - - - - - - - - - -
  OSCMessage osc_msg_rcv;
  OSCBundle osc_msg_rcv_bnd;

  int size = Udp.parsePacket();
  if (size > 0) {
    while (size--) {
      osc_msg_rcv_bnd.fill(Udp.read());
    }
    if (!osc_msg_rcv_bnd.hasError()) {
      for(int i=0; i<inputManager.osc.size(); ++i) {

          OSCMessage msg = osc_msg_rcv_bnd.getOSCMessage(0);

          if(msg.fullMatch(inputManager.osc[i]->address, 0))
          {
            #ifdef DEBUG_SERIAL
            Serial.print(inputManager.osc[i]->address);
            Serial.print(" VAL: ");
            Serial.println(msg.getFloat(0));            
            #endif
            #ifndef USE_LEMUR_APP
            inputManager.osc[i]->setValue(msg.getInt(0));
            #else
            inputManager.osc[i]->setValue(msg.getFloat(0)*1023);
            #endif
          }
      }
    } 
  }
  //- - - - - - - - - - OSC BUNDLE - - - - - - - - - - -
  #endif


  //- - - - - - - - - - - - POT - - - - - - - - - - - - 
  if (counter > SAMPLINGFREQUENCY/250)
  {
    counter = 0;
    slowLoop();
  }
  //- - - - - - - - - - - - POT - - - - - - - - - - - - 

}
