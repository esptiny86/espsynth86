#ifndef ModuleAudioEFX_h
#define ModuleAudioEFX_h

#include "Arduino.h"
#include "Module.h"
#include "Equations.h"

class ModuleAudioEFX : public Module
{
  
  public:
    ModuleAudioEFX(Equations *equations);
    uint32_t compute();
    
    // Inputs
    Module *equation_input;
    Module *audio_input;
    Module *param1_input;
    Module *param2_input;
    Module *param3_input;
    Module *reset_input;
    Module *mod_input;
    
  private:
    int equation;
    uint32_t audio;
    
    uint32_t p1;
    uint32_t p2;
    uint32_t p3;
    
    Equations *equations;    
};

#endif
