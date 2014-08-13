#ifndef FixedPointMath_h
#define FixedPointMath_h

#include "Arduino.h"
#include "Module.h"

class FixedPointMath
{
  public:
    
    uint32_t SquareRoot(uint32_t a_nInput);
    uint32_t exp_fix0912(uint32_t in);
    uint32_t sin_fix1212(uint32_t in);
    uint32_t cos_fix1212(uint32_t in);
    uint32_t square_fix1212(uint32_t in);
    uint32_t saw_fix1212(uint32_t x, uint32_t a);  
};

#endif