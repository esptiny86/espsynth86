#include "Arduino.h"
#include "ModuleEqDrum.h"
#include "Defines.h"

ModuleEqDrum::ModuleEqDrum()
{
  t = 0;  // Set the counter to 0
  w = 0;  // Initialize variables used for temporary storage
  fixed_point_20_12_index = 0;
  increment_by = 2500;
  trigger = 0;
  triggered = false;
  playing = false;
  
  // Initialize all inputs
  this->drum_selection_input = NULL;
  this->trigger_input = NULL;
  this->sample_rate_input = NULL;    
}

uint16_t ModuleEqDrum::compute()
{

  // Read inputs
  drum_selection = readInput(drum_selection_input, 0, 13);
  trigger        = readInput(trigger_input);
  increment_by   = readInput(sample_rate_input);

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
        w = (((fixed_point_math.SquareRoot(t%16384))<<5)&64)<<1;
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
        w = (w+t+(w>>2))&874356;
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
        w = ((t^99)/(t>>4))<<1;
        break;

      case 8: // Simple pulse
        w = (t/(t>>9));
        break;

      case 9: // Noise snare
        w = ((520 - t%(t%w))/(t>>11));
        break;

      case 10: // double noise snare
        w = ((800 - t%(t%w))/(t>>11));
        break;

      case 11: // open snare
        w = ((890&t%(t%126))/(t>>7))<<3;
        break;

      case 12: // metallic
        w = ((8999&t%(t&11))/(t>>8))<<6;
        break;

      case 13: // vinal pop
        w = ((28959^(t>>2)%(t%230))/(t>>3))<<2;
        break;

    }
    
    fixed_point_20_12_index += increment_by;

  }
  
  return(w << 4);
}

uint32_t ModuleEqDrum::stop_playback()
{
  playing = false;
  w = 0;
}
