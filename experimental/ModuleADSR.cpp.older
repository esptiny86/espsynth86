#include "Arduino.h"
#include "ModuleADSR.h"
#include "Defines.h"

ModuleADSR::ModuleADSR()
{
  this->output = 0;
  this->state = ADSR_INACTIVE;
  this->set(ADSR_PRESET_BLIP); // default ADSR durations
  this->triggered = false;  

  this->trigger_input = NULL;
}

ModuleADSR::ModuleADSR(uint32_t attack_time, uint32_t decay_time, uint32_t sustain, uint32_t release_time)
{
  this->output = 0;
  this->state = ADSR_INACTIVE;
  this->triggered = false;  
  this->set(attack_time, decay_time, sustain, release_time);
}

// 4 parameters to compute :
//
// A - attack time (time to reach 100% volume) 
// D - decay time (the time that the sound goes from 100% to sustain value)
// S - sustain value (the value where the sound must stop if the sound stay trigged) - % of the volume
// R - release time (time to go from sustain value to 0)


// The fixed point will be fixed at 19 bits.

// The parameters can be calculated like this : time (seconds) = parameter / 410

void ModuleADSR::set(uint32_t attack_time, uint32_t decay_time, uint32_t sustain, uint32_t release_time)
{
  this->attack_time = 4874/(attack_time+1); // 2.5 ms to 10 s
  this->sustain = sustain<<7; // convert to 19 bits
  this->decay_time = (524288 - this->sustain)/((decay_time+1)*107); // 2.5 ms to 10s
  this->release_time = (this->sustain * 4874/(release_time+1))>>19; // 2.5 ms to 10s
}


void ModuleADSR::setAttackTime(uint32_t value)
{
  this->attack_time = 4874/(value+1);
}

void ModuleADSR::setDecayTime(uint32_t value)
{
  this->decay_time = (524288-sustain)/((value+1)*107); 
}

void ModuleADSR::setSustain(uint32_t value)
{
  this->sustain = value << 7; // convert from 12 bits to 19 bits
}

void ModuleADSR::setReleaseTime(uint32_t value)
{
  this->release_time = (sustain*4874/(value+1))>>19;
}


uint32_t ModuleADSR::compute()
{
  uint32_t trigger = readInput(this->trigger_input);
  
  if((trigger >= MID_CV) && !triggered) 
  {
    triggered = true;
    state = ADSR_ATTACK;
  }

  // Is this correct?  Is it good to immediately skip to the
  // resease state when the trigger input falls?  Or, would it
  // be better to allow attack and decay to complete first?
  
  if((trigger < MID_CV) && triggered) 
  {
    triggered = false;
    state = ADSR_RELEASE;
  }

    
  switch(this->state)
  {
    case ADSR_ATTACK: 
    
      if(output >= 524288) // the volume reaches 100 % volume (19 bits)
      {
        state = ADSR_DECAY; 
      }
      else
      {
        if((output + attack_time) > 524288)
        {
          output = 524288;
        }
        else
        {
          output += attack_time; // increase the volume until 100 %
        }
      }
      break;    
      
    case ADSR_DECAY:
	
      // Decrease the volume until sustain value is reached
      if(output >= decay_time)
      {
        output -= decay_time;
      }
      else
      {
        output = 0;
      }
	  
      if(output <= sustain)
      {
        state = ADSR_SUSTAIN;
        output = sustain;
      }
      break;

    // Do nothing in the sustain case. The sound stays played until the trigger is trigged off
	  
    case ADSR_RELEASE:
      
      // Decrease the output until 0 is reached

      // testing
      // release_time = 1;

      if(output >= release_time)
      {
        output -= release_time;       
      }
      else
      {
        state = ADSR_INACTIVE;
        output = 0;
      }
      
      break;
      
  } // end switch
  
  return (output >> 7); 
}


