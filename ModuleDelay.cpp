#include "Arduino.h"
#include "ModuleDelay.h"
#include "Defines.h"

ModuleDelay::ModuleDelay()
{
  buffer_index = 0;
  mix = 819; // .2 * 4096  (20% wet, 80% dry)
  feedback = 819;
  delay_output = 0;
  
  for(int i=0; i++; i<1024)
  {
    buffer[i] = 0;
  }

  audio_input = NULL;
  mix_input = NULL;
}

uint32_t ModuleDelay::compute()
{
  uint32_t audio = this->readInput(audio_input);
  uint32_t mix   = this->readInput(mix_input);
  uint32_t wet_mix = 4095 - mix;

  buffer_index++;
  if(buffer_index == 1024) buffer_index = 0;
  
  delay_output = buffer[buffer_index];
  buffer[buffer_index] = ((audio * (4095 - feedback)) >> 12) + ((delay_output * feedback) >> 12);
  
  if(mix == 0)
  {
    return(audio);
  }
  else
  {
    return(((delay_output * mix) >> 12) + ((audio * wet_mix) >> 12));
  }
  
}
