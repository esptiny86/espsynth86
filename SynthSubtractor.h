#ifndef SynthSubtractor_h
#define SynthSubtractor_h

#include "Synth.h"

class SynthSubtractor : public Synth
{
  public:
    SynthSubtractor(Module *inputs[]); 
    
    // Create modules.  These modules will be wired together in the constructor
    ModuleOsc osc;   
    ModuleLowpassFilter lowpass_filter;
    ModuleVCA vca;
    ModuleLFO lfo;
    ModuleADSR adsr;
};

#endif
