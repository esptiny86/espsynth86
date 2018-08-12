#include "defines.h"
#include "EquationBankClassic.h"

EquationBankClassic::EquationBankClassic()
{
  number_of_equations = 7;
}

uint32_t EquationBankClassic::compute(int equation_number, uint32_t t, uint32_t p1, uint32_t p2, uint32_t p3)
{
  switch(equation_number)
  {
    
    case 0: // VAKoder - heavily modded MorphWiz patch
      w = (p1 * 5 & t >> 7) | (t * p2 & t >> 10);
      break;
   
    case 1: // Membrane
      w = (p1 | (t >> 9 | t >> 7)) * t & (p2 >> 11 | t >> 9);
      break;
   
    case 2: // Pulsar
      w = (p1 * 9 & t >> 4 | t * 5 & t >> 7 | p2 * 3 & t / 1024) - 1;
      break;
   
    case 3: // Hannah
      w = (t >> 6 | t | t >> (t >> 16)) * p1 + ((t >> 11)&p2);
      break;
      
    case 4: // Mobius Loop
      w = t * (t ^ t + (t >> 15 | p1) ^ (t - (1280 - p2)^t) >> 10);
      break;
     
    case 5: // Kricket
      w = ((t & 4096) ? ((t * (t ^ t % 255) | (t >> (4 + p1))) >> 1) : (t >> p2) | ((t & 8192) ? t << 2 : t));
      break;
      
    case 6: // lunar lander
      w = (t & t >> 12) * (t >> (4 + p1) | t >> (8 + p2))^t >> 6;
      break;

    case 7: // Foreground
      w = t * (((t >> 12) | (t >> (8 + p1))) & ((63 + p2) & (t >> 4)));
      break;

  }


  // It might seem strange that the output is being bitshifed 4 bits - leaving 8 bits for
  // the actual output and setting the 4 LSB to 0.  I experimented with 12-bit equation 
  // output and it sounded worse, not better, than the 8-bit output.  That's not because
  // 12-bit is bad, but because all of the bytebeat tools out there are tuned for 8-bits.
  // If there were some 12-bit bytebeat creation tools, things would be different.

  return(((uint32_t) w) << 8);
}


