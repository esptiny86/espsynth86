#ifndef ModuleSpeechSound_h
#define ModuleSpeechSound_h

#include "Module.h"

#if defined(__SAM3X8E__)
    #define PROGMEM
    #define pgm_read_byte(x)        (*((char *)x))
    #define pgm_read_word(x)        ( ((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x)))
    #define pgm_read_byte_near(x)   (*((char *)x))
    #define pgm_read_byte_far(x)    (*((char *)x))
    #define pgm_read_word_near(x)   ( ((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x)))
    #define pgm_read_word_far(x)    ( ((*((unsigned char *)x + 1)) << 8) + (*((unsigned char *)x))))
    #define PSTR(x)  x
  #if defined F
    #undef F
  #endif
  #define F(X) (X)
#endif

#define FORMANT_SZ 7


class ModuleSpeechSound : public Module
{
  public:
    ModuleSpeechSound();
    uint16_t compute();
	
    // Inputs
    Module *sound_input;
	Module *param1_input;
    Module *param2_input;
	Module *pitch_input;    
    
  private:
  
    uint32_t output;

    uint16_t pitchPhase, form1Phase,form2Phase,form3Phase;
    uint16_t pitchPhaseInc,form1PhaseInc,form2PhaseInc,form3PhaseInc;
    uint8_t form1Amp,form2Amp,form3Amp;
    uint8_t noiseMod;    
    
    /*
    int8_t sinCalc[256];
    int8_t sqrCalc[256];
    uint8_t formantTable[546];
    uint16_t pitchTable[64];
	int8_t word[72];
    */

    int frameTime;
    uint16_t basePitch;
    int formantScale;
    
    int8_t noise;
};
    

#endif

