#include "Arduino.h"
#include "ModuleSoundToy.h"
#include "defines.h"

ModuleSoundToy::ModuleSoundToy()
{
  for(uint32_t i = 0; i < 1024; i++) 
  { 
    Sine[i] = (uint16_t)(2048*sin(PI*(float)i/2048.0));
  } 
  
  for(uint32_t i = 0; i < 4095; i++) 
  { 
    Exp[i] = (uint16_t)(4095*exp((float)i/-512.0));
  } 
  
  frequency = 440;
  value = 2048;
  t = 0;

  // Initialize all inputs
  this->trigger_input = NULL;
  this->frequency_input = NULL;
  this->sound_input = NULL;  
}

uint32_t ModuleSoundToy::exp_fix0912(uint32_t in)
{
  if(in<4096) return Exp[in];
  else return 1;
}

uint32_t ModuleSoundToy::sin_fix1212(uint32_t in)
{
  uint32_t out = 0;
  uint16_t x = in % 4096;
  if(x>=0 && x<1024) out = Sine[x] + 2048;
  if(x>=1024 && x<2048) out = Sine[2047-x] + 2048;
  if(x>=2048 && x<3072) out = -Sine[x-2048] + 2048;
  if(x>=3072 && x<4096) out = -Sine[4095-x] + 2048;
  
  // Out will always range between 0 and 4095, with the Sine wave centered at 2048
  return out;
}

uint32_t ModuleSoundToy::cos_fix1212(uint32_t in)
{
  return sin_fix1212(1024+in);
}

uint32_t ModuleSoundToy::square_fix1212(uint32_t in)
{
  if(in >= 2048) return (in*in>>12);
  else return (((4095-in)*(4095-in))>>12);
}

uint32_t ModuleSoundToy::saw_fix1212(uint32_t x,uint32_t a)
{
    uint32_t f = x % 4096;

    if(f < a) f = (f<<12)/a;
    else f = 4095 - ((f-a)<<12)/(4095-a);
    return f;
}


uint32_t ModuleSoundToy::compute()
{
  uint32_t count;
  uint32_t countw, k0, k1, k2, k3, a1, a2, y0, y1, y2, inter1, inter2;
  
  // Read inputs
  sound = this->readInput(sound_input);
  frequency = this->readInput(frequency_input);
  trigger = this->readInput(trigger_input);

  if((trigger >= MID_CV) && !old_trigger) 
  {
    old_trigger = true;
    t = 0;
  }  
  
  if(trigger < MID_CV) old_trigger = false;
  
  sound = 1;
  
  switch(sound)
  {
    
    case 0: // fm1

      count= (t<<16)/44100;
      countw = count * frequency;
  
      k0 = 2048;
      k1 = 614;
      k2 = 4301;
      k3 = 20;

      a1 = 8;
      a2 = 401;

      y0 = (sin_fix1212(12 * sin_fix1212(countw>>5))>>1) + (sin_fix1212(a1 * sin_fix1212((k1 * countw)>>16))>>1);
            
      inter1 = (square_fix1212(y0)); //y0*y0-k2
      inter2 = sin_fix1212((k3 * countw)>>16); //sin(k3 * w * t)
      
      y1 = (inter1 * inter2)>>12;
      y2 = (random(2048) * exp_fix0912(count>>1))>>12;
      
      value = (y0 + y1 + y2)/3;
      value = (((value * exp_fix0912(count>>8))>>12) * exp_fix0912(2 * count>>8))>>12;

      break;

    case 1: // Piano 1
    
      count= (t<<16)/44100;
      countw = count * frequency;
      
      value = (((2458 * sin_fix1212((countw)>>4))>>4)*exp_fix0912((52*countw)>>23))>>20;
      value += (((1229 * sin_fix1212((countw)>>3))>>4)*exp_fix0912((66*countw)>>23))>>20;
      value += (((410 * sin_fix1212((countw)>>2))>>4)*exp_fix0912((98*countw)>>23))>>20;
      
      value = (value>>1) + ((((((819 * value) >> 4) * value) >> 12) * value) >> 21);
      
      value = (value * (3686 + sin_fix1212(1024 + ((70*count)>>4))/10))>>12;
      
      value = ((value * exp_fix0912(22*(count>>7)))>>13) + value>>2;    

      break;      
  }
  
  t++;
  
  return(value);
}
