#include "Arduino.h"
#include "ModuleEqDrum.h"
#include "Defines.h"

ModuleEqDrum::ModuleEqDrum()
{
  t = 0;  // Set the counter to 0
  w = 0;  // Initialize variables used for temporary storage
  fixed_point_20_12_index = 0;
  increment_by = 2500;
  triggered = false;
  playing = false;
  
  // Prepare high pass filter
  hpf.setCutoffFreq(255);
  hpf.setResonance(0);  

  // Initialize all inputs
  this->drum_selection_input = NULL;
  this->trigger_input = NULL;
  this->sample_rate_input = NULL;    
}

uint32_t ModuleEqDrum::compute()
{

  // Read inputs
  drum_selection = this->readInput(drum_selection_input, 0, 7);
  uint32_t trigger = readInput(trigger_input);
  increment_by = this->readInput(sample_rate_input);

  if((trigger >= MID_CV) && !triggered) 
  {
    triggered = true;
    playing = true;
    fixed_point_20_12_index = 0;
    w = 0;
  }
  
  if((trigger < MID_CV) && triggered) 
  {
    triggered = false;
  }
  
  if(playing)
  {
    // shift off th 12 bits used for fractional numbers, which leaves us with a 20 bit number
    t = fixed_point_20_12_index >> 12; 
    
    switch(drum_selection)
    {
      
      case 0:  // Sqrt Kick
        w = ((SquareRoot(t%16384))<<5)&64;
        if(t > 16384) stop_playback();
        break;      

      case 1: // Tech kick
        w = (((1250&t-17)>>6%t)*40) * (t<2000); // t < 2000 is the duration
        if(t > 2000) stop_playback();
        break;
        
      case 2: // Noise Hit 1
        w = ((50&t-177)>>356%t)*20;
        if(t > 2000) stop_playback();
        break;
        
      case 3: // White noise snare drum
        // (w+t+(w>>2)) is the whitenoise sound
        // &874356 pokes some holes for it so it mixes better with other sounds
        w = (w+t+(w>>2))&874356; // Generate the sound
        if(t > 2000) stop_playback();
        break;
  
      case 4: // rolling hats
        w = (t<<t/2);
        if(!triggered) stop_playback();
        break;

      case 5: // zap kick
        w = ((1200/t)*150);
        if(t > 2000) stop_playback();
        break;
  
      case 6: // hihat
        w = (3000-(3000%t))*(23/t)*(w+t);
        if(t > 2000) stop_playback();
        break;

      case 7: // tuned hat
        w = ((t^99)/(t>>5));
        break;
    }
    
    fixed_point_20_12_index += increment_by;

  }
  
  return(w << 4);
}

uint32_t ModuleEqDrum::SquareRoot(uint32_t a_nInput)
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

uint32_t ModuleEqDrum::stop_playback()
{
  playing = false;
  w = 0;
}
