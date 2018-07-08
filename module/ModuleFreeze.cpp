#include "Arduino.h"
#include "ModuleFreeze.h"
#include "defines.h"
#include "GlobalRingBuffer.h"

ModuleFreeze::ModuleFreeze()
{
  buffer_index = 0;
  buffer_output = 0;

  audio_input = NULL;  
  length_input = NULL;  
}

uint16_t ModuleFreeze::compute()
{
  uint16_t audio = this->readInput(audio_input);
  uint16_t buffer_length = this->readInput(length_input);

  uint16_t inverted_buffer_length = RING_BUFFER_SIZE - buffer_length;

  buffer_index++;
  if(buffer_index >= inverted_buffer_length) buffer_index = 0;
  
  buffer_output = RING_BUFFER[buffer_index];

  if(buffer_length > 1000)
  {
    return(buffer_output);
  }
  else
  {
    RING_BUFFER[buffer_index] = audio;
    return(audio);
  }
  
}
