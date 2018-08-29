#include "Arduino.h"
#include "ModuleOutput.h"
#include "defines.h"

ModuleOutput::ModuleOutput(Module *parent_module)
{
  this->value = 0;
  this->parent_module = parent_module;
}

uint16_t ModuleOutput::compute()
{
    // Call the parent module's run method.  Notice that the return results from 
    // the run method are ignored.  That's becuase, in this case, it's assumed that
    // the parent module will set this->value explicitely for this output module.
    this->parent_module->run(this->cycle);

    // this->value is the value at this output node
    return(this->value);
}
