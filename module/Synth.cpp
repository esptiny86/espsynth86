#include "Arduino.h"
#include "defines.h"
#include "Synth.h"

uint16_t Synth::run(uint8_t cycle)
{
  return(this->last_module->run(cycle));
}

