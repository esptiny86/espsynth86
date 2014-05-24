#include "Arduino.h"
#include "ModuleChatBot.h"
#include "defines.h"

/*

  This code is a port of the Arduino Cantarino 
  http://code.google.com/p/tinkerit/wiki/Cantarino

*/

ModuleChatBot::ModuleChatBot()
{
  output = 0;
  
  pitchTable = {
    58,61,65,69,73,77,82,86,92,97,
    103,109,115,122,129,137,145,154,163,173,
    183,194,206,218,231,244,259,274,291,308,
    326,346,366,388,411,435,461,489,518,549,
    581,616,652,691,732,776,822,871,923,978,
    1036,1097,1163,1232,1305,1383,1465,1552,1644,1742,
    1845,1955,2071,2195
  };
  
  sinCalc  = {
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,2,2,3,3,4,5,6,7,8,10,12,14,17,20,24,
    0,4,4,5,6,7,9,11,13,15,18,22,26,31,37,45,
    0,5,6,7,8,10,12,14,17,20,24,28,34,41,49,58,
    0,5,6,7,9,10,12,15,18,21,26,31,37,44,53,63,
    0,5,6,7,8,10,12,14,17,20,24,28,34,41,49,58,
    0,4,4,5,6,7,9,11,13,15,18,22,26,31,37,45,
    0,2,2,3,3,4,5,6,7,8,10,12,14,17,20,24,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
    0,-2,-2,-3,-3,-4,-5,-6,-7,-8,-10,-12,-14,-17,-20,-24,
    0,-4,-4,-5,-6,-7,-9,-11,-13,-15,-18,-22,-26,-31,-37,-45,
    0,-5,-6,-7,-8,-10,-12,-14,-17,-20,-24,-28,-34,-41,-49,-58,
    0,-5,-6,-7,-9,-10,-12,-15,-18,-21,-26,-31,-37,-44,-53,-63,
    0,-5,-6,-7,-8,-10,-12,-14,-17,-20,-24,-28,-34,-41,-49,-58,
    0,-4,-4,-5,-6,-7,-9,-11,-13,-15,-18,-22,-26,-31,-37,-45,
    0,-2,-2,-3,-3,-4,-5,-6,-7,-8,-10,-12,-14,-17,-20,-24
  };  
  
  sqrCalc  ={
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,1,2,2,2,3,3,4,5,5,6,8,9,11,13,16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16,
    0,-1,-2,-2,-2,-3,-3,-4,-5,-5,-6,-8,-9,-11,-13,-16
  };
  
  formantTable  = {
     0x0, 0x0, 0x0,0x0,0x0,0x0,0x0,/*00 space*/ 0x13,0x43,0x5b,0x0,0x0,0x0,0x0,/*01 .*/
    0x13,0x43,0x5b,0x0,0x0,0x0,0x0,/*02 ?*/     0x13,0x43,0x5b,0x0,0x0,0x0,0x0,/*03 ,*/
    0x13,0x43,0x5b,0x0,0x0,0x0,0x0,/*04 -*/      0xa,0x54,0x6e,0xd,0xa,0x8,0x0,/*05 IY*/
     0xe,0x49,0x5d,0xd,0x8,0x7,0x0,/*06 IH*/    0x13,0x43,0x5b,0xe,0xd,0x8,0x0,/*07 EH*/
    0x18,0x3f,0x58,0xf,0xe,0x8,0x0,/*08 AE*/    0x1b,0x28,0x59,0xf,0xd,0x1,0x0,/*09 AA*/
    0x17,0x2c,0x57,0xf,0xc,0x1,0x0,/*10 AH*/    0x15,0x1f,0x58,0xf,0xc,0x0,0x0,/*11 AO*/
    0x10,0x25,0x52,0xf,0xb,0x1,0x0,/*12 UH*/    0x14,0x2c,0x57,0xe,0xb,0x0,0x0,/*13 AX*/
     0xe,0x49,0x5d,0xd,0xb,0x7,0x0,/*14 IX*/    0x12,0x31,0x3e,0xc,0xb,0x5,0x0,/*15 ER*/
     0xe,0x24,0x52,0xf,0xc,0x1,0x0,/*16 UX*/    0x12,0x1e,0x58,0xf,0xc,0x0,0x0,/*17 OH*/
    0x12,0x33,0x3e,0xd,0xc,0x6,0x0,/*18 RX*/    0x10,0x25,0x6e,0xd,0x8,0x1,0x0,/*19 LX*/
     0xd,0x1d,0x50,0xd,0x8,0x0,0x0,/*20 WX*/     0xf,0x45,0x5d,0xe,0xc,0x7,0x0,/*21 YX*/
     0xb,0x18,0x5a,0xd,0x8,0x0,0x0,/*22 WH*/    0x12,0x32,0x3c,0xc,0xa,0x5,0x0,/*23 R*/
     0xe,0x1e,0x6e,0xd,0x8,0x1,0x0,/*24 L*/      0xb,0x18,0x5a,0xd,0x8,0x0,0x0,/*25 W*/
     0x9,0x53,0x6e,0xd,0xa,0x8,0x0,/*26 Y*/      0x6,0x2e,0x51,0xc,0x3,0x0,0x0,/*27 M*/
     0x6,0x36,0x79,0x9,0x9,0x0,0x0,/*28 N*/      0x6,0x56,0x65,0x9,0x6,0x3,0x0,/*29 NX*/
     0x6,0x36,0x79,0x0,0x0,0x0,0x0,/*30 DX*/    0x11,0x43,0x5b,0x0,0x0,0x0,0x0,/*31 Q*/
     0x6,0x49,0x63,0x7,0xa,0xd,0xf,/*32 S*/      0x6,0x4f,0x6a,0x0,0x0,0x0,0x0,/*33 SH*/
     0x6,0x1a,0x51,0x3,0x3,0x3,0xf,/*34 F*/      0x6,0x42,0x79,0x0,0x0,0x0,0x0,/*35 TH*/
     0xe,0x49,0x5d,0x0,0x0,0x0,0x0,/*36 /H*/    0x10,0x25,0x52,0x0,0x0,0x0,0x0,/*37 /X*/
     0x9,0x33,0x5d,0xf,0x3,0x0,0x3,/*38 Z*/      0xa,0x42,0x67,0xb,0x5,0x1,0x0,/*39 ZH*/
     0x8,0x28,0x4c,0xb,0x3,0x0,0x0,/*40 V*/      0xa,0x2f,0x5d,0xb,0x4,0x0,0x0,/*41 DH*/
     0x6,0x4f,0x65,0x0,0x0,0x0,0x0,/*42 CHa*/    0x6,0x4f,0x65,0x0,0x0,0x0,0x0,/*43 CHb*/
     0x6,0x42,0x79,0x1,0x0,0x0,0x0,/*44 Ja*/     0x5,0x42,0x79,0x1,0x0,0x0,0x0,/*45 Jb*/
     0x6,0x6e,0x79,0x0,0xa,0xe,0x0,/*46 Jc*/     0x0, 0x0, 0x0,0x2,0x2,0x1,0x0,/*47 Jd*/
    0x13,0x48,0x5a,0xe,0xe,0x9,0x0,/*48 EY*/    0x1b,0x27,0x58,0xf,0xd,0x1,0x0,/*49 AY*/
    0x15,0x1f,0x58,0xf,0xc,0x0,0x0,/*50 OY*/    0x1b,0x2b,0x58,0xf,0xd,0x1,0x0,/*51 AW*/
    0x12,0x1e,0x58,0xf,0xc,0x0,0x0,/*52 OW*/     0xd,0x22,0x52,0xd,0x8,0x0,0x0,/*53 UW*/
     0x6,0x1a,0x51,0x2,0x0,0x0,0x0,/*54 Ba*/     0x6,0x1a,0x51,0x4,0x1,0x0,0xf,/*55 Bb*/
     0x6,0x1a,0x51,0x0,0x0,0x0,0x0,/*56 Bc*/     0x6,0x42,0x79,0x2,0x0,0x0,0x0,/*57 Da*/
     0x6,0x42,0x79,0x4,0x1,0x0,0xf,/*58 Db*/     0x6,0x42,0x79,0x0,0x0,0x0,0x0,/*59 Dc*/
     0x6,0x6e,0x70,0x1,0x0,0x0,0x0,/*60 Ga*/     0x6,0x6e,0x6e,0x4,0x1,0x0,0xf,/*61 Gb*/
     0x6,0x6e,0x6e,0x0,0x0,0x0,0x0,/*62 Gc*/     0x6,0x54,0x5e,0x1,0x0,0x0,0x0,/*63 GXa*/
     0x6,0x54,0x5e,0x4,0x1,0x0,0xf,/*64 GXb*/    0x6,0x54,0x5e,0x0,0x0,0x0,0x0,/*65 GXc*/
     0x6,0x1a,0x51,0x0,0x0,0x0,0x0,/*66 Pa*/     0x6,0x1a,0x51,0x0,0x0,0x0,0x0,/*67 Pb*/
     0x6,0x1a,0x51,0x0,0x0,0x0,0x0,/*68 Pc*/     0x6,0x42,0x79,0x0,0x0,0x0,0x0,/*69 Ta*/
     0x6,0x42,0x79,0x0,0x0,0x0,0x0,/*70 Tb*/     0x6,0x42,0x79,0x0,0x0,0x0,0x0,/*71 Tc*/
     0x6,0x6d,0x65,0x0,0x0,0x0,0x0,/*72 Ka*/     0xa,0x56,0x65,0xc,0xa,0x7,0x0,/*73 Kb*/
     0xa,0x6d,0x70,0x0,0x0,0x0,0x0,/*74 Kc*/     0x6,0x54,0x5e,0x0,0x0,0x0,0x0,/*75 KXa*/
     0x6,0x54,0x5e,0x0,0xa,0x5,0x0,/*76 KXb*/    0x6,0x54,0x5e,0x0,0x0,0x0,0x0 /*77 KXc*/
  };  
  
  frameTime = 15;
  noise = 0;
  
  /*
  
    When you create a word, here is the structure :
    {"Number of sounds" , "First sound index" , "First sound duration", "First sound transition", "Second sound index", "Second sound duration", "Second sound transition"....}
    The sound and transition durations are multiples of 15 ms. So a sound with a duration value of "10" lasts 150 ms. Same thing for transition.
  
  */
  
  
  frameList[0]  = { 8, _Pa,10,0, _Pb,10,0, _Pc,5,0, _AH,15,0, _NN,10,0, _Ka,1,0, _Kb,1,0, _Kc,1,0 }; // Punk
  frameList[1]  = { 11 ,_SS,10,0, _Ta,5,0, _Tb,5,0, _Tc,5,0, _AH,20,0, _NN,5,0, _Ta,5,0, _Tb,5,0, _Tc,5,0, _IY,30,0, _NN,5,0 }; // Stuntin
  frameList[2]  = { 5,_Da,3,0,_Db,1,0,_Dc,4,3,_EY,25,8,_F,20,0}; // Def
  frameList[3]  = { 8, _AO,20,0, _Da,3,0, _Db,1,0, _Dc,4,0, _Ja,2,0, _Jb,2,0, _Jc,4,0, _IY,25,0 }; // O.G.
  frameList[4]  = { 9, _Pa,1,0, _Pb,2,0, _Pc,2,5, _LL,6,0, _EY,15,0, _IY,8,0, _AE,20,0, _RR,3,0, _ZZ,10,0 }; // Players
  frameList[5]  = { 9, _RR,5,0,_AA,15,8,_Ba,2,0,_Bb,2,0,_Bc,2,0,_AA,30,8,_Ta,2,0,_Tb,2,0,_Tc,2,0 }; // Robot
  frameList[6]  = { 2, _ZZ,10,5,_AE,20,0 }; // The
  frameList[7]  = { 4, _Ta,5,0,_Tb,5,0,_Tc,5,5,_UH,20,0 }; // To
  
  triggered = false; 
  word_selection = 0;
  soundPos = 0;
  soundnumber = frameList[word_selection][0]; 
  soundchrono = frameList[word_selection][2]*600;
  tween = 0;
  tween_mode = false;

  word_input = NULL;
  pitch_input = NULL;
  formant_scale_input = NULL;   
  trigger_input = NULL;   
}


uint32_t ModuleChatBot::compute()
{
  
  uint32_t pitch_input   = readInput(this->pitch_input, CONVERT_TO_6_BIT); // Range: 0 - 63
  uint32_t formant_scale = readInput(this->formant_scale_input,  CONVERT_TO_7_BIT); // Range: 0 - 127
  uint32_t trigger       = readInput(this->trigger_input);
  
  int8_t value = 0;
  
  // if((trigger < MID_CV) && triggered) triggered = false;
  
  if(trigger > MID_CV && !triggered) 
  {
    triggered = true; 
    soundPos = 0; 
    word_selection = readInput(this->word_input, CONVERT_TO_3_BIT); // Range: 0 - 7
    soundnumber = frameList[word_selection][0]; 
    soundchrono = frameList[word_selection][2]*600;
    tween = tween_start =  frameList[word_selection][3];
    tween_mode = false;    	
  }
  
  if(triggered)
  {
    if(!tween_mode)
    {
      uint32_t sound = frameList[word_selection][soundPos*3+1];
    
      // parameters update
      uint8_t formantPos;
      pitchPhaseInc = pitchTable[pitch_input];
      formantPos = sound * FORMANT_SZ;
      form1PhaseInc = formantTable[formantPos] * formant_scale;
      form2PhaseInc = formantTable[formantPos+1] * formant_scale;
      form3PhaseInc = formantTable[formantPos+2] * formant_scale;
      form1Amp = formantTable[formantPos+3];
      form2Amp = formantTable[formantPos+4];
      form3Amp = formantTable[formantPos+5];
      noiseMod = formantTable[formantPos+6]; 
    }
    else // if tween mode
    {
      uint32_t sound = frameList[word_selection][soundPos*3+1];
      uint32_t sound_next = frameList[word_selection][soundPos*3+4];
      
      // parameters update
      
      uint8_t formantPos;
      uint8_t formantPos_next;
	  
      pitchPhaseInc = pitchTable[pitch_input];
	  
      formantPos = sound * FORMANT_SZ;
      formantPos_next = sound_next * FORMANT_SZ;
	  
      form1PhaseInc = (formantTable[formantPos] * formant_scale * tween / tween_start) + (formantTable[formantPos_next] * formant_scale * (tween_start - tween) / tween_start);
      form2PhaseInc = (formantTable[formantPos+1] * formant_scale * tween / tween_start) + (formantTable[formantPos_next+1] * formant_scale * (tween_start - tween) / tween_start);
      form3PhaseInc = (formantTable[formantPos+2] * formant_scale * tween / tween_start) + (formantTable[formantPos_next+2] * formant_scale * (tween_start - tween) / tween_start);
      form1Amp = (formantTable[formantPos+3] * tween / tween_start) + (formantTable[formantPos_next+3] * (tween_start - tween) / tween_start);
      form2Amp = (formantTable[formantPos+4] * tween / tween_start) + (formantTable[formantPos_next+4] * (tween_start - tween) / tween_start);
      form3Amp = (formantTable[formantPos+5] * tween / tween_start) + (formantTable[formantPos_next+5] * (tween_start - tween) / tween_start);
      noiseMod = (formantTable[formantPos+6] * tween / tween_start) + (formantTable[formantPos_next+6] * (tween_start - tween) / tween_start);
    }     
    
    int16_t phaseNoise = noise * noiseMod;
    noise += noise << 2; 
    noise++;
    
    form1Phase += form1PhaseInc;
    value = pgm_read_byte(sinCalc+(((form1Phase>>8) & 0xf0) | form1Amp));
    
    form2Phase += form2PhaseInc;
    value += pgm_read_byte(sinCalc+(((form2Phase>>8) & 0xf0) | form2Amp));
    
    form3Phase += form3PhaseInc;
    value += pgm_read_byte(sqrCalc+(((form3Phase>>8) & 0xf0) | form3Amp));
    
    value = (value * (0xff^(pitchPhase>>8)))>>8;
    pitchPhase += pitchPhaseInc;
    
    if ((pitchPhase+phaseNoise) < pitchPhaseInc) {
      form1Phase = 0;
      form2Phase = 0;
      form3Phase = 0;
    }
    
    soundchrono--;
    
    if(soundchrono <= 0) 
    {
      if(tween <= 0)
      {
        soundPos ++;
  
        // If the word has been spoken, the start speaking a new one right away.
        if(soundPos >= soundnumber)
        {
          triggered = false;
        }
        else
        {
          soundchrono = frameList[word_selection][soundPos*3+2]*600;
          tween = tween_start = frameList[word_selection][soundPos*3+3];
          tween_mode = false;          
        }      
      }
      else
      {
        soundchrono = 600;
	tween_mode = true;
	tween--;
      }      
    }
    
  }
  
  return(((int)value + 0x80) << 5);
}
