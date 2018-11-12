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
#ifndef _I2S_H
#define _I2S_H

//https://www.arduino.cc/en/Reference/I2S

#include "Arduino.h"
#include <i2s.h>
#include <i2s_reg.h>

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

class I2SClass 
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
