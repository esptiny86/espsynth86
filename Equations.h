#ifndef Equations_h
#define Equations_h

#include "Arduino.h"
#include "Module.h"
#include "FixedPointMath.h"

class Equations
{
  public:
    Equations(); // Constructor

    uint32_t compute(int equation_number, uint32_t t, uint32_t p1, uint32_t p2, uint32_t p3);

    FixedPointMath fixed_point_math;

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