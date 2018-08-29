#include "Arduino.h"
#include "ModuleLooper.h"
#include "Defines.h"
#include "GlobalLoops.h"
#include "GlobalIncrements.h"

ModuleLooper::ModuleLooper()
{
  t = 0;  // Sample index
  w = 0;  // Final output
  fixed_point_20_12_index = 0;
  triggered = false; 

  // Initialize all inputs  
  this->sample_input = NULL;
  this->trigger_input = NULL;  
  this->sample_rate_input = NULL; 
  this->slice_input = NULL;    
}

uint16_t ModuleLooper::compute()
{

  // Read inputs
  uint16_t sample = this->readInput(sample_input, CONVERT_TO_1_BIT);
  uint16_t trigger = this->readInput(trigger_input);
  uint16_t frequency = this->readInput(sample_rate_input) << 1;
  uint16_t slice = this->readInput(slice_input, CONVERT_TO_4_BIT); // ranges from 0 to 16

  uint16_t sample_length;

  // Select sample

  switch(sample)
  {
    case 0:
      sample_length = DEVINE_BEAT1_LENGTH;
      break;

    case 1:
      sample_length = DEVINE_BEAT2_LENGTH;
      break;
  }

  // Handle trigger events

  if((trigger >= MID_CV) && !triggered) 
  {
    triggered = true;
    fixed_point_20_12_index = (slice * (sample_length/16)) << 12;
  }

  if((trigger < MID_CV) && triggered) 
  {
    triggered = false;
  }

  // Playback selected sample

  t = fixed_point_20_12_index >> 12; 

  if(t >= sample_length) 
  {
    t = t - sample_length;
    fixed_point_20_12_index = t << 12;
  }

  switch(sample)
  {
    case 0:
      w = DEVINE_BEAT1[t];
      break;

    case 1:
      w = DEVINE_BEAT2[t];
      break;
  }
  

  fixed_point_20_12_index += frequency;


  return(w<<4);
}
