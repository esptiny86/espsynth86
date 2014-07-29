#ifndef EquationBank_h
#define EquationBank_h

#include "Arduino.h"
#include "Module.h"
#include "FixedPointMath.h"

class EquationBank
{
  public:

    EquationBank();
    virtual uint32_t compute(int equation_number, uint32_t t, uint32_t p1, uint32_t p2, uint32_t p3) = 0;

    FixedPointMath fixed_point_math;
    uint8_t number_of_equations;

    int value;

    uint32_t p; // Temporary variable for use in equations
    uint32_t q; // Temporary variable for use in equations
    uint16_t w; // The final output of the equation
    
    uint32_t p1; // parameters used in equations to modify the soudn
    uint32_t p2;
    uint32_t p3;
};

#endif