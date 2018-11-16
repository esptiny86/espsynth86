#include "Arduino.h"
#include "ModuleReverb.h"
#include "Defines.h"
#include "GlobalRingBuffer.h"

ModuleReverb::ModuleReverb()
{
  buffer_index = 0;
  reverb_output = 0;

  audio_input = NULL;
  mix_input = NULL;
  feedback_input = NULL;   
}

uint16_t ModuleReverb::compute()
{
  uint32_t audio = this->readInput(audio_input);
  uint32_t wet_mix = this->readInput(mix_input);
  uint32_t feedback = this->readInput(feedback_input);
  uint16_t buffer_length = 4095;
  uint16_t buffer_index_2;
  uint16_t buffer_index_3;

  uint32_t dry_mix = 4095 - wet_mix;

  buffer_index++;
  if(buffer_index >= buffer_length) buffer_index = 0;

  buffer_index_2 = (buffer_index + 64) % 4095;
  buffer_index_3 = (buffer_index + 128) % 4095;  
  
  reverb_output = RING_BUFFER[buffer_index];

  // RING_BUFFER[buffer_index] = ((audio * (4095 - feedback)) >> 12) + ((reverb_output * feedback) >> 12);
  RING_BUFFER[buffer_index_2] = ((audio * (4095 - (feedback >> 0))) >> 12) + ((RING_BUFFER[buffer_index_2] * (feedback >> 0)) >> 12);
  RING_BUFFER[buffer_index_3] = ((audio * (4095 - (feedback >> 1))) >> 12) + ((RING_BUFFER[buffer_index_3] * (feedback >> 1)) >> 12);

  if(wet_mix == 0)
  {
    return(audio);
  }
  else
  {
    return(((reverb_output * wet_mix) >> 12) + ((audio * dry_mix) >> 12));
  }
  
}
