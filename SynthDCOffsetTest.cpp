#include "Arduino.h"
#include "defines.h"
#include "SynthDCOffsetTest.h"

SynthDCOffsetTest::SynthDCOffsetTest(Module* inputs[])
{
  ModuleArpeggio *arpeggio = new ModuleArpeggio();
  arpeggio->root_note_input = new ModuleConstant(20);
  arpeggio->pattern_input = new ModuleConstant(4);
  arpeggio->clock_input = new ModuleClock(10,8);
  
  this->last_module = arpeggio;
}