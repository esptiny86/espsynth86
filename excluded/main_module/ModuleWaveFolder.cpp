#include "ModuleWaveFolder.h"
#include "Defines.h"

ModuleWaveFolder::ModuleWaveFolder()
{
  this->audio_input = NULL;
  this->lower_clipping_level_input = NULL;
  this->upper_clipping_level_input = NULL;
}

uint16_t ModuleWaveFolder::compute()
{
  // Read inputs
  uint16_t audio = this->readInput(this->audio_input);
  uint16_t lower_clipping_level = this->readInput(this->lower_clipping_level_input, 0, 1792);
  uint16_t upper_clipping_level = this->readInput(this->upper_clipping_level_input, 4095, 2304);

  // Allow up to 4 folds
  for(int i=0; i<4; i++)
  {
    if(audio > upper_clipping_level) 
    {
      audio = upper_clipping_level - (audio - upper_clipping_level);
    }

    if(audio < lower_clipping_level)
    {
      audio = lower_clipping_level + (lower_clipping_level - audio);
    }
  }

  // Clip any remaining audio that doesn't fit withing the clipping range
  if(audio > upper_clipping_level) audio = upper_clipping_level;
  if(audio < lower_clipping_level) audio = lower_clipping_level;

  // Adjust gain based on clipping levels
  float gain = 4095.0 / (float)(upper_clipping_level - lower_clipping_level);

  return((audio - lower_clipping_level) * gain);
}
