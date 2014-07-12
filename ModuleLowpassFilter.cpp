#include "Arduino.h"
#include "ModuleLowpassFilter.h"
#include "defines.h"
#include "GlobalFilterTables.h"

// Special thanks to Gaetan Ro for adapting this
// filter for the Equation Composer from
//
// http://www.musicdsp.org/showone.php?id=24

ModuleLowpassFilter::ModuleLowpassFilter()
{
  y1=y2=y3=y4=oldx=oldy1=oldy2=oldy3=0; 

  // Initialize all inputs
  this->audio_input = NULL; 
  this->cutoff_input = NULL;
  this->resonance_input = NULL;      
}


uint16_t ModuleLowpassFilter::compute()
{
  long audio = ((this->readInput(audio_input))<<1) - 4096;
  long cutoff = this->readInput(cutoff_input);
  long resonance = this->readInput(resonance_input, CONVERT_TO_11_BIT);
  long k,p,r,x,t,t2,t3;

  // LPF_P_TABLE is computed using:
  //-------------------------------
  // cutoff = cutoff * .9;  
  // p = (cutoff*(7373-((3277*cutoff)>>12)))>>12;

  p = (long) LPF_P_TABLE[cutoff];

  // LPF_T_TABLE is computed using:
  // ------------------------------
  // t = ((4096-p)*5678)>>12;
  // t = (long) LPF_T_TABLE[cutoff];

  // LPF_T2_TABLE is computed using:
  // -------------------------------
  // t2 = 49152+((t*t)>>12);

  t2 = (long) LPF_T2_TABLE[cutoff];

  // LPF_T3_TABLE is computed using:
  // t3 = (24576*t)>>12;

  t3 = (long) LPF_T3_TABLE[cutoff];


  r = resonance * (t2+t3)/(t2-t3);

  // Inverted feed back for corner peaking
  x = audio - ((r*y4)>>12);

  k = p+p-4095;

  // Four cascaded onepole filters (bilinear transform)
  y1=((x*p)>>12) + ((oldx*p)>>12) - ((k*y1)>>12);
  y2=((y1*p)>>12) + ((oldy1*p)>>12) - ((k*y2)>>12);
  y3=((y2*p)>>12) + ((oldy2*p)>>12) - ((k*y3)>>12);
  y4=((y3*p)>>12) + ((oldy3*p)>>12) - ((k*y4)>>12);

  // Clipper band limited sigmoid
  y4 = y4 - ((y4 * ((y4 * ((y4 * 683)>>12))>>12))>>12);    //clipping

  oldx = x;
  oldy1 = y1;
  oldy2 = y2;
  oldy3 = y3;
   
  return(((uint32_t) (y4 + 4096))>>1);
}