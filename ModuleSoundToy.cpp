#include "Arduino.h"
#include "ModuleSoundToy.h"
#include "defines.h"

ModuleSoundToy::ModuleSoundToy()
{
  frequency = 440;
  value = 2048;
  t = 0;

  // Initialize all inputs
  this->trigger_input = NULL;
  this->frequency_input = NULL;
  this->sound_input = NULL;  
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

      y0 = (fixed_point_math.sin_fix1212(12 * fixed_point_math.sin_fix1212(countw>>5))>>1) + (fixed_point_math.sin_fix1212(a1 * fixed_point_math.sin_fix1212((k1 * countw)>>16))>>1);
            
      inter1 = (fixed_point_math.square_fix1212(y0)); //y0*y0-k2
      inter2 = fixed_point_math.sin_fix1212((k3 * countw)>>16); //sin(k3 * w * t)
      
      y1 = (inter1 * inter2)>>12;
      y2 = (rand.random(2048) * fixed_point_math.exp_fix0912(count>>1))>>12;
      
      value = (y0 + y1 + y2)/3;
      value = (((value * fixed_point_math.exp_fix0912(count>>8))>>12) * fixed_point_math.exp_fix0912(2 * count>>8))>>12;

      break;

    case 1: // Piano 1
    
      count= (t<<16)/44100;
      countw = count * frequency;
      
      value  = (((2458 * fixed_point_math.sin_fix1212((countw)>>4))>>4)*fixed_point_math.exp_fix0912((52*countw)>>23))>>20;
      value += (((1229 * fixed_point_math.sin_fix1212((countw)>>3))>>4)*fixed_point_math.exp_fix0912((66*countw)>>23))>>20;
      value += (((410  * fixed_point_math.sin_fix1212((countw)>>2))>>4)*fixed_point_math.exp_fix0912((98*countw)>>23))>>20;
      
      value = (value>>1) + ((((((819 * value) >> 4) * value) >> 12) * value) >> 21);
      
      value = (value * (3686 + fixed_point_math.sin_fix1212(1024 + ((70*count)>>4))/10))>>12;
      
      value = ((value * fixed_point_math.exp_fix0912(22*(count>>7)))>>13) + value>>2;    

      break;      
  }
  
  t++;
  
  return(value);
}
