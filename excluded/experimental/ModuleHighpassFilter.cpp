#include "Arduino.h"
#include "ModuleHighpassFilter.h"
#include "Defines.h"

ModuleHighpassFilter::ModuleHighpassFilter()
{
  // Set cutoff and resonance to 0 to start with.
  // For some reason, if you don't do this, the lowpass filter 
  // can generate noise until the cutoff reaches 0, then it starts sounding OK.
  hpf.setCutoffFreq(0);
  hpf.setResonance(0);

  // Initialize all inputs
  this->audio_input = NULL; 
  this->cutoff_input = NULL;
  this->resonance_input = NULL;  
}

uint16_t ModuleHighpassFilter::compute()
{
  // Read inputs
  uint32_t audio = this->readInput(audio_input);                            // audio range: 0 to 4095
  uint32_t cutoff = this->readInput(cutoff_input, CONVERT_TO_8_BIT);        // cutoff range: 0 to 255
  uint32_t resonance = this->readInput(resonance_input, CONVERT_TO_8_BIT);  // resonance range: 0 to 255
  
  hpf.setCutoffFreq(cutoff);
  hpf.setResonance(resonance);

  return(hpf.next(audio) >> 1);
}

