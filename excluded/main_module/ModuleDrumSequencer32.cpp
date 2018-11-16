#include "Arduino.h"
#include "ModuleDrumSequencer32.h"
#include "Defines.h"

ModuleDrumSequencer32::ModuleDrumSequencer32()
{
  this->clocked = false;
  this->step = 0;

  // Initialize all inputs
  this->clock_input = NULL;
  this->kick_pattern_input = NULL;  
  this->snare_pattern_input = NULL;  
  this->hihat_pattern_input = NULL;  

  // Instantiate all outputs
  kick_output = new ModuleOutput(this);
  snare_output = new ModuleOutput(this);
  hihat_output  = new ModuleOutput(this);
}

uint16_t ModuleDrumSequencer32::compute()
{
  uint32_t clock = this->readInput(clock_input);

  if((clock < MID_CV) && clocked)
  {
    clocked = false;
    kick_output->value = 0;
    snare_output->value = 0;
    hihat_output->value = 0;
  }

  if((clock >= MID_CV) && !clocked) 
  {
    clocked = true;
    
    uint8_t kick_pattern  = this->readInput(kick_pattern_input, CONVERT_TO_4_BIT);
    uint8_t snare_pattern = this->readInput(snare_pattern_input, CONVERT_TO_4_BIT);
    uint8_t hihat_pattern = this->readInput(hihat_pattern_input, CONVERT_TO_4_BIT);
    
    kick_output->value  = bitRead(patterns[0][kick_pattern], step) * MAX_CV;
    snare_output->value = bitRead(patterns[1][snare_pattern], step) * MAX_CV;
    hihat_output->value = bitRead(patterns[2][hihat_pattern], step) * MAX_CV;
    
    step++;
    if(step == 32) step = 0;
  }

  return(kick_output->value);
}
