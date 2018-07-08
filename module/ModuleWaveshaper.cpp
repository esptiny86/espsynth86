
#include "defines.h"
#include "ModuleWaveshaper.h"
#include "GlobalWaveshaperTables.h"

ModuleWaveshaper::ModuleWaveshaper()
{
	// Initialize all inputs
  this->audio_input = NULL;
  this->mix_input = NULL;
  this->waveshaper_input = NULL;  
}

uint16_t ModuleWaveshaper::compute()
{
  // Read inputs
  uint16_t audio = this->readInput(audio_input);
  uint16_t waveshaper = this->readInput10Bit(waveshaper_input,0,4);
  uint16_t wet_mix = this->readInput10Bit(mix_input,0,4095);
  uint16_t dry_mix = 4095 - wet_mix;
  uint32_t shaped_output = 0;
  shaped_output = WAVE_SHAPER_TABLES[waveshaper][audio>>4]<<0;

  if(wet_mix < 100)
  {
    return(audio);
  }
  else
  {
    shaped_output = (((shaped_output * wet_mix) >> 8) + ((audio * dry_mix) >> 8));
    return shaped_output;
  }
}

