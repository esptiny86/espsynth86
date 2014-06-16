#include "Arduino.h"
#include "ModuleLFO.h"
#include "defines.h"
#include "Wavetables.h"

ModuleLFO::ModuleLFO()
{
  fixed_point_10_22_index = 0;

  for(uint32_t i=0; i < 4096; i++)
  {
    increments[i] = ((float)(512 << 20)/SAMPLE_RATE_FLOAT) * 0.1 * pow(2.0,((10.0*i)/4096.0));
  }  

  // Initialize all module inputs to NULL
  this->frequency_input = NULL;  
  this->wavetable_input = NULL;
}

uint32_t ModuleLFO::compute()
{
  // Read frequency input.  
  frequency = this->readInput(frequency_input);
  
  // Read the wavetable input and map it to the appropriate range
  wavetable = this->readInput(wavetable_input, 0, NUMBER_OF_WAVETABLES);
  wavetable = constrain(wavetable, 0, NUMBER_OF_WAVETABLES - 1);
  
  // Calculate the index into the wavetable  
  fixed_point_10_22_index += increments[frequency];
  if(fixed_point_10_22_index > (WAVE_SAMPLES << 22)) fixed_point_10_22_index -= (WAVE_SAMPLES << 22);

  wavetable_index = fixed_point_10_22_index >> 22; // This should yeald a value between 0 and WAVE_SAMPLES
  
  // This output will range from 0 to 4095 (which is a 12-bit value)
  // The slope values range from -128 to 127, and the additional math
  // below scales them between 0 and 4095.  
  return(WAVETABLES[wavetable][wavetable_index] << 4);
}
