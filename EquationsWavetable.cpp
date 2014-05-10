// These equations gererate relatively simple waveforms

#include "Defines.h"
#include "EquationsWavetable.h"

uint32_t EquationsWavetable::compute(int equation_number, uint32_t t)
{
  equation_number = map(equation_number, 0, 4092, 0, NUMBER_OF_WAVETABLE_EQUATIONS);

  switch(equation_number)
  {
    
    case 0:
      w = t;
      break;      

    case 1:
      w = t+(t>>2)|(t%252)|(t%100);
      break;

    case 2:
      w= t+(t>>1)|(t%64)|(t%8);
      break;
      
    case 3:
      w= t+(t<<1)|(t&64)|(t%8)-(t>>2);
      break;      
      
    case 4:
      w = t+(t|64)|(t|8)-(t>>1);
      break;        

    case 5:
      w = (t>>1)|(t>>2)|((t*14)>>3);
      break;
      
    case 6:
      w = (t>>1)|(t<<3)|((t*14)>>3);
      break;

    case 7:
      w = t+(t>>1)|(t>>2);
      break;         
      
    case 8:
      w = t|(t*t)>>3;
      break; 

    case 9:
      w = t|(t*t+3)<<2;
      break;

    case 10:
      w = (t-12)|(t&t+3)<<1;
      break;
      
    case 11:
      w = 5-t|(t|99);
      break;
      
    case 12:
      w = ((t+t)%33-t);
      break;  

    case 13:
      w = ((t+t)%597-t);
      break;
      
    case 14:
      w = ((t+t)%597-t)+(t>>1);
      break;
      
    case 15:
      w = t-t*(128&t)>>1;
      break;
      
  }

  return(((uint32_t) w) << 4);
}


EquationsWavetable::EquationsWavetable()
{
  w = 0; 
}

