#include "Arduino.h"
#include "ModuleSwitch.h"
#include "defines.h"

ModuleSwitch::ModuleSwitch()
{
}

uint32_t ModuleSwitch::compute()
{  
  // Serial.println(this->readInput(select_input));

  if(this->readInput(select_input) >= MID_CV)
  {
    return(this->readInput(b_input));
  }
  else
  {
    return(this->readInput(a_input));
  }
}
