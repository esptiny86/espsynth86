#include "Arduino.h"
#include "ModuleClock.h"
#include "Defines.h"

ModuleClock::ModuleClock(uint16_t bpm, int clock_division)
{
  this->counter = 0;  
  this->bpm = constrain(bpm, 0, 254);
  
  for(uint8_t bpm_i=0; bpm_i < 255; bpm_i++)
  {
    bpm_ppqn[bpm_i] = ((float)(60.0 * SAMPLE_RATE_FLOAT * clock_division)/((float)bpm_i * 96.0));
    bpm_half_ppqn[bpm_i] = bpm_ppqn[bpm_i] / 2;
  }   
}

ModuleClock::ModuleClock(uint16_t bpm)
{
  this->counter = 0;  
  this->bpm = constrain(bpm, 0, 254);
  
  for(uint8_t bpm_i=0; bpm_i < 255; bpm_i++)
  {
    bpm_ppqn[bpm_i] = ((float)(60.0 * SAMPLE_RATE_FLOAT)/((float)bpm_i * 96.0));
    bpm_half_ppqn[bpm_i] = bpm_ppqn[bpm_i] / 2;
  }  
}


uint16_t ModuleClock::compute()
{
  this->counter = this->counter + 1;

  //   If we're at the end of the clock duty,
  //   then reset the counter back to 0 and return 0  
  //
  //         _____↓
  //        |     |
  //   _____|     |

  if(this->counter == this->bpm_ppqn[bpm]) 
  {
    this->counter = 0;
    return(0);
  }
  
  // If we're 1/2 way (or more) through the clock duty,
  // then output the MAX_CV
  //
  //        ↓_____
  //        |     |
  //   _____|     |
  
  if (this->counter >= this->bpm_half_ppqn[bpm])
  {
    return(MAX_CV);
  }
  
  // If neither of the two conditions above it true,
  // then we're at the first phase of the clock duty,
  // so return 0.
  //
  //         _____
  //        |     |
  //   __↓__|     |  
  
  else
  {
    return(0);
  }
  
}
