#include "Arduino.h"
#include "ModuleSamplePlayer.h"
#include "Defines.h"
#include "GlobalSamples.h"
#include "GlobalIncrements.h"

ModuleSamplePlayer::ModuleSamplePlayer()
{
  t = 0;  // Sample index
  w = 0;  // Final output
  fixed_point_20_12_index = 0;
  triggered = false; 
}

uint16_t ModuleSamplePlayer::compute()
{

  // Read inputs
  uint16_t sample_selection = this->readInput(sample_selection_input, CONVERT_TO_2_BIT); // range: 0 - 3
  uint16_t trigger = this->readInput(trigger_input);
  uint16_t frequency = this->readInput(sample_rate_input) << 2;
  
  if((trigger >= MID_CV) && !triggered) 
  {
    triggered = true;
    playing = true;
    fixed_point_20_12_index = 0;
  }
  
  if((trigger < MID_CV) && triggered) 
  {
    triggered = false;
  }
  
  if(playing)
  {
    // shift off th 12 bits used for fractional numbers, which leaves us with a 20 bit number
    t = fixed_point_20_12_index >> 12; 

	// Serial.println(sample_selection);

    switch(sample_selection)
    {
      
      case 0: // Kick drum
      
        if(t < SAMPLE_KICK2_LENGTH) {
          w = SAMPLE_KICK2[t];
        }
        else {
          stop_playback();
        }
        break;      
  
      case 1: // Snare drum

        if(t < SAMPLE_SNARE2_LENGTH) {
          w = SAMPLE_SNARE2[t];
        }
        else {
          stop_playback();
        }
        break;
        
      case 2: // Hihat

        if(t < SAMPLE_HIHAT2_LENGTH) {
          w = SAMPLE_HIHAT2[t];
        }
        else {
          stop_playback();
        }

        break;
        
      case 3:

        break;
  
    }

    fixed_point_20_12_index += frequency;
  }

  return(w);
}

void ModuleSamplePlayer::stop_playback()
{
  t = 0;
  playing = false;
}

