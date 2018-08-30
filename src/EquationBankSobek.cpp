#include "Defines.h"
#include "EquationBankSobek.h"

EquationBankSobek::EquationBankSobek()
{
  number_of_equations = 17;
}

uint32_t EquationBankSobek::compute(int equation_number, uint32_t t, uint32_t p1, uint32_t p2, uint32_t p3)
{
  switch(equation_number)
  {
    
    case 0: // VAKoder - heavily modded MorphWiz patch
      w = (p2^((t>>((p1>>2)%20)))+t%(43+6*(t>>(p1%12)&3^1)))/2+p3;
      break;
   
    case 1: // Membrane
      w = (t/((t+81+(p1<<4)|t)%((t*(p3+1))&(t|t)-(935+(p2<<2)))));
      break;
   
    case 2: // Pulsar
      w = (720+(45+p1|(t^1>>t-p1)/p2)*t)-(p1>>(p2>>t))&(255-p3);
      break;
   
    case 3: // Hannah
      w = ((t<<t+(t%(w>>2)-t+(p1>>4)))>>(p3>>10))+p2;
      break;
      
    case 4: // Mobius Loop
      w = ((w&p1)|(69*p2)|(p3^t))+((w%(4333-p1))>>2);
      break;
     
    case 5: // Kricket
      w = (((p1>>6)+1)^(t>>(p3>>14))/(w*((p2>>4)+1)));
      break;     
      
    case 6: // lunar lander
      w = (t+5-p2*(t&p1))*t/t%(p3+556);  
      break;

    case 7: // Foreground
      w = (t>>(p1>>4)>>t*((t>>5)%((186*p2)+1)))-p3;
      break;

    case 8: // Pins and needles
      w = t*(869-p3)<<((t+(p2<<1)&65-t)%t)%p1;
      break;

    case 9: // odd scales
      w = (3-(((1063-p3)*(t>>3))%(254&p2)))|(3-((1063*(t>>2))%(254%p1)));
      break;

    case 10: // Clickers
      w=(((570%((t>>2)%(1613+p1)))-((p2|(t>>2))>>(710-p2)))-1-p3);
      break;

    case 11: // Tone Sweeper
      w = ((t&p2&t)*p1+(t>>(p3>>6)))>>1;
      break;
      
    case 12: // Detuner
      w = ((t-p3)|t+(t+t%p1))-p2;
      break;
      
    case 13: // Autodrums (p1, p2, and p3 control drum patterns)
      w = ((((fixed_point_math.SquareRoot(t%16384)<<5)&64)*(((p1<<1) >> ((t>>14)%8))&1))<<1) +  // kick
          (((random(25))*(( p2 >>((t>>10)%8))&1))&344) + // hat
          ((((random(18000)))>>7) * (( p3 >> ((t>>13)%8))&1)&422); // snare
      break;

    case 14: // Burst Thinking
      w = (1099991*t&t<<(p2-t%p1)+t)>>(p3>>6);
      break;

    case 15: // Bit Futurist
      w = (((1317-p1)*t)|w/p2%t)>>(p3>>6);
      break;

    case 16: // Tinbot
      w = (t/(40+p1)*(t+t|4-(p2+20)))+(t*(p3>>5));
      break;

  }


  // It might seem strange that the output is being bitshifed 4 bits - leaving 8 bits for
  // the actual output and setting the 4 LSB to 0.  I experimented with 12-bit equation 
  // output and it sounded worse, not better, than the 8-bit output.  That's not because
  // 12-bit is bad, but because all of the bytebeat tools out there are tuned for 8-bits.
  // If there were some 12-bit bytebeat creation tools, things would be different.

  return(((uint32_t) w) << 4);
}


