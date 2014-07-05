/*
 *  +----------------------+
 *  | MacroGatedLPF.h      |
 *  |----------------------|
 *  +----------------------+
 *
 */


#ifndef MacroGatedLPF_h
#define MacroGatedLPF_h

#include "Arduino.h"
#include "Macro.h"

#include "ModuleLowpassFilter.h"
#include "ModuleENV.h"
#include "ModuleConstant.h"

class MacroGatedLPF : public Macro
{
  
  public:
    MacroGatedLPF();
    uint16_t compute();
    
    // Modules
    ModuleLowpassFilter *lowpass_filter;
    ModuleENV *envelope_generator;

    // Inputs
    //Module *audio_input;
    //Module *trigger_input;
};

#endif
