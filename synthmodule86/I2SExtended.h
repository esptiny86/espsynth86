#ifndef _I2S_H
#define _I2S_H

//https://www.arduino.cc/en/Reference/I2S

#include "Arduino.h"
#include <I2SExtended.h>
#include <i2s_reg.h>

typedef enum 
{
  I2S_RIGHT_JUSTIFIED_MODE,
  I2S_LEFT_JUSTIFIED_MODE
} i2s_mode_t_extended;

class I2SExtended
{
  public:

    uint8_t  begin(i2s_mode_t_extended mode, uint32_t sampleRate, uint8_t bitsPerSample);
    void     end();

    uint32_t availableForWrite();

    void     write(int16_t data);
    void     write(int16_t leftData, int16_t rightData);

    void     write(int16_t *data, size_t size);

    i2s_mode_t_extended i2sMode;

};

#endif
