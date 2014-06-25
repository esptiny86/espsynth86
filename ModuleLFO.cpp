#include "Arduino.h"
#include "ModuleLFO.h"
#include "defines.h"
#include "Wavetables.h"
#include "Increments.h"

ModuleLFO::ModuleLFO()
{
  fixed_point_10_22_index = 0;

  // Initialize all module inputs to NULL
  this->frequency_input = NULL;  
  this->wavetable_input = NULL;
}

uint16_t ModuleLFO::compute()
{
  // Read frequency input.  
  frequency = this->readInput(frequency_input);
  
  // Read the wavetable input and map it to the appropriate range
  wavetable = this->readInput(wavetable_input, 0, NUMBER_OF_WAVETABLES);
  wavetable = constrain(wavetable, 0, NUMBER_OF_WAVETABLES - 1);
  
  // Calculate the index into the wavetable  
  fixed_point_10_22_index += ((INCREMENTS[frequency] - 3100000) >> 4);
  if(fixed_point_10_22_index > WAVE_SAMPLES_SHIFTED_22) fixed_point_10_22_index -= WAVE_SAMPLES_SHIFTED_22;

  wavetable_index = fixed_point_10_22_index >> 22;
   
  return(WAVETABLES[wavetable][wavetable_index] << 4);
}
