#ifndef defines_h
#define defines_h

// Number of wavetable in GlobalWavetables.cpp
#define NUMBER_OF_WAVETABLES 32 

// Slopes are defined in GlobalSlopes.cpp
#define NUMBER_OF_SLOPES 10

// Some wavetable constants.  Don't change these.
#define WAVE_SAMPLES 512
#define WAVE_SAMPLES_SHIFTED_22 2147483648 

// Maximum CV value used throughout the module
#define MAX_CV 4095

// 1/2 of MAX_CV
#define MID_CV 2047

// Pin definitions
#define PIN_PRG 0
#define PIN_SR 1
#define PIN_PARAM_1 2
#define PIN_PARAM_2 3
#define PIN_PARAM_3 4
#define PIN_MOD 5
#define PIN_GATE 22

// ADAC and Analog Read values
// Typical values are 8, 10 or 12
#define ANALOG_READ_RESOLUTION 12

// Assorted definitions
#define SAMPLE_RATE 22050
#define SAMPLE_RATE_FLOAT 22050.0

// Conversion constants used by uint16_t readInput(Module *, int conversion);
#define CONVERT_TO_1_BIT 11
#define CONVERT_TO_2_BIT 10
#define CONVERT_TO_3_BIT 9
#define CONVERT_TO_4_BIT 8
#define CONVERT_TO_5_BIT 7
#define CONVERT_TO_6_BIT 6
#define CONVERT_TO_7_BIT 5
#define CONVERT_TO_8_BIT 4
#define CONVERT_TO_9_BIT 3
#define CONVERT_TO_10_BIT 2
#define CONVERT_TO_11_BIT 1
#define NO_COVERSION 0

// Define clock divisions for use in ModuleClock and ModuleExtClock constructors
// Note: These constants can't be used for the ModuleClockDivider
#define WHOLE_NOTE_CLOCK_DIVISION 384
#define HALF_NOTE_CLOCK_DIVISION 192
#define QUARTER_NOTE_CLOCK_DIVISION 96
#define EIGHTH_NOTE_CLOCK_DIVISION 48
#define SIXTEENTH_NOTE_CLOCK_DIVISION 24
#define THIRTY_SECOND_NOTE_CLOCK_DIVISION 12


// Enums for voice simulation synths
// These may not be needed anymore.
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


#endif
