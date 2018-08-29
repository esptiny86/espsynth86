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

  // Initialize all inputs
  this->sample_selection_input = NULL;  
  this->trigger_input = NULL;  
  this->sample_rate_input = NULL;   
}

uint16_t ModuleSamplePlayer::compute()
{

  // Read inputs
  uint16_t sample_selection = this->readInput(sample_selection_input, 0, 8);
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

    switch(sample_selection)
    {

      // ========= Drum kit #0 =============

      case 0: // Kick drum
      
        if(t < SAMPLE_KICK_LENGTH) {
          w = SAMPLE_KICK[t];
        }
        else {
          stop_playback();
        }
        break;      
  
      case 1: // Snare drum

        if(t < SAMPLE_SNARE_LENGTH) {
          w = SAMPLE_SNARE[t];
        }
        else {
          stop_playback();
        }
        break;
        
      case 2: // Hihat

        if(t < SAMPLE_HIHAT_LENGTH) {
          w = SAMPLE_HIHAT[t];
        }
        else {
          stop_playback();
        }
        break;
        
      // ========= Drum kit #1 =============

      case 3: // Kick drum 2
      
        if(t < SAMPLE_KICK2_LENGTH) {
          w = SAMPLE_KICK2[t];
        }
        else {
          stop_playback();
        }
        break;      
  
      case 4: // Snare drum 2

        if(t < SAMPLE_SNARE2_LENGTH) {
          w = SAMPLE_SNARE2[t];
        }
        else {
          stop_playback();
        }
        break;
        
      case 5: // Hihat 2

        if(t < SAMPLE_HIHAT2_LENGTH) {
          w = SAMPLE_HIHAT2[t];
        }
        else {
          stop_playback();
        }
        break;
  
      // ========= Drum kit #2 =============

      case 6: // Kick drum 3
      
        if(t < SAMPLE_KICK3_LENGTH) {
          w = SAMPLE_KICK3[t];
        }
        else {
          stop_playback();
        }
        break;      
  
      case 7: // Snare drum 3

        if(t < SAMPLE_SNARE3_LENGTH) {
          w = SAMPLE_SNARE3[t];
        }
        else {
          stop_playback();
        }
        break;
        
      case 8: // Hihat 3

        if(t < SAMPLE_HIHAT3_LENGTH) {
          w = SAMPLE_HIHAT3[t];
        }
        else {
          stop_playback();
        }
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

