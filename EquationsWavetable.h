#ifndef EquationsWavetable_h
#define EquationsWavetable_h

#include "Arduino.h"
#include "Module.h"

class EquationsWavetable
{
  public:
    EquationsWavetable(); // Constructor

    uint32_t compute(int equation_number, uint32_t t);

    // t: This is a counter which is incremented at audio rates and forms the basis
    // of the audio.  For example, 'w = t' is a simple sawtooth waveform.

  private:
    uint16_t w; // The final output of the equation
};

#endif