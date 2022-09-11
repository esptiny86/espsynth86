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
*/

#include "SoundOutput.h"

/*
void toggleLed()
{
  static boolean flag;
  flag ^= 1;
  digitalWrite(D3, flag);
}*/
uint8_t SoundOutput::begin(i2s_mode_t mode, uint32_t sampleRate, uint8_t bitsPerSample)
{
  i2sMode = mode;

  i2s_begin();
  i2s_set_rate(sampleRate);
  return true;
}

void SoundOutput::end()
{
  i2s_end();
}

void SoundOutput::onTransmit(void (*callback) (void))
{
  i2s_set_callback(callback);
}
    
void SoundOutput::write(int16_t leftData, int16_t rightData)
{
  if (i2sMode == I2S_PHILIPS_MODE)
  {
    int32_t  left,right;
    uint32_t value;

    left  = leftData;
    right = rightData;

    value = left & 0xFFFF;
    value += right << 16;

    i2s_write_sample(value);

  } else if (i2sMode == I2S_LEFT_JUSTIFIED_MODE)
  {
    int32_t left, right;
    static uint32_t oldValue;
    uint32_t value;

    left  = ((int32_t)leftData)&0xFFFF;
    right = ((int32_t)rightData)&0xFFFF;

    value  = left  << 1;
    value += right << 17;

    if (right & 0x8000) oldValue |= 1;

    i2s_write_sample(oldValue);

    oldValue = value&0xFFFFFFFE;
  }else if (i2sMode == I2S_PDM_MODE)
  {
    //******** PDM From Jan Ostman **********
    static uint32_t i2sACC;
    static uint16_t err;
    uint16_t DAC;
    DAC = ((int32_t)leftData + rightData) >> 1;
    for (uint8_t i = 0; i < 32; i++)
    {
      i2sACC = i2sACC << 1;
      if (DAC >= err) {
        i2sACC |= 1;
        err += 0xFFFF - DAC;
      } else {
        err -= DAC;
      }
    }
    i2s_write_sample(i2sACC);
    //**************************************
  }
}

void SoundOutput::write(int16_t data)
{
  write(data,data);
}


void SoundOutput::write(int16_t *data, size_t samples)
{
  for (size_t i = 0; i < samples; i++)
  {
    write(data[i]);
  }
}

uint32_t SoundOutput::availableForWrite() 
{
  return i2s_available();
}


