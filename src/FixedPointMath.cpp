#include "Defines.h"
#include "FixedPointMath.h"
#include "GlobalFixedPointMathTables.h"

//
// Below are some useful fixed-point math functions.  Most of these aren't used
// in the module, but I'm including them anyhow for other people to explore. 
// Special thanks to Gaetan Ro for figuring these out.
// 

uint32_t FixedPointMath::SquareRoot(uint32_t a_nInput)
{
    uint32_t op  = a_nInput;
    uint32_t res = 0;
    uint32_t one = 1uL << 30; // The second-to-top bit is set: use 1u << 14 for uint16_t type; use 1uL<<30 for uint32_t type


    // "one" starts at the highest power of four <= than the argument.
    while (one > op)
    {
        one >>= 2;
    }

    while (one != 0)
    {
        if (op >= res + one)
        {
            op = op - (res + one);
            res = res +  2 * one;
        }
        res >>= 1;
        one >>= 2;
    }
    return res;
}

uint32_t FixedPointMath::exp_fix0912(uint32_t in)
{
  if(in<4096) return fixed_point_exp[in];
  else return 0;
}

uint32_t FixedPointMath::sin_fix1212(uint32_t in)
{
  uint32_t out = 0;
  uint16_t x = in % 4096;
  if(x>=0 && x<1024) out = fixed_point_sin[x]+0x0800;
  if(x>=1024 && x<2048) out = fixed_point_sin[2047-x]+0x0800;
  if(x>=2048 && x<3072) out = -fixed_point_sin[x-2048]+0x0800;
  if(x>=3072 && x<4096) out = -fixed_point_sin[4095-x]+0x0800;
  if (out>=4095) out = 4095;
  return out;
}

uint32_t FixedPointMath::cos_fix1212(uint32_t in)
{
  return sin_fix1212(1024+in);
}

uint32_t FixedPointMath::square_fix1212(uint32_t in)
{
  if(in>=2048) return (in*in>>12);
  else return (((4095-in)*(4095-in))>>12);
}

uint32_t FixedPointMath::saw_fix1212(uint32_t x,uint32_t a)
{
  uint32_t f = x % 4096;

  if(f<a) f = (f<<12)/a;
  else f = 4095 - ((f-a)<<12)/(4095-a);
  if(f>4095) f =4095;
  return f;
}