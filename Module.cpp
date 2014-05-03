#include "Arduino.h"
#include "Defines.h"
#include "Module.h"

Module::Module()
{
  // cycle is used to see if the module has already been run during the current 
  // interrupt execution.
  cycle = 10;
  output = 0; 
  no_output_conversion = false;
}

uint32_t Module::run(long cycle)
{ 
  
  // If the module has already been run during this cycle, then return the 
  // output without recalculating it.
  if(this->cycle == cycle) return(this->output);
  
  this->cycle = cycle;
  
  // Compute the module's output and store it as a instance variable
  this->output = this->compute();
  
  return(this->output);
}

uint32_t Module::readInput(Module *module, int conversion)
{
  // If someone forgot to attach a module to an input, assume they mean for that 
  // input to be 0.
  if(! module) return(0);

  // When no_output_conversion is true, the actual output value of a module is
  // used, instead of being mapped to 0-4095. no_output_conversion is set in
  // ModuleConstant.php

  if(module->no_output_conversion)
  {
    return(module->run(this->cycle));
  }
  else
  {
    return(module->run(this->cycle) >> conversion);
  }
}

uint32_t Module::readInput(Module *module)
{
  if(! module) return(0);

  return(module->run(this->cycle));
}

