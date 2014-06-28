#include "Arduino.h"
#include "ModuleWavetableOsc.h"
#include "defines.h"
#include "GlobalWavetables.h"
#include "GlobalIncrements.h"

ModuleWavetableOsc::ModuleWavetableOsc()
{
  fixed_point_10_22_index = 0;

  // Initialize all inputs
  this->frequency_input = NULL;
  this->wavetable_input = NULL;
}

uint16_t ModuleWavetableOsc::compute()
{
  // Read the frequency
  frequency = this->readInput(frequency_input);  

  // Read the wavetable input and map it to the appropriate range
  wavetable = this->readInput(wavetable_input, 0, NUMBER_OF_WAVETABLES);
  wavetable = constrain(wavetable, 0, NUMBER_OF_WAVETABLES - 1);

  // Calculate the index into the wavetable
  fixed_point_10_22_index += INCREMENTS[frequency];
  if(fixed_point_10_22_index > WAVE_SAMPLES_SHIFTED_22) fixed_point_10_22_index -= WAVE_SAMPLES_SHIFTED_22;

  wavetable_index = fixed_point_10_22_index >> 22; // This should yeald a value between 0 and WAVE_SAMPLES (512)

  // This output will range from 0 to 4080 (which is a 12-bit value)
  return(WAVETABLES[wavetable][wavetable_index] << 4);
}
