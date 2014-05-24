#include "Arduino.h"
#include "defines.h"
#include "Synth.h"

Synth::Synth()
{
  
}

uint32_t Synth::run(double cycle)
{
  return(this->last_module->run(cycle));
}

