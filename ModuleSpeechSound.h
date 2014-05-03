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

/*
enum {
  _SP,_DOT,_QM,_COM,_HYP,_IY,_IH,_EH,_AE,_AA,
  _AH,_AO,_UH,_AX,_IX,_ER,_UX,_OH,_RX,_LX,
  _WX,_YX,_WH,_RR,_LL,_WW,_YY,_MM,_NN,_NX,
  _DX,_QQ,_SS,_SH,_F,_TH,__H,__X,_ZZ,_ZH,
  _V,_DH,_CHa,_CHb,_Ja,_Jb,_Jc,_Jd,_EY,_AY,
  _OY,_AW,_OW,_UW,_Ba,_Bb,_Bc,_Da,_Db,_Dc,
  _Ga,_Gb,_Gc,_GXa,_GXb,_GXc,_Pa,_Pb,_Pc,_Ta,
  _Tb,_Tc,_Ka,_Kb,_Kc,_KXa,_KXb,_KXc
};
*/

class ModuleSpeechSound : public Module
{
  public:
    ModuleSpeechSound();
    uint32_t compute();
	
    // Inputs
    Module *sound_input;
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

