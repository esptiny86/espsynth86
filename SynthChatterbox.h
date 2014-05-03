#ifndef SynthChatterbox_h
#define SynthChatterbox_h

#include "Arduino.h"
#include "Synth.h"

class SynthChatterbox : public Synth
{
  public:
  
    SynthChatterbox(Module *inputs[]); 
};

#endif
