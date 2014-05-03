/*
 *  +----------------------+
 *  | ModuleVCA            |
 *  |----------------------|
 *  > audio_input          |
 *  > cv_input             |
 *  |               output >
 *  +----------------------+
 */

#ifndef ModuleVCA_h
#define ModuleVCA_h

#include "Module.h"

class ModuleVCA : public Module
{
  public:
  	ModuleVCA();
    uint32_t compute();

    // Inputs
    Module *audio_input;  
    Module *cv_input;  
};

#endif
