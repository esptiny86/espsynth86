#include "Arduino.h"
#include "ModuleCAOsc.h"
#include "Defines.h"

ModuleCAOsc::ModuleCAOsc()
{
  output = 32768;
  last_output = 32768;

  ca_rules = { 0, 1, 1, 0, 1, 0, 0, 1 };
}

uint16_t ModuleCAOsc::compute()
{
  // Calculate next output
  for(uint8_t i=0; i<16; i++)
  {
    uint8_t a = ((i-1)%16);
    uint8_t b = i;
    uint8_t c = ((i+1)%16);

    uint8_t mask = (bitRead(last_output,c) << 2) +  (bitRead(last_output,b) << 1) + bitRead(last_output,a);

    bitWrite(output, i, ca_rules[mask]);
  }

  last_output = output;

  return(output);
}
