#include <Arduino.h>
#include <Ticker.h>
#include <pgmspace.h>
#include <i2s.h>
#include <i2s_reg.h>
#include <NeoPixelBus.h>
#include <ESP8266WiFi.h>
#include "lib/AudioOutputI2S.h"
#include "analogmultiplexer.h"


extern "C" {
#include "user_interface.h"
}

//DEFINE SYNTH PATCH
#include "synth/osc_delay_crush.h"
SynthTest mysynth;

// ----------------------- START CONFIG -----------------------------

//#define ENABLE_OTA
//#define ENABLE_APPLEMIDI
// note:  clicking sound when not conncted to wifi (strange)
#define ENABLE_WIFI
//#define USE_PDM

#define MULTIPLEXED_ANALOG_INPUT A0
#define MUX_A D1
#define MUX_B D2
#define MUX_C D3

//NOTE: IF EVRYTHING STARTED TO ACT WEIRD ERASE FLASH AND SKETCH FROM IDE
// (1000000 us/44100) × 5 = 113
#define USE_AUDIOBLOCK
#define NON_AUDIOBLOCK_RATE 113
#define AUDIOBLOCK_RATE 1450
#define AUDIOBLOCK_SIZE 65

#define POT_SAMPLE_RATE_MS 20

// How many leds in your strip?
//#define ENABLE_NEO_PIXEL
#define NEO_NUM_LEDS 8
#define NEO_DATA_PIN D7

#define WIFI_SSID "RUMAH"
#define WIFI_PASSWORD "rumah4321"

#define WIFI_AP_SSID "8BITMIXTAPEWIFI"
#define WIFI_AP_PASSWORD "thereisnospoon"

// ----------------------- END CONFIG -----------------------------

#ifdef ENABLE_WIFI
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#endif

#ifdef ENABLE_OTA
#include <ArduinoOTA.h>
#endif

#ifdef ENABLE_APPLEMIDI
#include "AppleMidi.h"
#endif

#include "GlobalWavetables.h"
#include "GlobalIncrements.h"


#ifdef ENABLE_NEO_PIXEL
NeoPixelBus<NeoRgbFeature, NeoEsp8266BitBang400KbpsMethod> neoPixel(NEO_NUM_LEDS, NEO_DATA_PIN);
RgbColor red(128, 0, 0);
RgbColor green(0, 128, 0);
RgbColor black(0);
#endif

AudioOutputI2S *soundOut;
AnalogMultiplexerPin multiplexer;

Ticker potTimer;

const char *ssid = WIFI_AP_SSID;
const char *password = WIFI_AP_PASSWORD;

uint16_t DAC=0x8000;
int16_t sample[2];
int16_t cycle = 0;
uint16_t potc[] = {1,1,1,1,1,1,1,1};

// Non-blocking I2S write for left and right 16-bit PCM
bool ICACHE_FLASH_ATTR i2s_write_lr_nb(int16_t left, int16_t right){
  int sample = right & 0xFFFF;
  sample = sample << 16;
  sample |= left & 0xFFFF;
  return i2s_write_sample_nb(sample);
}

#ifdef USE_PDM
//PDM From Jan Ostman
uint32_t i2sACC;
uint16_t err;

void writeDAC(uint16_t DAC) {
  for (uint8_t i=0;i<32;i++) {
    i2sACC=i2sACC<<1;
    if(DAC >= err) {
      i2sACC|=1;
      err += 0xFFFF-DAC;
    } else {
      err -= DAC;
    }
  }
  bool flag=i2s_write_sample(i2sACC);
}
#endif


//Forward declaration
void ICACHE_RAM_ATTR onTimerISR();
void onUpdateControl();

//Applemidi
#ifdef ENABLE_APPLEMIDI
APPLEMIDI_CREATE_INSTANCE(WiFiUDP, AppleMIDI); // see definition in AppleMidi_Defs.h
void OnAppleMidiControlChange(byte channel, byte note, byte value);
#endif

void setup() {

#ifdef ENABLE_WIFI
    WiFi.softAP(ssid, password);
//  WiFi.begin(ssid, pass);
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//  }
#else
    wifi_set_sleep_type(MODEM_SLEEP_T);
    delay(1);
#endif

//160MHZ clock speed
system_update_cpu_freq(160);

#ifdef ENABLE_OTA
  ArduinoOTA.begin();
#endif

#ifdef ENABLE_APPLEMIDI
  AppleMIDI.begin("ESP909"); // 'ESP909' will show up as the session name
  AppleMIDI.OnReceiveControlChange(OnAppleMidiControlChange);
#endif

  multiplexer.setup(MUX_A, MUX_B, MUX_C, MULTIPLEXED_ANALOG_INPUT);

  //Soundcard settings
  soundOut = new AudioOutputI2S();
  soundOut->SetRate(44100);
  soundOut->SetBitsPerSample(16);
  soundOut->SetChannels(2);
  soundOut->begin();
//  i2s_begin(); //Start the i2s DMA engine
//  i2s_set_rate(44100); //Set sample rate

  //Soundcard timer
  timer1_attachInterrupt(onTimerISR); //Attach our sampling ISR
  timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP);

  #ifdef USE_AUDIOBLOCK
  timer1_write(AUDIOBLOCK_RATE); //Read potentio control at AUDIOBLOCK_RATE interval
  #else
  timer1_write(NON_AUDIOBLOCK_RATE); //Read potentio control at AUDIOBLOCK_RATE interval
  #endif

  //Control timer (update pots)
  potTimer.attach_ms(POT_SAMPLE_RATE_MS, onUpdateControl); //Read potentio control at 20ms interval

  #ifdef ENABLE_NEO_PIXEL
  neoPixel.Begin();
  neoPixel.Show();
  #endif

  #ifdef USE_PDM
  pinMode(2, INPUT); //restore GPIOs taken by i2s
  pinMode(15, INPUT);
  #endif

}

void onUpdateControl() {
    potc[0] =  multiplexer.read(0,10) >> 0;
    potc[1] =  multiplexer.read(1,8) >> 0;
    potc[2] =  multiplexer.read(2,8) >> 0;
    //potc[3] =  multiplexer.read(3,10) >> 0;
    //potc[4] =  multiplexer.read(4,10) >> 0;
    //potc[5] =  multiplexer.read(5,10) >> 0;
    //potc[6] =  multiplexer.read(6,10) >> 0;
    //potc[7] =  multiplexer.read(7,10) >> 0;

    if (potc[0] < 360){
        mysynth.param[1].setValue(potc[1]);
        mysynth.param[2].setValue(potc[2]);
    }else{
        mysynth.param[3].setValue(potc[1]);
        mysynth.param[4].setValue(potc[2]);
    }

    #ifdef ENABLE_NEO_PIXEL
    for(uint8_t j =0; j < 8; j++)
    {
        if (j < 8) neoPixel.SetPixelColor(j, black);
    }

    for(uint8_t i =0; i <  ((( (DAC) >>12) - 4)<<1) ; i++)
    {
        if (i < 8) neoPixel.SetPixelColor(i, green);
    }

    neoPixel.Show();
    #endif

    //mysynth.param[3].setValue(potc[3]);
    //mysynth.param[4].setValue(potc[4]);
    //mysynth.param[5].setValue(potc[5]);
    //mysynth.param[6].setValue(potc[6]);
    //mysynth.param[7].setValue(potc[7]);
}

#ifdef ENABLE_APPLEMIDI
void OnAppleMidiControlChange(byte channel, byte note, byte value) {
    if (channel==10) {
        if (note < 5) potc[note] = value;
    }
}
#endif

void ICACHE_RAM_ATTR onTimerISR() {
        #ifdef USE_AUDIOBLOCK
        for(uint8_t i = 0; i < AUDIOBLOCK_SIZE; i++) //Bigger Audioblock, more latency
        {
            if(!i2s_is_full())
            {

                DAC = mysynth.run(i);

                #ifdef USE_PDM
                    writeDAC(DAC^0x8000);
                #else
                    sample[0] = (DAC-0x8000); //normalize
                    sample[1] = sample[0];
                    soundOut->ConsumeSample(sample); //more overhead
//                    i2s_write_lr_nb( DAC, DAC); //nicer
                #endif

            }
        }
        timer1_write(AUDIOBLOCK_RATE); // Render next block in... ms..
        #else
        //We are using realtime clock 44100 Hz
        if(!i2s_is_full())
        {
            DAC = mysynth.run(cycle++);
            #ifdef USE_PDM
                writeDAC(DAC^0x8000);
            #else
                sample[0] = (DAC-0x8000); //normalize
                sample[1] = sample[0];
                soundOut->ConsumeSample(sample); //more overhead
//                i2s_write_lr_nb( DAC, DAC); //nicer
            #endif
        }

        #endif

        //i2s_write_lr_nb((((((DAC)<<8) ^ 32768))),0); //for one liner

}

void loop() {

#ifdef ENABLE_OTA
  ArduinoOTA.handle();
#endif

#ifdef ENABLE_APPLEMIDI
  AppleMIDI.run();
#endif

}
