#include "Arduino.h"
#include "ModuleExtClock.h"
#include "defines.h"

ModuleExtClock::ModuleExtClock(uint32_t bpm, int clock_division)
{
  // 'counter' is used for timing the internal clock
  this->counter = 0;  

  // 'ext_clocked' records the status (on or off) of the external clock input
  this->ext_clocked = 0;

  // 'ext_clock_count' help determine which clock mode to use: internal or external
  this->ext_clock_counter = 176400;

  // 'bpm' the beats per minute of the internal clock
  this->bpm = constrain(bpm, 0, 254);
  
  for(uint32_t bpm_i=0; bpm_i < 255; bpm_i++)
  {
    bpm_ppqn[bpm_i] = ((float)(60.0 * SAMPLE_RATE_FLOAT * clock_division)/((float)bpm_i * 96.0));
    bpm_half_ppqn[bpm_i] = bpm_ppqn[bpm_i] / 2;
  }   
}

ModuleExtClock::ModuleExtClock(uint32_t bpm)
{
  this->counter = 0;  
  this->ext_clocked = 0;  
  this->ext_clock_counter = 176400;
  this->bpm = constrain(bpm, 0, 254);

  for(uint32_t bpm_i=0; bpm_i < 255; bpm_i++)
  {
    bpm_ppqn[bpm_i] = ((float)(60.0 * SAMPLE_RATE_FLOAT)/((float)bpm_i * 96.0));
    bpm_half_ppqn[bpm_i] = bpm_ppqn[bpm_i] / 2;
  }  
}


uint32_t ModuleExtClock::compute()
{
  this->counter++;
  this->ext_clock_counter++;

  // Check value at the external clock input.  If it goes high, then
  // reset the ext_clock_counter

  uint32_t clock_input_value = this->readInput(clock_input);
  if((clock_input_value < MID_CV) && ext_clocked) ext_clocked = false;  
  if((clock_input_value >= MID_CV) && !ext_clocked) 
  {
    ext_clocked = true;
    ext_clock_counter = 0;
  }


  // If 4 seconds have passed, then switch back to the internal
  // clock generator. 176400 is 4 x 44100, which is our interrupt rate
  if(ext_clock_counter >= 176400) 
  {

    // Avoid overflow of ext_clock_counter
    ext_clock_counter = 176400;

    //   If we're at the end of the clock duty,
    //   then reset the counter back to 0 and return 0  
    //
    //         _____↓
    //        |     |
    //   _____|     |

    if(this->counter >= this->bpm_ppqn[bpm]) 
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

  // If there has been a clock pulse on the external clock input
  // recently, then passthrough the clock input and don't use
  // the internal clock generator.
  else
  {
    return(clock_input_value);
  }
}
