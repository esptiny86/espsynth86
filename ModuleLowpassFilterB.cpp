#include "Arduino.h"
#include "ModuleLowpassFilterB.h"
#include "defines.h"

ModuleLowpassFilterB::ModuleLowpassFilterB()
{
  // Set cutoff and resonance to 0 to start with.
  // For some reason, if you don't do this, the lowpass filter 
  // can generate noise until the cutoff reaches 0, then it starts sounding OK.
  lpf.setFC(0,0);

  // Initialize all inputs
  this->audio_input = NULL; 
  this->cutoff_input = NULL;
  this->resonance_input = NULL;    
}

uint16_t ModuleLowpassFilterB::compute()
{
  // Read inputs
  uint16_t audio = this->readInput(audio_input);               // audio range: 0 to 4095
  uint32_t cutoff = this->readInput(cutoff_input);        // cutoff range: 0 to 4095
  uint32_t resonance = this->readInput(resonance_input);  // resonance range: 0 to 4095

  lpf.setFC(cutoff, resonance);  

  return(lpf.next(audio));
}