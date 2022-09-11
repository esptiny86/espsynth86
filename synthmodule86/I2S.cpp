/*
  Arduino I2S compatible wrapper for ESP8266 and ESP32

  https://www.arduino.cc/en/Reference/I2S


  ************************************************************************
  This sketch is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  ********************* list of outhors **********************************


  v0.1   7. November 2018  ChrisMicro,  initial version
*/

#include "I2S.h"


uint8_t I2SClass::begin(i2s_mode_t mode, uint32_t sampleRate, uint8_t bitsPerSample)
{
  i2sMode = mode;

  i2s_begin();
  i2s_set_rate(sampleRate);
  return true;
}

void I2SClass::end()
{
  i2s_end();
}

void I2SClass::write(int16_t leftData, int16_t rightData)
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

    left  = leftData;
    right = rightData;

    value = (left << 1) & 0x1FFFE;
    value += right << 17;

    if (right & 0x8000) oldValue |= 1;

    i2s_write_sample(oldValue);

    oldValue = value;
  }
}

void I2SClass::write(int16_t data)
{
  write(data,data);
}


void I2SClass::write(int16_t *data, size_t samples)
{
  for (size_t i = 0; i < samples; i++)
  {
    write(data[i]);
  }
}

uint32_t I2SClass::availableForWrite() 
{
  return i2s_available();
}


