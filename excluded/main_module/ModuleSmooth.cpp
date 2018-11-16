#include "Arduino.h"
#include "ModuleSmooth.h"
#include "Defines.h"

ModuleSmooth::ModuleSmooth()
{
  mix = 819; // .2 * 4096  (20% wet, 80% dry)
  smooth_output = 0;
  
  for(int i=0; i++; i<6)
  {
    buffer[i] = 0;
  }

  // Initialize all inputs
  this->audio_input = NULL;
  this->mix_input = NULL;
}

//
// haystack smooth using coefficients 1 3 6 7 6 3 1
// See: http://terpconnect.umd.edu/~toh/spectrum/Smoothing.html
//
uint16_t ModuleSmooth::compute()
{
  uint16_t audio = this->readInput(audio_input);
  uint16_t mix   = this->readInput(mix_input);
  uint16_t wet_mix = 4095 - mix;

  buffer[0] = buffer[1];
  buffer[1] = buffer[2];
  buffer[2] = buffer[3];
  buffer[3] = buffer[4];
  buffer[4] = buffer[5];
  buffer[5] = buffer[6];
  buffer[6] = audio;

  smooth_output = ((buffer[0] + (3*buffer[1]) + (6*buffer[2]) + (7*buffer[3]) + (6*buffer[4]) + (3*buffer[5]) + buffer[6]) / 27.0);
  
  if(mix == 0)
  {
    return(audio);
  }
  else
  {
    return(((smooth_output * mix) >> 12) + ((audio * wet_mix) >> 12));
  }
  
}
