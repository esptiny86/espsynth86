#include "Arduino.h"
#include "ModuleDelay.h"
#include "defines.h"
#include "GlobalRingBuffer.h"

ModuleDelay::ModuleDelay()
{
  buffer_index = 0;
  delay_output = 0;

  audio_input = NULL;
  mix_input = NULL;
  feedback_input = NULL;  
  length_input = NULL;  
}

uint16_t ModuleDelay::compute()
{
  uint32_t audio = this->readInput(audio_input);
  uint32_t wet_mix = this->readInput(mix_input,0, 4095);
  uint32_t feedback = this->readInput(feedback_input,0, 4095);
  uint16_t buffer_length = this->readInput(length_input,0, RING_BUFFER_SIZE);

  uint32_t dry_mix = 4095 - wet_mix;

  buffer_index++;
  if(buffer_index >= buffer_length) buffer_index = 0;
  
  delay_output = RING_BUFFER[buffer_index];
  RING_BUFFER[buffer_index] = ((audio * (4095 - feedback)) >> 12) + ((delay_output * feedback) >> 12);

  if(wet_mix == 0)
  {
    return(audio);
  }
  else
  {
    return(((delay_output * wet_mix) >> 12) + ((audio * dry_mix) >> 12));
  }
  
}
