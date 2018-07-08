#include <Arduino.h>
#include <Ticker.h>
#include <pgmspace.h>
#include "lib/AudioOutputI2S.h"

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#include "AppleMidi.h"

#include <i2s.h>
#include <i2s_reg.h>

#include "analogmultiplexer.h"

#include "synthtest.h"

SynthTest mysynth;

extern "C" {
#include "user_interface.h"
}

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

//Two Complement Format Sinewave
//int16_t sine[256] = {
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

APPLEMIDI_CREATE_INSTANCE(WiFiUDP, AppleMIDI); // see definition in AppleMidi_Defs.h

// Non-blocking I2S write for left and right 16-bit PCM
bool ICACHE_FLASH_ATTR i2s_write_lr_nb(int16_t left, int16_t right){
  int sample = right & 0xFFFF;
  sample = sample << 16;
  sample |= left & 0xFFFF;
  return i2s_write_sample_nb(sample);
}

#include "EquationBankPtah.h";
#include "EquationBankKhepri.h";

EquationBankPtah ptah;
uint16_t potc[] = {1,1,1,1};

uint8_t sine3[] = 	{ 128, 129, 130, 132, 133, 135, 136, 137, 139, 140, 142, 143, 144, 146, 147, 149, 150, 151, 153, 154, 155, 157, 158, 160, 161, 162, 164, 165, 166, 168, 169, 170, 172, 173, 174, 175, 177, 178, 179, 181, 182, 183, 184, 186, 187, 188, 189, 190, 192, 193, 194, 195, 196, 197, 198, 199, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 217, 218, 219, 220, 221, 222, 222, 223, 224, 225, 226, 226, 227, 228, 228, 229, 230, 230, 231, 232, 232, 233, 233, 234, 234, 235, 235, 236, 236, 237, 237, 238, 238, 239, 239, 239, 240, 240, 240, 240, 241, 241, 241, 241, 242, 242, 242, 242, 242, 242, 242, 243, 243, 243, 243, 243, 243, 243, 243, 243, 242, 242, 242, 242, 242, 242, 242, 241, 241, 241, 241, 240, 240, 240, 240, 239, 239, 239, 238, 238, 237, 237, 236, 236, 235, 235, 234, 234, 233, 233, 232, 232, 231, 230, 230, 229, 228, 228, 227, 226, 226, 225, 224, 223, 222, 222, 221, 220, 219, 218, 217, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 199, 198, 197, 196, 195, 194, 193, 192, 190, 189, 188, 187, 186, 184, 183, 182, 181, 179, 178, 177, 175, 174, 173, 172, 170, 169, 168, 166, 165, 164, 162, 161, 160, 158, 157, 156, 154, 153, 151, 150, 149, 147, 146, 144, 143, 142, 140, 139, 137, 136, 135, 133, 132, 130, 129, 128, 126, 125, 123, 122, 120, 119, 118, 116, 115, 113, 112, 111, 109, 108, 106, 105, 104, 102, 101, 100, 98, 97, 95, 94, 93, 91, 90, 89, 87, 86, 85, 83, 82, 81, 80, 78, 77, 76, 74, 73, 72, 71, 69, 68, 67, 66, 65, 63, 62, 61, 60, 59, 58, 57, 56, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 38, 37, 36, 35, 34, 33, 33, 32, 31, 30, 29, 29, 28, 27, 27, 26, 25, 25, 24, 23, 23, 22, 22, 21, 21, 20, 20, 19, 19, 18, 18, 17, 17, 16, 16, 16, 15, 15, 15, 15, 14, 14, 14, 14, 13, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 15, 15, 15, 15, 16, 16, 16, 17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 23, 24, 25, 25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 33, 33, 34, 35, 36, 37, 38, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 56, 57, 58, 59, 60, 61, 62, 64, 65, 66, 67, 68, 69, 71, 72, 73, 74, 76, 77, 78, 80, 81, 82, 83, 85, 86, 87, 89, 90, 91, 93, 94, 95, 97, 98, 100, 101, 102, 104, 105, 106, 108, 109, 111, 112, 113, 115, 116, 118, 119, 120, 122, 123, 125, 126 };

uint16_t sine2[256] = {
0x0000, 0x0324, 0x0647, 0x096a, 0x0c8b, 0x0fab, 0x12c8, 0x15e2,
0x18f8, 0x1c0b, 0x1f19, 0x2223, 0x2528, 0x2826, 0x2b1f, 0x2e11,
0x30fb, 0x33de, 0x36ba, 0x398c, 0x3c56, 0x3f17, 0x41ce, 0x447a,
0x471c, 0x49b4, 0x4c3f, 0x4ebf, 0x5133, 0x539b, 0x55f5, 0x5842,
0x5a82, 0x5cb4, 0x5ed7, 0x60ec, 0x62f2, 0x64e8, 0x66cf, 0x68a6,
0x6a6d, 0x6c24, 0x6dca, 0x6f5f, 0x70e2, 0x7255, 0x73b5, 0x7504,
0x7641, 0x776c, 0x7884, 0x798a, 0x7a7d, 0x7b5d, 0x7c29, 0x7ce3,
0x7d8a, 0x7e1d, 0x7e9d, 0x7f09, 0x7f62, 0x7fa7, 0x7fd8, 0x7ff6,
0x7fff, 0x7ff6, 0x7fd8, 0x7fa7, 0x7f62, 0x7f09, 0x7e9d, 0x7e1d,
0x7d8a, 0x7ce3, 0x7c29, 0x7b5d, 0x7a7d, 0x798a, 0x7884, 0x776c,
0x7641, 0x7504, 0x73b5, 0x7255, 0x70e2, 0x6f5f, 0x6dca, 0x6c24,
0x6a6d, 0x68a6, 0x66cf, 0x64e8, 0x62f2, 0x60ec, 0x5ed7, 0x5cb4,
0x5a82, 0x5842, 0x55f5, 0x539b, 0x5133, 0x4ebf, 0x4c3f, 0x49b4,
0x471c, 0x447a, 0x41ce, 0x3f17, 0x3c56, 0x398c, 0x36ba, 0x33de,
0x30fb, 0x2e11, 0x2b1f, 0x2826, 0x2528, 0x2223, 0x1f19, 0x1c0b,
0x18f8, 0x15e2, 0x12c8, 0x0fab, 0x0c8b, 0x096a, 0x0647, 0x0324,
0x0000, 0xfcdc, 0xf9b9, 0xf696, 0xf375, 0xf055, 0xed38, 0xea1e,
0xe708, 0xe3f5, 0xe0e7, 0xdddd, 0xdad8, 0xd7da, 0xd4e1, 0xd1ef,
0xcf05, 0xcc22, 0xc946, 0xc674, 0xc3aa, 0xc0e9, 0xbe32, 0xbb86,
0xb8e4, 0xb64c, 0xb3c1, 0xb141, 0xaecd, 0xac65, 0xaa0b, 0xa7be,
0xa57e, 0xa34c, 0xa129, 0x9f14, 0x9d0e, 0x9b18, 0x9931, 0x975a,
0x9593, 0x93dc, 0x9236, 0x90a1, 0x8f1e, 0x8dab, 0x8c4b, 0x8afc,
0x89bf, 0x8894, 0x877c, 0x8676, 0x8583, 0x84a3, 0x83d7, 0x831d,
0x8276, 0x81e3, 0x8163, 0x80f7, 0x809e, 0x8059, 0x8028, 0x800a,
0x8000, 0x800a, 0x8028, 0x8059, 0x809e, 0x80f7, 0x8163, 0x81e3,
0x8276, 0x831d, 0x83d7, 0x84a3, 0x8583, 0x8676, 0x877c, 0x8894,
0x89bf, 0x8afc, 0x8c4b, 0x8dab, 0x8f1e, 0x90a1, 0x9236, 0x93dc,
0x9593, 0x975a, 0x9931, 0x9b18, 0x9d0e, 0x9f14, 0xa129, 0xa34c,
0xa57e, 0xa7be, 0xaa0b, 0xac65, 0xaecd, 0xb141, 0xb3c1, 0xb64c,
0xb8e4, 0xbb86, 0xbe32, 0xc0e9, 0xc3aa, 0xc674, 0xc946, 0xcc22,
0xcf05, 0xd1ef, 0xd4e1, 0xd7da, 0xdad8, 0xdddd, 0xe0e7, 0xe3f5,
0xe708, 0xea1e, 0xed38, 0xf055, 0xf375, 0xf696, 0xf9b9, 0xfcdc
};
#include "GlobalWavetables.h"
#include "GlobalIncrements.h"

void ICACHE_RAM_ATTR onTimerISR(){

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



        for(uint8_t i = 0; i < AUDIOBLOCK_SIZE; i++)
        {

            if(!i2s_is_full())
            {
//                snd =  ((t>>(potc[0]>>4))&(t<<3)/(t*potc[1]*(t>>11)%(3+((t>>(16-(potc[2]>>4)))%22))));
//                DAC = (uint16_t) ptah.compute2(potc[3], t, 1+potc[0], 1+potc[2], 1+potc[1]);
//                DAC = (t*5&t>>potc[0])|(t*3&t>>potc[1]);
                //    DAC = t*(t^t+(t>>pot_control[2]|1)^(t-1280^t)>>10);
                //    DAC = (t*5&t>>7)|(t*3&t>>10);
                //    DAC = (t*9&t>>4|t*5&t>>7|t*3&t/1024)-1;
//                    DAC = (t>>6|t|t>>(t>>potc[2]))*10+((t>>potc[3])&7);

//                DAC = (((((DAC)<<potc[0]))));

//                tc++;
//                t = tc + INCREMENTS[potc[0]];


                DAC = mysynth.run(i);

//                i2s_write_lr_nb((((((DAC)<<8) ^ 32768))),0);

//                i2s_write_lr_nb(DAC^0x8000,0);


//                    phase = phase + 1;

//                int16_t  tmp2 = ((sine2[phase]^0x8000))-0x8000;
//                i2s_write_lr_nb((((((tmp2>>1)<<0)))),0);

//                int16_t  tmp = ((sine3[(tc<<2)%512]))-127;
//                i2s_write_lr_nb((((((tmp)<<8)))),0);


                //normalize
                sample[0] = (DAC-0x8000);
                sample[1] = sample[0];
//                                i2s_write_lr_nb( sample[0], sample[1]);

                soundOut.ConsumeSample(sample);

            }
        }
        timer1_write(AUDIOBLOCK_RATE);//Next in 2mS

}


void onTimerPot()
{
    // 4 1 2 3

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


void OnAppleMidiControlChange(byte channel, byte note, byte value) {
    if (channel==10) {
        if (note < 5) potc[note] = value;
    }
}


void setup()
{

  system_update_cpu_freq(160);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }


  ArduinoOTA.begin();

  soundOut.SetRate(44100);
  soundOut.SetBitsPerSample(16);
  soundOut.SetChannels(2);
  soundOut.begin();

  multiplexer.setup(MUX_A, MUX_B, MUX_C, MULTIPLEXED_ANALOG_INPUT);

  timer1_attachInterrupt(onTimerISR); //Attach our sampling ISR
  timer1_enable(TIM_DIV16, TIM_EDGE, TIM_SINGLE);
  timer1_write(AUDIOBLOCK_RATE); //Service at 2mS intervall

  potTimer.attach_ms(20, onTimerPot);


  AppleMIDI.begin("ESP909"); // 'ESP909' will show up as the session name
  AppleMIDI.OnReceiveControlChange(OnAppleMidiControlChange);

}


void loop()
{
  ArduinoOTA.handle();
  AppleMIDI.run();
}
