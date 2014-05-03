#ifndef Inputs_h
#define Inputs_h

#include "defines.h"
#include "ModuleAnalogInput.h"
#include "ModuleDigitalInput.h"


class Inputs
{
  public:
  
    // Methods
    Inputs(); // Constructor

    void read();

    // Individual input modules
    //
	// It might seem strange to use a "module" just for an input, but it's necessary because of the way
	// the modules are strung together.  Each module can have inputs, and these inputs -must be- pointers 
	// to other modules.  That's also why there's such thing as a ModuleConstant, since we can't set a 
	// module's input to a number, like 43.  The input modules are global and are passed into each
	// Synth via the constructor.

	ModuleAnalogInput *prg;
	ModuleAnalogInput *sr;
	ModuleAnalogInput *mod;
	ModuleAnalogInput *param1;
	ModuleAnalogInput *param2;
	ModuleAnalogInput *param3;
	ModuleDigitalInput *gate;

};

#endif