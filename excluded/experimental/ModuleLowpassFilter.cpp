#include "Arduino.h"
#include "ModuleLowpassFilter.h"
#include "Defines.h"

ModuleLowpassFilter::ModuleLowpassFilter()
{
  // Initialize all inputs
  this->audio_input = NULL; 
  this->cutoff_input = NULL;
  this->resonance_input = NULL;   

  b0=b1=b2=b3=b4=t1=t2=0;  
}

uint16_t ModuleLowpassFilter::compute()
{
  // Read inputs
  long audio = this->readInput(audio_input) - 2048;
  uint32_t cutoff = this->readInput(cutoff_input, CONVERT_TO_8_BIT);
  uint32_t resonance = this->readInput(resonance_input, CONVERT_TO_7_BIT);

  q = 256 - cutoff; 
      p = cutoff + ((((205 * cutoff)>>8) * q)>>8); 
      f = ((int)p<<1) - 256; 
      long temp1 = (q * q)>>8;
      temp1 = (1434 * temp1)>>8;
      temp1 = temp1 + 256 - q;
      temp1 = (temp1*q)>>8;
      temp1 = temp1>>1;
      temp1 += 256;
      q = (temp1*resonance)>>8;
	  
	  audio -= (q * b4)>>8;                          //feedback 
      t1 = b1; 
      b1 = (((audio + b0) * p)>>8) - ((b1 * f)>>8); 
   
      t2 = b2; 
      b2 = (((b1 + t1) * p)>>8) - ((b2 * f)>>8); 
      t1 = b3; 
      b3 = (((b2 + t2) * p)>>8) - ((b3 * f)>>8); 
      b4 = (((b3 + t1) * p)>>8) - ((b4 * f)>>8); 
      b0 = audio; 
      return((uint32_t) (b4 + 2048));
}

