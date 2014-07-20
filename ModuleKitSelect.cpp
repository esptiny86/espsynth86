#include "Arduino.h"
#include "ModuleKitSelect.h"
#include "Defines.h"


ModuleKitSelect::ModuleKitSelect()
{
  // The number in the kits array are the indexes of
  // the sounds in ModuleSamplePlayer.php
  this->kits = {
    { 
      0,1,2
    },
    {
      3,4,5
    },
    {
      6,7,8
    }    
  };

  // Initialize all inputs
  this->kit_selection_input = NULL;

  // Instantiate all outputs
  kick_output = new ModuleOutput(this);
  snare_output = new ModuleOutput(this);
  hihat_output  = new ModuleOutput(this);

  // The outputs of ModuleKitSelect should not
  // be mapped by the receiving module, which is
  // usually ModuleSamplePlayer

  kick_output->no_output_conversion = true;
  snare_output->no_output_conversion = true;
  hihat_output->no_output_conversion = true;
}

uint16_t ModuleKitSelect::compute()
{

  // Read inputs
  uint8_t kit_selection = this->readInput(kit_selection_input, 0, 3);

  this->kick_output->value = kits[kit_selection][0];
  this->snare_output->value = kits[kit_selection][1];
  this->hihat_output->value = kits[kit_selection][2];

  return(0);
}