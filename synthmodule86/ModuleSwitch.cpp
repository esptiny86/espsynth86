#include "Arduino.h"
#include "ModuleSwitch.h"
#include "Defines.h"

uint16_t ModuleSwitch::compute()
{  
  if(this->readInput(select_input) >= MID_CV)
  {
    return(this->readInput(b_input));
  }
  else
  {
    return(this->readInput(a_input));
  }
}
