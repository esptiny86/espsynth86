#include "Defines.h"
#include "EquationBankPtah.h"

EquationBankPtah::EquationBankPtah()
{
  number_of_equations = 20;
}


uint32_t EquationBankPtah::compute2(int equation_number, uint16_t t, uint16_t p1, uint16_t p2, uint16_t p3)
{
  switch(equation_number)
  {

    case 0: // Buildup
      w2 = (((t/(p3+1)*t)%p1)&(t-t/p2*632));
      break;

    case 1: // Silent treatment
      w2 = t-t+t*p1|t&(p3+1)|t/p2;
      break;

    case 2: // Ryg's musical one-liner (with variations) - keeper, not good for looper though
      w2 = ((t*("363646292929289"[t>>13&14]&15))/p1&p2)+(((((t>>12)^(t>>12)-2)%11*t)/4|t&(t%(p3 * 100)))&63);
      break;

    case 3: // The Signs
      w2 = ((0&(251&(t/(100+p1))))|((w/t|(t/(100*(p2+1))))*(t|p3)));
      break;

    case 4: // Degraded Thumper
      w2 = (t*(p1/(t%+10))&t>>(p3>>4))&((t*(p1>>5))&t>>(p2>>5))|(t>>4&p2);
      break;

    case 5:  // BitWiz Transplant
      w2 = (t-((t&p1)*p2-1668899)*((t>>15)%15*t))>>((t>>12)%16)>>(p3%15);
      break;

    case 6:  // Derived Grit
      w2 = (w2|((t>>2)+6)+t%(p1<<3))/(((p2<<3)+1)/(p1+1))+p3;
      break;

    case 7:  // Screetchy
      w2 = (t*((t>>(p1%16)|p2>>9)&63-p3&t>>4))>>((t>>12)%15);
       break;

    case 8: // Arp Rotator
      w2 = ((t>>(p1>>4))&(t<<3)/(t*p2*(t>>11)%(3+((t>>(16-(p3>>4)))%22))));
      break;

    case 9: // Question / Answer
      w2 = ((t*(t>>8|t>>p3)&p2&t>>8))^(t&t>>p1|t>>6);
      break;

    case 10: // Magnified
      w2 = (p1&t%p3)^(t/p2);
      break;

    case 11: // Triangle Wiggler
      w = (t*(4|7&t>>13)>>((~t>>p1)&1)&p3) + ((t)*(t>>11&t>>13)*((~t>>9)&3)&p2);
      break;

    case 12: // Triangle Wiggler 2
      w = ((t>>(p1>>4))|t|t>>6)*p3+4*(t&(t>>(p2>>4))|t>>(p1>>4));
      break;

    case 13: // GGT2
      w = ((p1|(t>>(t>>13)%14))*((t>>(p1%12))-p2&249))>>((t>>13)%6)>>((p3>>4)%12);
      break;

    case 14: // Abducted
      w = (p1+t>>p2%12)|((w%(p1+t>>p1%4))+11+p3^t)>>(p3>>12);
      break;

    case 15: // My quiet friend
      w = (((t>>((p1>>12)%12))%(t>>((p2%12)+1))%(t>>((t>>(p3%10))%12)))/((t>>((p2>>2)%15))%15))<<2;
      break;

    case 16: // My loud friend
      w = (((t>>((p1>>12)%12))%(t>>((p2%12)+1))-(t>>((t>>(p3%10))%12)))/((t>>((p1>>2)%15))%15))<<4;
      break;

    case 17: // Light reactor
      w = ((t>>3)*(p1-643|(325%t|p2)&t)-((t>>6)*35/p3%t))>>6;
      break;

    case 18: // Timing master
      w = (((t>>(t>>(p2%15))%16)/((t>>((t>>(p3%15))%15))%12)+p1)*((t>>(p1%12))+15))<<4;
      break;

    case 19: // Pulse click beat - from MorphWiz, modified by Bret
      w = ((t*((50*p1)/(t%20011))&t>>(p1>>12))-((t*3)&t>>((p3>>5)%255))|(t>>4&(255-p2)));
      break;

  }


  // It might seem strange that the output is being bitshifed 4 bits - leaving 8 bits for
  // the actual output and setting the 4 LSB to 0.  I experimented with 12-bit equation
  // output and it sounded worse, not better, than the 8-bit output.  That's not because
  // 12-bit is bad, but because all of the bytebeat tools out there are tuned for 8-bits.
  // If there were some 12-bit bytebeat creation tools, things would be different.

  return(w2);
}

uint32_t EquationBankPtah::compute(int equation_number, uint32_t t, uint32_t p1, uint32_t p2, uint32_t p3)
{
  switch(equation_number)
  {
    
    case 0: // Buildup
      w = (((t/(p3+1)*t)%p1)&(t-t/p2*632)); 
      break;
      
    case 1: // Silent treatment
      w = t-t+t*p1|t&(p3+1)|t/p2;    
      break;
      
    case 2: // Ryg's musical one-liner (with variations) - keeper, not good for looper though
      w = ((t*("363646292929289"[t>>13&14]&15))/p1&p2)+(((((t>>12)^(t>>12)-2)%11*t)/4|t&(t%(p3 * 100)))&63);
      break;
      
    case 3: // The Signs
      w = ((0&(251&(t/(100+p1))))|((w/t|(t/(100*(p2+1))))*(t|p3)));
      break;
      
    case 4: // Degraded Thumper
      w = (t*(p1/(t%+10))&t>>(p3>>4))&((t*(p1>>5))&t>>(p2>>5))|(t>>4&p2);
      break;
      
    case 5:  // BitWiz Transplant
      w = (t-((t&p1)*p2-1668899)*((t>>15)%15*t))>>((t>>12)%16)>>(p3%15);
      break;
      
    case 6:  // Derived Grit
      w = (w|((t>>2)+6)+t%(p1<<3))/(((p2<<3)+1)/(p1+1))+p3;
      break;
      
    case 7:  // Screetchy
      w = (t*((t>>(p1%16)|p2>>9)&63-p3&t>>4))>>((t>>12)%15);
       break;
       
    case 8: // Arp Rotator
      w = ((t>>(p1>>4))&(t<<3)/(t*p2*(t>>11)%(3+((t>>(16-(p3>>4)))%22))));
      break;
        
    case 9: // Question / Answer
      w = ((t*(t>>8|t>>p3)&p2&t>>8))^(t&t>>p1|t>>6);
      break;
      
    case 10: // Magnified
      w = (p1&t%p3)^(t/p2);
      break;
      
    case 11: // Triangle Wiggler
      w = (t*(4|7&t>>13)>>((~t>>p1)&1)&p3) + ((t)*(t>>11&t>>13)*((~t>>9)&3)&p2);
      break; 
 
    case 12: // Triangle Wiggler 2
      w = ((t>>(p1>>4))|t|t>>6)*p3+4*(t&(t>>(p2>>4))|t>>(p1>>4));
      break;
 
    case 13: // GGT2
      w = ((p1|(t>>(t>>13)%14))*((t>>(p1%12))-p2&249))>>((t>>13)%6)>>((p3>>4)%12);
      break; 
      
    case 14: // Abducted
      w = (p1+t>>p2%12)|((w%(p1+t>>p1%4))+11+p3^t)>>(p3>>12);
      break;
      
    case 15: // My quiet friend
      w = (((t>>((p1>>12)%12))%(t>>((p2%12)+1))%(t>>((t>>(p3%10))%12)))/((t>>((p2>>2)%15))%15))<<2;
      break;  
  
    case 16: // My loud friend
      w = (((t>>((p1>>12)%12))%(t>>((p2%12)+1))-(t>>((t>>(p3%10))%12)))/((t>>((p1>>2)%15))%15))<<4;
      break;
      
    case 17: // Light reactor
      w = ((t>>3)*(p1-643|(325%t|p2)&t)-((t>>6)*35/p3%t))>>6;
      break;
      
    case 18: // Timing master
      w = (((t>>(t>>(p2%15))%16)/((t>>((t>>(p3%15))%15))%12)+p1)*((t>>(p1%12))+15))<<4;
      break;
      
    case 19: // Pulse click beat - from MorphWiz, modified by Bret
      w = ((t*((50*p1)/(t%20011))&t>>(p1>>12))-((t*3)&t>>((p3>>5)%255))|(t>>4&(255-p2)));
      break;

  }


  // It might seem strange that the output is being bitshifed 4 bits - leaving 8 bits for
  // the actual output and setting the 4 LSB to 0.  I experimented with 12-bit equation 
  // output and it sounded worse, not better, than the 8-bit output.  That's not because
  // 12-bit is bad, but because all of the bytebeat tools out there are tuned for 8-bits.
  // If there were some 12-bit bytebeat creation tools, things would be different.

  return(w);
}


