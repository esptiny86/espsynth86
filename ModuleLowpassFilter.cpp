#include "Arduino.h"
#include "ModuleLowpassFilter.h"
#include "defines.h"


ModuleLowpassFilter::ModuleLowpassFilter()
{
  // Set cutoff and resonance to 0 to start with.
  // For some reason, if you don't do this, the lowpass filter 
  // can generate noise until the cutoff reaches 0, then it starts sounding OK.
  lpf.setResonance(0);
  lpf.setCutoffFreq(0);

  // Initialize all inputs
  this->audio_input = NULL; 
  this->cutoff_input = NULL;
  this->resonance_input = NULL;    
}



uint16_t ModuleLowpassFilter::compute()
{

  // Read inputs
  int audio = this->readInput(audio_input) - 2048;                          // audio range: 0 to 4095
  uint32_t cutoff = this->readInput(cutoff_input, CONVERT_TO_8_BIT);        // cutoff range: 0 to 255
  uint32_t resonance = this->readInput(resonance_input, CONVERT_TO_8_BIT);  // resonance range: 0 to 255

  lpf.setResonance(resonance);  
  lpf.setCutoffFreq(cutoff);

  return((uint32_t) ((lpf.next(audio >> 4) << 3) + 2048));
}