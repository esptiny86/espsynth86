/*
 *  +------------------------+
 *  | ModuleOscParam         |
 *  |------------------------|
 *  > waveform_input         |
 *  > pitch_input            |
 *  > fine_input             |
 *  |                        |
 *  >          osc1_waveform >
 *  >          osc2_waveform >
 *  >          osc3_waveform >
 *  >          osc1_pitch    >
 *  >          osc2_pitch    >
 *  >          osc3_pitch    >
 *  >          vca1_volume   >
 *  >          vca2_volume   >
 *  >          vca3_volume   >
 *  |                        |
 *  +------------------------+
 *
 */
// =============================================================================
// 
// ModuleOscParam takes 3 inputs and routes them to 9 outputs, in order to send 
// parameters to a 3 osc synth.  This module is very specific to Synth3Osc.
//


#ifndef ModuleOscParam_h
#define ModuleOscParam_h

#include "Module.h"
#include "ModuleOutput.h"

class ModuleOscParam : public Module
{
  public:
    ModuleOscParam();  	
    uint16_t compute();
    
    // Inputs
    Module *waveform_input;
    Module *pitch_input;
    Module *fine_input;

    // Outputs
    ModuleOutput *osc1_waveform;
    ModuleOutput *osc2_waveform;
    ModuleOutput *osc3_waveform;
    ModuleOutput *osc1_pitch;
    ModuleOutput *osc2_pitch;
    ModuleOutput *osc3_pitch;
    ModuleOutput *vca1_volume; 
    ModuleOutput *vca2_volume; 
    ModuleOutput *vca3_volume; 
};

#endif