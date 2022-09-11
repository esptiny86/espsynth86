#include "Arduino.h"

#ifndef SPEECH_TABLES
#define SPEECH_TABLES

extern const uint16_t speechPitchTable[];
extern const int8_t speechSinCalc[]; 
extern const int8_t speechSqrCalc[];
extern const uint8_t speechFormantTable[];
extern const uint8_t speechWordTable[];

#endif