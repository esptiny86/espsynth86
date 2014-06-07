#include "defines.h"
#include "Equations.h"

// If you add or subtract equatitions from this list, you'll need to update 
// the NUMBER_OF_EQUATIONS constant defined in defines.h

uint32_t Equations::compute(int equation_number, uint32_t t, uint32_t p1, uint32_t p2, uint32_t p3)
{

  switch(equation_number)
  {
    
    case 0: // Arpeggiation
      p = t/(1236+p1)%128 & ((t>>(p3>>5))*232);
      q = t/(t/(500*p2) % 5 + 1)%p;
      w = (t>>q>>(p1>>5)) + (t/(t>>((p3>>5)&12))>>p);
      break;      

    case 1: // Landing Gear
      w = ((p1&t^(t>>2)%p2)&w+1393+p3);
      break;

    case 2: // Alpha
      w= (((t^(p1>>3)-456)*(p2+1))/(((t>>(p3>>3))%14)+1))+(t*((182>>(t>>15)%16))&1);
      break;
      
    case 3: // Omega
      w= (((t>>5)|(t<<((p3>>4)+1))>>4)*p1-(t/((1853>>(t>>(p2>>4))%15))&1)>>(t>>12)%6)>>4;
      break;      
      
    case 4: // Widerange
      w = (((p1^(t>>(p2>>3)))-(t>>(p3>>2))-t%(t&p2)));
      break;        

    case 5: // Toner
      w = ((t>>((t>>12)%(p3>>4)))+((p1|t)%p2))<<2;
      break;
      
    case 6: // Defender
      w = ((w-482+(w^(3456-p1)))%(p2*t>>5&(1030-(p3<<2))));
      break;

    case 7:  // Exploratorium
      w = ((t%(p1+(t%p2)))^(t>>(p3>>5)))*2;
      break;         
      
    case 8: // Filtered Triangles
      w = ((t%(512-(t*351)+16))^((t>>(p1>>5))))*(2+(t>>14)%6)|((t*p2)&(t>>(p3>>5)));
      break; 

    case 9: // Vocalizer
      w = ((t%p1>>2)&p2)*(t>>(p3>>5));
      break;

    case 10: // A bit high-frequency, but keeper anyhow
      w = (t+w+p2/p1)%(p1|t+p3);
      break;
      
    case 11: // Hooks
      w = (t&(p1+2))-(t/p2)/w/p3;
      break;
      
    case 12: // Melodic
      w = ( t* (( t>>9| t>>p1 ) & p2)) & (p3+5);
      break;  

    case 13: // Classic Downward Wiggle
      w = (t*9&t>>4|t*p1&t>>(5+ (p3>>4))|t*3&t/p2)-1;
      break;
      
    case 14: // Digital Memory
      w = (p2>>((((p1%w)+w)>>t)^(t/p3))^(p2<<2)*p1)%((t>>(p3>>4))%p1*14-t);
      break;
      
    case 15: // Modern
      w = (((t%4069)^p1+t)+(w/257)+(w/300%t)+(w/p2^t%65))%(p3*4);
      break;
      
    case 16: // Chewie
      w = (p1-(((p3+1)/t)^p1|t^922+p1))*(p3+1)/p1*((t+p2)>>p2%19);
      break;
    
    case 17: // The Smoker
      w = w^(t>>(p3>>4)) >> (t/6988*t%(p1+1))+(t<<t/(p2 * 4));
      break;
      
    case 18: // Bit Tweaker
      w = ((t/339+p1)+t/(t/4334+p2&t))+t%p3+455;
      break;
      
    case 19: // Wingless
      w = (t^p1)+p2&t-(w&t/p3)/3;
      break;
      
    case 20: // Buildup
      w = (((t/(p3+1)*t)%p1)&(t-t/p2*632)); 
      break;
      
    case 21: // Silent treatment
      w = t-t+t*p1|t&(p3+1)|t/p2;    
      break;
      
    case 22: // Ryg's musical one-liner (with variations) - keeper, not good for looper though
      w = ((t*("363646292929289"[t>>13&14]&15))/p1&p2)+(((((t>>12)^(t>>12)-2)%11*t)/4|t&(t%(p3 * 100)))&63);
      break;
      
    case 23: // The Signs
      w = ((0&(251&(t/(100+p1))))|((w/t|(t/(100*(p2+1))))*(t|p3)));
      break;
      
    case 24: // Degraded Thumper
      w = (t*(p1/(t%+10))&t>>(p3>>4))&((t*(p1>>5))&t>>(p2>>5))|(t>>4&p2);
      break;
      
    case 25:  // BitWiz Transplant
      w = (t-((t&p1)*p2-1668899)*((t>>15)%15*t))>>((t>>12)%16)>>(p3%15);
      break;
      
    case 26:  // Derived Grit
      w = (w|((t>>2)+6)+t%(p1<<3))/(((p2<<3)+1)/(p1+1))+p3;
      break;
      
    case 27:  // Screetchy
      w = (t*((t>>(p1%16)|p2>>9)&63-p3&t>>4))>>((t>>12)%15);
       break;
       
    case 28: // Arp Rotator
      w = ((t>>(p1>>4))&(t<<3)/(t*p2*(t>>11)%(3+((t>>(16-(p3>>4)))%22))));
      break;
        
    case 29: // Question / Answer
      w = ((t*(t>>8|t>>p3)&p2&t>>8))^(t&t>>p1|t>>6);
      break;
      
    case 30: // Magnified
      w = (p1&t%p3)^(t/p2);
      break;
      
    case 31: // Triangle Wiggler
      w = (t*(4|7&t>>13)>>((~t>>p1)&1)&p3) + ((t)*(t>>11&t>>13)*((~t>>9)&3)&p2);
      break; 
 
    case 32: // Triangle Wiggler 2
      w = ((t>>(p1>>4))|t|t>>6)*p3+4*(t&(t>>(p2>>4))|t>>(p1>>4));
      break;
 
    case 33: // GGT2
      w = ((p1|(t>>(t>>13)%14))*((t>>(p1%12))-p2&249))>>((t>>13)%6)>>((p3>>4)%12);
      break; 
      
    case 34: // Abducted
      w = (p1+t>>p2%12)|((w%(p1+t>>p1%4))+11+p3^t)>>(p3>>12);
      break;
      
    case 35: // My quiet friend
      w = (((t>>((p1>>12)%12))%(t>>((p2%12)+1))%(t>>((t>>(p3%10))%12)))/((t>>((p2>>2)%15))%15))<<2;
      break;  
  
    case 36: // My loud friend
      w = (((t>>((p1>>12)%12))%(t>>((p2%12)+1))-(t>>((t>>(p3%10))%12)))/((t>>((p1>>2)%15))%15))<<4;
      break;
      
    case 37: // Light reactor
      w = ((t>>3)*(p1-643|(325%t|p2)&t)-((t>>6)*35/p3%t))>>6;
      break;
      
    case 38: // Timing master
      w = (((t>>(t>>(p2%15))%16)/((t>>((t>>(p3%15))%15))%12)+p1)*((t>>(p1%12))+15))<<4;
      break;
      
    case 39: // Pulse click beat - from MorphWiz, modified by Bret
      w = ((t*((50*p1)/(t%20011))&t>>(p1>>12))-((t*3)&t>>((p3>>5)%255))|(t>>4&(255-p2)));
      break;
      
    case 40: // VAKoder - heavily modded MorphWiz path
      w = (p2^((t>>((p1>>2)%20)))+t%(43+6*(t>>(p1%12)&3^1)))/2+p3;
      break;
   
    case 41: // Membrane
      w = (t/((t+81+(p1<<4)|t)%((t*(p3+1))&(t|t)-(935+(p2<<2)))));
      break;
   
    case 42: // Pulsar
      w = (720+(45+p1|(t^1>>t-p1)/p2)*t)-(p1>>(p2>>t))&(255-p3);
      break;
   
    case 43: // Hannah
      w = ((t<<t+(t%(w>>2)-t+(p1>>4)))>>p3)+p2;
      break;
      
    case 44: // Mobius Loop
      w = ((w&p1)|(69*p2)|(p3^t))+((w%(4333-p1))>>2);
      break;
     
    case 45: // Kricket
      w = (((p1>>6)+1)^(t>>(p3>>14))/(w*((p2>>4)+1)));
      break;     
      
    case 46: // lunar lander
      w = (t+5-p2*(t&p1))*t/t%(p3+556);  
      break;

    case 47: // Foreground
      w = (t>>(p1>>4)>>t*((t>>5)%((186*p2)+1)))-p3;
      break;

    case 48: // Pins and needles
      w = t*(869-p3)<<((t+(p2<<1)&65-t)%t)%p1;
      break;

    case 49: // odd scales
      w = (3-(((1063-p3)*(t>>3))%(254&p2)))|(3-((1063*(t>>2))%(254%p1)));
      break;

    case 50: // Clickers
      w=(((570%((t>>2)%(1613+p1)))-((p2|(t>>2))>>(710-p2)))-1-p3);
      break;

    // More "solid tone" sounds  
      
    case 51: // Tone Sweeper
      w = ((t&p2&t)*p1+(t>>(p3>>6)))>>1;
      break;
      
    case 52: // Detuner
      w = ((t-p3)|t+(t+t%p1))-p2;
      break;
      
    // Special sounds  
      
    case 53: // Autodrums (p1, p2, and p3 control drum patterns)
      w = ((((SquareRoot(t%16384)<<5)&64)*(((p1<<1) >> ((t>>14)%8))&1))<<1) +  // kick
          (((random(25))*(( p2 >>((t>>10)%8))&1))&344) + // hat
          ((((random(18000)))>>7) * (( p3 >> ((t>>13)%8))&1)&422); // snare
      break;

    // Note:
    // If you add or remove equations, you need to modify the line above that looks like:
    // #define NUMBER_OF_EQUATIONS 53
  }


  // It might seem strange that the output is being bitshifed 4 bits - leaving 8 bits for
  // the actual output and setting the 4 LSB to 0.  I experimented with 12-bit equation 
  // output and it sounded worse, not better, than the 8-bit output.

  return(((uint32_t) w) << 4);
}


Equations::Equations()
{
  // Initialize some variables
  w = 0;

  for(uint32_t i = 0; i < 1024; i++) 
  { 
    Sine[i] = (uint16_t)(2048*sin(PI*(float)i/2048.0));
  } 
  
  for(uint32_t i = 0; i < 4096; i++) 
  { 
    Exp[i] = (uint16_t)(4095*exp((float)i/-512.0));
  }   
}




//
// Below are some useful fixed-point math functions.  Most of these aren't used
// in the module, but I'm including them anyhow for other people to explore. 
// Special thanks to Gaetan Ro for figuring these out.
// 

uint32_t Equations::SquareRoot(uint32_t a_nInput)
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

uint32_t Equations::exp_fix0912(uint32_t in)
{
  if(in<4096) return Exp[in];
  else return 0;
}

uint32_t Equations::sin_fix1212(uint32_t in)
{
  uint32_t out = 0;
  uint16_t x = in % 4096;
  if(x>=0 && x<1024) out = Sine[x]+0x0800;
  if(x>=1024 && x<2048) out = Sine[2047-x]+0x0800;
  if(x>=2048 && x<3072) out = -Sine[x-2048]+0x0800;
  if(x>=3072 && x<4096) out = -Sine[4095-x]+0x0800;
  if (out>=4095) out = 4095;
  return out;
}

uint32_t Equations::cos_fix1212(uint32_t in)
{
  return sin_fix1212(1024+in);
}

uint32_t Equations::square_fix1212(uint32_t in)
{
  if(in>=2048) return (in*in>>12);
  else return (((4095-in)*(4095-in))>>12);
}

uint32_t Equations::saw_fix1212(uint32_t x,uint32_t a)
{
    uint32_t f = x % 4096;

    if(f<a) f = (f<<12)/a;
    else f = 4095 - ((f-a)<<12)/(4095-a);
  if(f>4095) f =4095;
    return f;
}