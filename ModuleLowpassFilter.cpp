#include "Arduino.h"
#include "ModuleLowpassFilter.h"
#include "defines.h"

ModuleLowpassFilter::ModuleLowpassFilter()
{
  // Set cutoff and resonance to 0 to start with.
  // For some reason, if you don't do this, the lowpass filter 
  // can generate noise until the cutoff reaches 0, then it starts sounding OK.
  lpf.setCutoffFreq(0);
  lpf.setResonance(0);

  // Initialize all inputs
  this->audio_input = NULL; 
  this->cutoff_input = NULL;
  this->resonance_input = NULL;    
}

uint32_t ModuleLowpassFilter::compute()
{
  // Read inputs
  uint32_t audio = this->readInput(audio_input);                            // audio range: 0 to 4095
  uint32_t cutoff = this->readInput(cutoff_input, CONVERT_TO_8_BIT);        // cutoff range: 0 to 255
  uint32_t resonance = this->readInput(resonance_input, CONVERT_TO_8_BIT);  // resonance range: 0 to 255
  
  lpf.setCutoffFreq(cutoff);
  lpf.setResonance(resonance);

  return(lpf.next(audio) >> 1);
}

