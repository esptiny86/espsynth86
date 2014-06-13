#include "Arduino.h"
#include "ModuleDelay.h"
#include "defines.h"

ModuleDelay::ModuleDelay()
{
  buffer_index = 0;
  feedback = 819;
  delay_output = 0;
  
  for(uint16_t i=0; i++; i < DELAY_BUFFER_SIZE)
  {
    buffer[i] = 0;
  }

  audio_input = NULL;
  mix_input = NULL;
  feedback_input = NULL;  
  length_input = NULL;  
}

uint32_t ModuleDelay::compute()
{
  uint32_t audio = this->readInput(audio_input);
  uint32_t wet_mix = this->readInput(mix_input);
  uint32_t feedback = this->readInput(feedback_input);
  uint16_t buffer_length = this->readInput(length_input);

  uint32_t dry_mix = 4095 - wet_mix;

  buffer_index++;
  if(buffer_index >= buffer_length) buffer_index = 0;
  
  delay_output = buffer[buffer_index];
  buffer[buffer_index] = ((audio * (4095 - feedback)) >> 12) + ((delay_output * feedback) >> 12);
  
  if(wet_mix == 0)
  {
    return(audio);
  }
  else
  {
    return(((delay_output * wet_mix) >> 12) + ((audio * dry_mix) >> 12));
  }
  
}
