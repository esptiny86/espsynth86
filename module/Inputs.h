#ifndef Inputs_h
#define Inputs_h

#include "Defines.h"
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
	// modules are strung together.  Each module can have inputs, and these inputs -must be- pointers 
	// to other modules.  That's also why there's such thing as a ModuleConstant, since we can't set a 
	// module's input to a number, like 43.  A pointer to a global instance of the Inputs class is passed 
	// into each Synth via the constructor.  From inside a synth, you can read one of the inputs with 
	// code like:
	//
	//   some_module->some_input = inputs->param2;
	//

	ModuleAnalogInput *prg;
	ModuleAnalogInput *sr;
	ModuleAnalogInput *mod;
	ModuleAnalogInput *param1;
	ModuleAnalogInput *param2;
	ModuleAnalogInput *param3;
	ModuleDigitalInput *gate;

};

#endif