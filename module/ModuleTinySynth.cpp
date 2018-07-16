#include "ModuleTinySynth.h"
#include "defines.h"
#include "GlobalChords.h"
#include "GlobalWavetables.h"
#include "GlobalIncrements.h"
#include "globalwavetable.h"

ModuleTinySynth::ModuleTinySynth(const char * ample)
{
  this->counter = 0;  
  this->clocked = false;

  this->trigger_input = NULL;
  this->module_output_bit = OUTPUT_16BIT;

  this->Tune = ample;

    ch1 = new ModuleOutput(this);
    ch2 = new ModuleOutput(this);
    ch3 = new ModuleOutput(this);
    ch4 = new ModuleOutput(this);

    ch1->module_output_bit = OUTPUT_16BIT;
    ch2->module_output_bit = OUTPUT_16BIT;
    ch3->module_output_bit = OUTPUT_16BIT;
    ch4->module_output_bit = OUTPUT_16BIT;

}

uint16_t ModuleTinySynth::compute()
{


    uint16_t clock = this->readInput(trigger_input);

    if (clocked == false && clock >= MAX_CV)
    {
        clocked = true;
        this->counter++;
        //send trigger here..
    }

    if (clocked == true && clock < MAX_CV)
    {
        clocked = false;
    }



    int8_t Sign = 0, Number = 0, Chan = 0, SaveIndex = 0, SaveOctave = 0;
    char Symbol;
    boolean More = 1, ReadNote = 0, Bra = 0, SetOctave = 0;

    if (this->counter > NextTick){
        do {
            do { // Skip formatting characters
              if(TunePtr > (strlen(Tune)-1) )
              {
                  TunePtr = 0;
                  Freqs[0] = 0;
                  Freqs[1] = 0;
                  Freqs[2] = 0;
                  Freqs[3] = 0;
                  Acc[0] = 0;
                  Acc[1] = 0;
                  Acc[2] = 0;
                  Acc[3] = 0;
                  Octave = 0;
                  LastIndex = 0;
                  Duration = 4;
              }

              Symbol = (Tune[TunePtr++]);
            } while ((Symbol == ' ') || (Symbol == '|'));
            int CapSymbol = Symbol & 0x5F;
            if (Symbol == '(') { Bra = 1; SaveIndex = LastIndex; SaveOctave = Octave; }
            else if (ReadNote && !Bra) More = 0;
            else if (Symbol == ')') { Bra = 0; LastIndex = SaveIndex; Octave = SaveOctave; }
            else if (Symbol == 0) for (;;) ;          // End of string - stop
            else if (Symbol == ',') { Duration = Number; Number = 0; Sign = 0; }
            else if (Symbol == ':') {
              SetOctave = 1; Octave = Number;
              if (Sign == -1) Octave = -Octave;
              Number = 0; Sign = 0;
            }
            else if ((Symbol >= '0') && (Symbol <= '9')) Number = Number*10 + Symbol - '0';
            else if (Symbol == '<') Octave--;
            else if (Symbol == '>') Octave++;
            else if (Symbol == '-') Sign = -1;
            else if (Symbol == '+') Sign = 1;
            else if (Symbol == '/') ReadNote = 1;
            else if (Symbol == '^') { Acc[Chan] = Silence; Freqs[Chan++] = 0; ReadNote = 1; }
            else if ((CapSymbol >= 'A') && (CapSymbol <= 'G')) {
              boolean Lowercase = (Symbol & 0x20);
              int Index = (((CapSymbol - 'A' + 5) % 7) << 1) + 1 + Sign;
              if (!SetOctave) {
                if (LastIndex && (Index < LastIndex) && !Lowercase) Octave++;
                if (LastIndex && (Index > LastIndex) && Lowercase) Octave--;
              } else SetOctave = 0;
              Freqs[Chan++] = Scale[Index] >> (4 - Octave);
              LastIndex = Index;
              ReadNote = 1; Sign = 0;
            }
          } while (More);
        TunePtr--;
        NextTick = NextTick + Duration;
    }

    int8_t Mask, Temp, Sum=0;
    for (int c=0; c<4; c++) {
      Acc[c] = Acc[c] + Freqs[c];
      Temp = Acc[c] >> 8;
      Mask = Temp >> 15;
      Sum = Sum + ((char)(Temp ^ Mask) >> 1);
    }

    int32_t sound = ((Sum-127)*100)+0x8000;

//    this->ch1->value = sound;

//    return (( (pgm_read_word_near(sine + wavetable_index)^0x8000) - 0x8000)>> 1 ) + 0x8000;


    return sound;

//    while (Ticks() < NextTick);


}
