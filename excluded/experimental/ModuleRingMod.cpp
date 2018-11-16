#include "Arduino.h"
#include "ModuleRingMod.h"
#include "Defines.h"
#include "GlobalWavetables.h"
#include "GlobalIncrements.h"

ModuleRingMod::ModuleRingMod()
{
  fixed_point_10_22_index = 0;

  // Initialize all module inputs to NULL
  this->audio_input = NULL;  
  this->frequency_input = NULL;
}

uint16_t ModuleRingMod::compute()
{
  uint16_t audio = this->readInput(audio_input);
  uint16_t frequency = this->readInput(frequency_input);
  uint16_t wavetable = 0;

  fixed_point_10_22_index += ((INCREMENTS[frequency] - 3100000));
  if(fixed_point_10_22_index > WAVE_SAMPLES_SHIFTED_22) fixed_point_10_22_index -= WAVE_SAMPLES_SHIFTED_22;

  wavetable_index = fixed_point_10_22_index >> 22;
   
  return(((uint32_t)audio * (uint32_t)WAVETABLES[wavetable][wavetable_index]) >> 1);
}