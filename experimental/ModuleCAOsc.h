#ifndef ModuleCAOsc_h
#define ModuleCAOsc_h

#include "Arduino.h"
#include "Module.h"

class ModuleCAOsc : public Module
{
  
  public:
  
    ModuleCAOsc();
    uint16_t compute();
    
    // Inputs


  private:
  
    uint16_t output;
    uint16_t last_output;

    uint16_t ca_rules[8];
};

#endif