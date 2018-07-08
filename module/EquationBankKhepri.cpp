#include "defines.h"
#include "EquationBankKhepri.h"

EquationBankKhepri::EquationBankKhepri()
{
  number_of_equations = 20;
}

uint16_t EquationBankKhepri::compute2(int equation_number, uint8_t t, uint8_t p1, uint8_t p2, uint8_t p3)
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
  }


  // It might seem strange that the output is being bitshifed 4 bits - leaving 8 bits for
  // the actual output and setting the 4 LSB to 0.  I experimented with 12-bit equation
  // output and it sounded worse, not better, than the 8-bit output.  That's not because
  // 12-bit is bad, but because all of the bytebeat tools out there are tuned for 8-bits.
  // If there were some 12-bit bytebeat creation tools, things would be different.

  return(((uint32_t) w) << 4);
}

uint32_t EquationBankKhepri::compute(int equation_number, uint32_t t, uint32_t p1, uint32_t p2, uint32_t p3)
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
  }


  // It might seem strange that the output is being bitshifed 4 bits - leaving 8 bits for
  // the actual output and setting the 4 LSB to 0.  I experimented with 12-bit equation 
  // output and it sounded worse, not better, than the 8-bit output.  That's not because
  // 12-bit is bad, but because all of the bytebeat tools out there are tuned for 8-bits.
  // If there were some 12-bit bytebeat creation tools, things would be different.

  return(((uint32_t) w) << 4);
}


