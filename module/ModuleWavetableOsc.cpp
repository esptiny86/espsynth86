#include "Arduino.h"
#include "ModuleWavetableOsc.h"
#include "defines.h"
#include "GlobalWavetables.h"
#include "GlobalIncrements.h"
#include "globalwavetable.h"

ModuleWavetableOsc::ModuleWavetableOsc()
{
  fixed_point_10_22_index = 0;
  phase = 0;

  // Initialize all inputs
  this->frequency_input = NULL;
  this->wavetable_input = NULL;
  this->module_output_bit = OUTPUT_16BIT;
}

uint16_t ModuleWavetableOsc::compute()
{
  // Read the frequency
  frequency = this->readInput(frequency_input);
  wavetable = this->readInput10Bit(wavetable_input,0,4);

//  /*phase*/ = phase + frequency;
  // Read the wavetable input and map it to the appropriate range
//  wavetable = this->readInput(wavetable_input, 0, NUMBER_OF_WAVETABLES);

//  // Calculate the index into the wavetable
  fixed_point_10_22_index += INCREMENTS[frequency] >> 2;
  if(fixed_point_10_22_index > WAVE_SAMPLES_SHIFTED_22) fixed_point_10_22_index -= WAVE_SAMPLES_SHIFTED_22;

  wavetable_index = fixed_point_10_22_index >> 22; // This should yeald a value between 0 and WAVE_SAMPLES (512)

  // This output will range from 0 to 4080 (which is a 12-bit value)

//    return((((wavetable_index&0b11011101)<<8)+0x8000)^0x8000);

   if(wavetable == 0)
   {
       //sine
       return(((sine[wavetable_index]))^0x8000);
   }
   else if(wavetable == 1)
   {
       //square
       return((((wavetable_index&0x80)<<8)+0x4000)^0x8000);
   }
   else if(wavetable == 2)
   {
       //tri
       return((((wavetable_index&0b11111111)<<8)+0x8000)^0x8000);
       //       return((((wavetable_index&0b11111111)<<7)+16384));
   }
   else if(wavetable == 3)
   {
       //sine low
//       return( ((((((sine[wavetable_index])^0x8000))>>1)+16384))^16384);

       //always start from zero or trouble!!
//       int32_t tmp = ((((sine[wavetable_index]^0x8000)) - 0x8000)>> 1 )+ 0x8000;
//        return tmp;
       return ((((sine[wavetable_index]^0x8000)) - 0x8000)>> 1 )+ 0x8000;

   }
   else{
       //strange
       return( ((sine[wavetable_index]^0x8000)>>1)+24576 );

   }

}
