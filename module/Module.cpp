#include "Arduino.h"
#include "defines.h"
#include "Module.h"

Module::Module()
{
  // cycle is used to see if the module has already been run during the current 
  // interrupt execution.
  cycle = 10;
  output = 0; 
  no_output_conversion = false;
}

uint16_t Module::run(uint8_t cycle)
{ 
  
  // If the module has already been run during this cycle, then return the 
  // output without recalculating it.
  if(this->cycle == cycle) return(this->output);
  
  this->cycle = cycle;
  
  // Compute the module's output and store it as a instance variable
  this->output = this->compute();
  
  return(this->output);
}

uint16_t Module::readInput(Module *module, int conversion)
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

uint16_t Module::readInput(Module *module, uint32_t map_low, uint32_t map_high)
{
  // If someone forgot to attach a module to an input, assume they mean for that 
  // input to be 0.
  if(! module) return(0);

  // When no_output_conversion is true, the actual output value of a module is
  // used, instead of being mapped. no_output_conversion is set in ModuleConstant.php

  if(module->no_output_conversion)
  {
    return(module->run(this->cycle));
  }
  else
  {

    //
    // The output equation below is the same as..
    //
    //   return(map(module->run(this->cycle), 0, 4096, map_low, map_high));
    //
    // But since dividing by 4096 can be done a lot faster via bitshifting,
    // this is a more efficient algorithm.  When tested against a call to 
    // map(..), it's about 2x as fast.
    //

    return((((module->run(this->cycle) * (map_high - map_low)) >> 12) + map_low));
  }
}

uint16_t Module::readInput10Bit(Module *module, uint32_t map_low, uint32_t map_high)
{
  // If someone forgot to attach a module to an input, assume they mean for that
  // input to be 0.
  if(! module) return(0);

  // When no_output_conversion is true, the actual output value of a module is
  // used, instead of being mapped. no_output_conversion is set in ModuleConstant.php

    return(((( (module->run(this->cycle)+1) * (map_high - map_low)) >> 10) + map_low));
}


uint16_t Module::readInput(Module *module)
{
  if(! module) return(0);

  return(module->run(this->cycle));
}

