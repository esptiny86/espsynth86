/*
 *   +-------------------------+
 *   | ModuleVocalizer         |
 *   |-------------------------|
 *   > pitch_input             |
 *   > param1_input            |
 *   > param2_input            |
 *   > param3_input            |
 *   > formant_scale_input     |
 *   |                         |
 *   |                  output >
 *   +-------------------------+
 *
*/
// =============================================================================
// 
// ModuleVocalizer is a human speech vowel emulator.  Output sounds like someone
// saying "oooo", "whaaa", "uuuuu".
//
// Example usage:
//
//   ModuleWords *words = new ModuleWords();
// 
//   words->sound_input = inputs->mod;
//   words->param1_input = inputs->param1;
//   words->param2_input = inputs->param2;
//   words->param3_input = inputs->param3;
//   words->pitch_input = inputs->sr;
//
//   this->last_module = words;
//

#ifndef ModuleVocalizer_h
#define ModuleVocalizer_h

#include "Module.h"

#define FORMANT_SZ 7


class ModuleVocalizer : public Module
{
  public:
    ModuleVocalizer();
    uint32_t compute();
	
    // Inputs
    Module *param1_input;
    Module *param2_input;
	Module *param3_input;
	Module *pitch_input;
    Module *formant_scale_input;     
    
  private:
  
    uint32_t output;

    uint16_t pitchPhase, form1Phase,form2Phase,form3Phase;
    uint16_t pitchPhaseInc,form1PhaseInc,form2PhaseInc,form3PhaseInc;
    uint8_t form1Amp,form2Amp,form3Amp;
    uint8_t noiseMod;    
    
    int8_t sinCalc[256];
    int8_t sqrCalc[256];
    uint8_t formantTable[546];
    uint16_t pitchTable[64];
    int frameTime;
    uint16_t basePitch;
    int formantScale;
    
    int8_t noise;
};
    

#endif