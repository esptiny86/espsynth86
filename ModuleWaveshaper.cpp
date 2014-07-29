
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
  uint16_t waveshaper = this->readInput(waveshaper_input,0,4);
  uint16_t wet_mix = this->readInput(mix_input);

  uint16_t dry_mix = 4095 - wet_mix;

  uint16_t shaped_output = WAVE_SHAPER_TABLES[waveshaper][audio];

  if(wet_mix == 0)
  {
    return(audio);
  }
  else
  {
    return(((shaped_output * wet_mix) >> 12) + ((audio * dry_mix) >> 12));
  }
}

