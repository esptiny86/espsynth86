#include "Arduino.h"
#include "ModuleWavetableOsc.h"
#include "Defines.h"
#include "Wavetables.h"

#define SAMPLE_RATE 44100.0
#define SAMPLES_PER_CYCLE 512
#define SAMPLES_PER_CYCLE_FIXEDPOINT (SAMPLES_PER_CYCLE<<20)
#define TICKS_PER_CYCLE (float)((float)SAMPLES_PER_CYCLE_FIXEDPOINT/(float)SAMPLE_RATE)

ModuleWavetableOsc::ModuleWavetableOsc()
{
  fixed_point_10_22_index = 0;

  for(uint32_t i=0; i < 128; i++)
  {
    float frequency = ((pow(2.0,(i-69.0)/12.0)) * 440.0);
    increments[i] = frequency * TICKS_PER_CYCLE;
  }

  // Initialize all inputs
  this->frequency_input = NULL;
  this->wavetable_input = NULL;
}

uint32_t ModuleWavetableOsc::compute()
{
  // Read the frequency
  frequency = this->readInput(frequency_input, CONVERT_TO_10_BIT);  
  
  // Read the wavetable input and map it to the appropriate range
  wavetable = this->readInput(wavetable_input, 0, NUMBER_OF_WAVETABLES);
  wavetable = constrain(wavetable, 0, NUMBER_OF_WAVETABLES - 1);

  // Calculate the index into the wavetable
  fixed_point_10_22_index += increments[((frequency*60)>>10)+48];
  if(fixed_point_10_22_index > (WAVE_SAMPLES << 22)) fixed_point_10_22_index -= (WAVE_SAMPLES << 22);

  wavetable_index = fixed_point_10_22_index >> 22; // This should yeald a value between 0 and WAVE_SAMPLES

  // This output will range from 0 to 4080 (which is a 12-bit value)
  // The wavetable values range from -128 to 127, and the additional math
  // below scales them between 0 and 4095.
  return((WAVETABLES[wavetable][wavetable_index] + 128) << 4);
}
