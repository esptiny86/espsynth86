/*
  Arduino I2S compatible wrapper for ESP8266 and ESP32

  https://www.arduino.cc/en/Reference/I2S


  ************************************************************************
  This sketch is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  ********************* list of authors **********************************


  v0.1   7. November 2018  ChrisMicro,  initial version
  v0.2   16.Novemeber 2018 Badgeek, Include in internal lib, fix i2s header, and rename class to SoundOutput

*/
#ifndef _I2S_H
#define _I2S_H

//https://www.arduino.cc/en/Reference/I2S

#include "Arduino.h"
#include <I2SExtended.h>
#include <i2s_reg.h>


void i2s_begin(); // Enable TX only, for compatibility
bool i2s_rxtx_begin(bool enableRx, bool enableTx); // Allow TX and/or RX, returns false on OOM error
void i2s_end();
void i2s_set_rate(uint32_t rate);//Sample Rate in Hz (ex 44100, 48000)
void i2s_set_dividers(uint8_t div1, uint8_t div2);//Direct control over output rate
float i2s_get_real_rate();//The actual Sample Rate on output
bool i2s_write_sample(uint32_t sample);//32bit sample with channels being upper and lower 16 bits (blocking when DMA is full)
bool i2s_write_sample_nb(uint32_t sample);//same as above but does not block when DMA is full and returns false instead
bool i2s_write_lr(int16_t left, int16_t right);//combines both channels and calls i2s_write_sample with the result
bool i2s_read_sample(int16_t *left, int16_t *right, bool blocking); // RX data returned in both 16-bit outputs.
bool i2s_is_full();//returns true if DMA is full and can not take more bytes (overflow)
bool i2s_is_empty();//returns true if DMA is empty (underflow)
bool i2s_rx_is_full();
bool i2s_rx_is_empty();
int16_t i2s_available();// returns the number of samples than can be written before blocking
int16_t i2s_rx_available();// returns the number of samples than can be written before blocking
void i2s_set_callback(void (*callback) (void));
void i2s_rx_set_callback(void (*callback) (void));

/* i2s_mode
  
  I2S audio dacs from different manufacturers need dedicated setups.

  i2s mode                     DAC
  =========================    ============================
  I2S_PHILIPS_MODE             MAS98357a,UDA1334A  
  I2S_RIGHT_JUSTIFIED_MODE,    PT8211
  I2S_PDM_MODE                 pulse density mode for direct RC-low 
                               pass connection at pin and no hardware DAC

 */

typedef enum 
{
  I2S_PHILIPS_MODE,            // I2S dacs: MAS98357a,  
  I2S_RIGHT_JUSTIFIED_MODE,    // PT8211 DAC uses this mode
  I2S_LEFT_JUSTIFIED_MODE,
  I2S_PDM_MODE                 // pulse density mode for direct RC-low pass connection at pin
} i2s_mode_t;

class SoundOutput 
{
  public:

    uint8_t  begin(i2s_mode_t mode, uint32_t sampleRate, uint8_t bitsPerSample); 
    void     end();

    uint32_t availableForWrite();

    void     write(int16_t data);
    void     write(int16_t leftData, int16_t rightData);

    void     write(int16_t *data, size_t size);

    void     onTransmit(void (*callback) (void)); // call back shall have "void ICACHE_RAM_ATTR" attribute 
    
    i2s_mode_t i2sMode;

};

#endif
