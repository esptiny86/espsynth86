#include <Arduino.h>
#include <Ticker.h>
#include <pgmspace.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <i2s.h>
#include <i2s_reg.h>
#include "lib/AudioOutputI2S.h"
#include "analogmultiplexer.h"
#include "synthtest.h"

#define ENABLE_OTA
//#define ENABLE_APPLEMIDI
#define ENABLE_WIFI
//#define USE_PDM

#ifdef ENABLE_OTA
#include <ArduinoOTA.h>
#endif

#ifdef ENABLE_APPLEMIDI
#include "AppleMidi.h"
#endif

#include "GlobalWavetables.h"
#include "GlobalIncrements.h"

extern "C" {
#include "user_interface.h"
}

SynthTest mysynth;

#define MUX_A D2
#define MUX_B D1
#define MUX_C D0
#define MULTIPLEXED_ANALOG_INPUT A0

#define AUDIOBLOCK_RATE 1450
#define AUDIOBLOCK_SIZE 65

AudioOutputI2S soundOut;
AnalogMultiplexerPin multiplexer;

char ssid[] = "RUMAH"; //  your network SSID (name)
char pass[] = "rumah4321";    // your network password (use for WPA, or use as key for WEP)


uint8_t phase=0; //Sine phase counter
int16_t sample[2];

uint32_t i2sACC;
uint8_t i2sCNT=32;
uint16_t DAC=0x8000;
uint16_t err;

int pot = 1;
Ticker potTimer;

uint32_t t = 0;
uint32_t tc = 0;
uint8_t snd = 0;


// Non-blocking I2S write for left and right 16-bit PCM
bool ICACHE_FLASH_ATTR i2s_write_lr_nb(int16_t left, int16_t right){
  int sample = right & 0xFFFF;
  sample = sample << 16;
  sample |= left & 0xFFFF;
  return i2s_write_sample_nb(sample);
}

#ifdef USE_PDM
//PDM From Jan Ostman
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


uint16_t potc[] = {1,1,1,1,1,1,1,1};

//uint16_t sine2[256] = {
//0x0000, 0x0324, 0x0647, 0x096a, 0x0c8b, 0x0fab, 0x12c8, 0x15e2,
//0x18f8, 0x1c0b, 0x1f19, 0x2223, 0x2528, 0x2826, 0x2b1f, 0x2e11,
//0x30fb, 0x33de, 0x36ba, 0x398c, 0x3c56, 0x3f17, 0x41ce, 0x447a,
//0x471c, 0x49b4, 0x4c3f, 0x4ebf, 0x5133, 0x539b, 0x55f5, 0x5842,
//0x5a82, 0x5cb4, 0x5ed7, 0x60ec, 0x62f2, 0x64e8, 0x66cf, 0x68a6,
//0x6a6d, 0x6c24, 0x6dca, 0x6f5f, 0x70e2, 0x7255, 0x73b5, 0x7504,
//0x7641, 0x776c, 0x7884, 0x798a, 0x7a7d, 0x7b5d, 0x7c29, 0x7ce3,
//0x7d8a, 0x7e1d, 0x7e9d, 0x7f09, 0x7f62, 0x7fa7, 0x7fd8, 0x7ff6,
//0x7fff, 0x7ff6, 0x7fd8, 0x7fa7, 0x7f62, 0x7f09, 0x7e9d, 0x7e1d,
//0x7d8a, 0x7ce3, 0x7c29, 0x7b5d, 0x7a7d, 0x798a, 0x7884, 0x776c,
//0x7641, 0x7504, 0x73b5, 0x7255, 0x70e2, 0x6f5f, 0x6dca, 0x6c24,
//0x6a6d, 0x68a6, 0x66cf, 0x64e8, 0x62f2, 0x60ec, 0x5ed7, 0x5cb4,
//0x5a82, 0x5842, 0x55f5, 0x539b, 0x5133, 0x4ebf, 0x4c3f, 0x49b4,
//0x471c, 0x447a, 0x41ce, 0x3f17, 0x3c56, 0x398c, 0x36ba, 0x33de,
//0x30fb, 0x2e11, 0x2b1f, 0x2826, 0x2528, 0x2223, 0x1f19, 0x1c0b,
//0x18f8, 0x15e2, 0x12c8, 0x0fab, 0x0c8b, 0x096a, 0x0647, 0x0324,
//0x0000, 0xfcdc, 0xf9b9, 0xf696, 0xf375, 0xf055, 0xed38, 0xea1e,
//0xe708, 0xe3f5, 0xe0e7, 0xdddd, 0xdad8, 0xd7da, 0xd4e1, 0xd1ef,
//0xcf05, 0xcc22, 0xc946, 0xc674, 0xc3aa, 0xc0e9, 0xbe32, 0xbb86,
//0xb8e4, 0xb64c, 0xb3c1, 0xb141, 0xaecd, 0xac65, 0xaa0b, 0xa7be,
//0xa57e, 0xa34c, 0xa129, 0x9f14, 0x9d0e, 0x9b18, 0x9931, 0x975a,
//0x9593, 0x93dc, 0x9236, 0x90a1, 0x8f1e, 0x8dab, 0x8c4b, 0x8afc,
//0x89bf, 0x8894, 0x877c, 0x8676, 0x8583, 0x84a3, 0x83d7, 0x831d,
//0x8276, 0x81e3, 0x8163, 0x80f7, 0x809e, 0x8059, 0x8028, 0x800a,
//0x8000, 0x800a, 0x8028, 0x8059, 0x809e, 0x80f7, 0x8163, 0x81e3,
//0x8276, 0x831d, 0x83d7, 0x84a3, 0x8583, 0x8676, 0x877c, 0x8894,
//0x89bf, 0x8afc, 0x8c4b, 0x8dab, 0x8f1e, 0x90a1, 0x9236, 0x93dc,
//0x9593, 0x975a, 0x9931, 0x9b18, 0x9d0e, 0x9f14, 0xa129, 0xa34c,
//0xa57e, 0xa7be, 0xaa0b, 0xac65, 0xaecd, 0xb141, 0xb3c1, 0xb64c,
//0xb8e4, 0xbb86, 0xbe32, 0xc0e9, 0xc3aa, 0xc674, 0xc946, 0xcc22,
//0xcf05, 0xd1ef, 0xd4e1, 0xd7da, 0xdad8, 0xdddd, 0xe0e7, 0xe3f5,
//0xe708, 0xea1e, 0xed38, 0xf055, 0xf375, 0xf696, 0xf9b9, 0xfcdc
//};


//Forward declaration
void ICACHE_RAM_ATTR onTimerISR();
void onUpdateControl();

//Applemidi
#ifdef ENABLE_APPLEMIDI
APPLEMIDI_CREATE_INSTANCE(WiFiUDP, AppleMIDI); // see definition in AppleMidi_Defs.h
void OnAppleMidiControlChange(byte channel, byte note, byte value);
#endif

void setup() {

  //160MHZ clock speed
  system_update_cpu_freq(160);

#ifdef ENABLE_WIFI
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
#endif

#ifdef ENABLE_OTA
  ArduinoOTA.begin();
#endif

#ifdef ENABLE_APPLEMIDI
  AppleMIDI.begin("ESP909"); // 'ESP909' will show up as the session name
  AppleMIDI.OnReceiveControlChange(OnAppleMidiControlChange);
#endif

  multiplexer.setup(MUX_A, MUX_B, MUX_C, MULTIPLEXED_ANALOG_INPUT);

  //Soundcard settings
  soundOut.SetRate(44100);
  soundOut.SetBitsPerSample(16);
  soundOut.SetChannels(2);
  soundOut.begin();

  //Soundcard timer
  timer1_attachInterrupt(onTimerISR); //Attach our sampling ISR
  timer1_enable(TIM_DIV16, TIM_EDGE, TIM_SINGLE);
  timer1_write(AUDIOBLOCK_RATE); //Read potentio control at AUDIOBLOCK_RATE interval

  //Control timer (update pots)
  potTimer.attach_ms(20, onUpdateControl); //Read potentio control at 20ms interval


}

void onUpdateControl() {
    potc[0] =  multiplexer.read(0,10) >> 0;
    potc[1] =  multiplexer.read(1,10) >> 0;
    potc[2] =  multiplexer.read(2,10) >> 0;
    potc[3] =  multiplexer.read(3,10) >> 0;
    potc[4] =  multiplexer.read(4,10) >> 0;
    potc[5] =  multiplexer.read(5,10) >> 0;
    potc[6] =  multiplexer.read(6,10) >> 0;
    potc[7] =  multiplexer.read(7,10) >> 0;
    mysynth.param[0].setValue(potc[0]);
    mysynth.param[1].setValue(potc[1]);
    mysynth.param[2].setValue(potc[2]);
    mysynth.param[3].setValue(potc[3]);
    mysynth.param[4].setValue(potc[4]);
    mysynth.param[5].setValue(potc[5]);
    mysynth.param[6].setValue(potc[6]);
    mysynth.param[7].setValue(potc[7]);
}

#ifdef ENABLE_APPLEMIDI
void OnAppleMidiControlChange(byte channel, byte note, byte value) {
    if (channel==10) {
        if (note < 5) potc[note] = value;
    }
}
#endif

void ICACHE_RAM_ATTR onTimerISR() {

//    while (!(i2s_is_full())) { //Don’t block the ISR if the buffer is full
//    phase = phase + pot;
//    DAC=0x8000+sine[phase];
//    i2s_write_lr_nb(DAC^0x8000,0);
//    }
//    timer1_write(2000);//Next in 2mS

//    for(uint8_t i = 0; i < AUDIOBLOCK_SIZE; i++)
//    {
//        if(!i2s_is_full())
//        {
//            phase = phase + potc[0];
//            DAC=0x8000+sine2[phase];
//            i2s_write_lr_nb(DAC^0x8000,0);
//        }
//    }
//    timer1_write(AUDIOBLOCK_RATE);//Next in 2mS

//    while (!(i2s_is_full())) { //Don’t block the ISR if the buffer is full
//        sample[0] = sine[phase++];
//        sample[1] = 0;
//        soundOut.ConsumeSample(sample);
//    }
//    timer1_write(SOUNDTIMER_RATE);//Next in 2mS



//        while (!(i2s_is_full())) { //Don’t block the ISR if the buffer is full
//            sample[0] = sine2[phase++];
//            sample[1] = 0;
//            soundOut.ConsumeSample(sample);
//        }
//        timer1_write(AUDIOBLOCK_RATE);//Next in 2mS



        for(uint8_t i = 0; i < AUDIOBLOCK_SIZE; i++) //Bigger Audioblock, more latency
        {
            if(!i2s_is_full())
            {
//              snd =  ((t>>(potc[0]>>4))&(t<<3)/(t*potc[1]*(t>>11)%(3+((t>>(16-(potc[2]>>4)))%22))));
//              DAC = (uint16_t) ptah.compute2(potc[3], t, 1+potc[0], 1+potc[2], 1+potc[1]);
//              DAC = (t*5&t>>potc[0])|(t*3&t>>potc[1]);
//              DAC = t*(t^t+(t>>pot_control[2]|1)^(t-1280^t)>>10);
//              DAC = (t*5&t>>7)|(t*3&t>>10);
//              DAC = (t*9&t>>4|t*5&t>>7|t*3&t/1024)-1;
//              DAC = (t>>6|t|t>>(t>>potc[2]))*10+((t>>potc[3])&7);
//              DAC = (((((DAC)<<potc[0]))));
//              tc++;
//              t = tc + INCREMENTS[potc[0]];

                DAC = mysynth.run(i);

//              i2s_write_lr_nb((((((DAC)<<8) ^ 32768))),0);
//              i2s_write_lr_nb(DAC^0x8000,0);
//              phase = phase + 1;
//              int16_t  tmp2 = ((sine2[phase]^0x8000))-0x8000;
//              i2s_write_lr_nb((((((tmp2>>1)<<0)))),0);
//              int16_t  tmp = ((sine3[(tc<<2)%512]))-127;
//              i2s_write_lr_nb((((((tmp)<<8)))),0);



                //i2s_write_lr_nb( sample[0], sample[1]);

                #ifdef USE_PDM
                    writeDAC(DAC);
                #else
                    sample[0] = (DAC-0x8000); //normalize
                    sample[1] = sample[0];
                    soundOut.ConsumeSample(sample);
                #endif

            }
        }
        timer1_write(AUDIOBLOCK_RATE); // Render next block in... ms..

}

void loop() {

#ifdef ENABLE_OTA
    ArduinoOTA.handle();
#endif

#ifdef ENABLE_APPLEMIDI
  AppleMIDI.run();
#endif

}
