/*
 *  +----------------------+
 *  | ModuleSpeechSound    |
 *  |----------------------|
 *  > phase1_input         |
 *  > phase2_input         |
 *  > phase3_input         |
 *  > pitch_input          |
 *  > formant_scale_input  |
 *  |                      |
 *  |               output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleSpeechSound is a Formant synthesizer that makes sounds similar to vowel 
// sounds.
// 

#ifndef ModuleSpeechSound_h
#define ModuleSpeechSound_h

#include "Module.h"

#define FORMANT_SZ 7

class ModuleSpeechSound : public Module
{
  public:
    uint16_t compute();
    
    // Inputs
    Module *phase1_input;
    Module *phase2_input;
    Module *phase3_input;
    Module *pitch_input;
    Module *formant_scale_input;     
    
  private:
  
    uint16_t pitchPhase, form1Phase, form2Phase, form3Phase;
    uint16_t pitchPhaseInc, form1PhaseInc, form2PhaseInc, form3PhaseInc;
    uint8_t form1Amp, form2Amp, form3Amp;
        
    int frameTime;
    uint16_t basePitch;
    int formantScale;
};
    

#endif

