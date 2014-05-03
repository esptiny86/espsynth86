#ifndef SynthDCOffsetTest_h
#define SynthDCOffsetTest_h

#include "Arduino.h"
#include "Synth.h"

class SynthDCOffsetTest : public Synth
{
  public:
    SynthDCOffsetTest(Module *inputs[]); 
};

#endif