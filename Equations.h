#ifndef Equations_h
#define Equations_h

#include "Arduino.h"
#include "Module.h"

class Equations
{
  public:
    Equations(); // Constructor

    uint32_t compute(int equation_number, uint32_t t, uint32_t p1, uint32_t p2, uint32_t p3);

    // t: This is a counter which is incremented at audio rates and forms the basis
    // of the audio.  For example, 'w = t' is a simple sawtooth waveform.
    // 
    // p1, p2, p3: These are the values at the inputs [1],[2], and [3] of the module.
    // They are used to tweak the equations for different sounding output.
    
    // Supporting fixed point math functions
    uint32_t SquareRoot(uint32_t a_nInput);
    uint32_t exp_fix0912(uint32_t in);
    uint32_t sin_fix1212(uint32_t in);
    uint32_t cos_fix1212(uint32_t in);
    uint32_t square_fix1212(uint32_t in);
    uint32_t saw_fix1212(uint32_t x,uint32_t a);

  private:
    int value;
    uint32_t p; // Temporary variable for use in equations
    uint32_t q; // Temporary variable for use in equations
    uint16_t w; // The final output of the equation
    
    uint32_t p1; // parameters used in equations to modify the soudn
    uint32_t p2;
    uint32_t p3;

    uint16_t Sine[1024];
    uint16_t Exp[4095];    

};

#endif