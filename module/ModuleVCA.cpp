#include "ModuleVCA.h"
#include "Defines.h"

ModuleVCA::ModuleVCA()
{
    this->audio_input = NULL;  
    this->cv_input = NULL;
}

uint16_t ModuleVCA::compute()
{
  // Read inputs
  uint32_t audio = this->readInput(audio_input);
  uint32_t cv = this->readInput(cv_input) ;
  
  return((audio * cv) >> 10 );
}
