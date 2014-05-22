#ifndef Synth_h
#define Synth_h

// Include all of the module definitions so that they
// don't need to be included in the individual synths

#include "Arduino.h"
#include "Inputs.h"

#include "Module.h"
#include "ModuleOutput.h"
#include "ModuleArpeggio.h"
#include "ModuleClock.h"
#include "ModuleClockDivider.h"
#include "ModuleConstant.h"
#include "ModuleCounter.h"
#include "ModuleDelay.h"
#include "ModuleDrumSequencer.h"
#include "ModuleENV.h"
#include "ModuleEqDrum.h"
#include "ModuleEquationPlayer.h"
#include "ModuleEquationLooper.h"
#include "ModuleHighpassFilter.h"
#include "ModuleLFO.h"
#include "ModuleLowpassFilter.h"
#include "ModuleMixer3.h"
#include "ModuleSequencer.h"
#include "ModuleSmooth.h"
#include "ModuleSoundToy.h"
#include "ModuleVCA.h"
#include "ModuleVCClockDivider.h"
#include "ModuleVocalizer.h"
#include "ModuleWavetableOsc.h"
#include "ModuleWords.h"

class Synth
{
  public:
  
    // Methods
    Synth(); // Constructor
    uint32_t run(double cycle);

    
    // 'last_module' is the last module in the synth.  
    // This module's run() method will be called by the synth.
    Module *last_module; 
};

#endif
