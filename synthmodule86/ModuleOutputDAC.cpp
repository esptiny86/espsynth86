#include "Arduino.h"
#include "ModuleOutputDAC.h"
#include "Defines.h"

I2SClass * ModuleOutputDAC::I2S = NULL;

ModuleOutputDAC::ModuleOutputDAC()
{
  if (I2S == NULL)
  {
      I2S = new I2SClass();
      I2S->begin(I2S_LEFT_JUSTIFIED_MODE, 44100, 16);
  }
}

uint16_t ModuleOutputDAC::compute()
{
    // this->value is the value at this output node
    uint32_t inputl = this->readInput(left);
    uint32_t inputr = this->readInput(right);

    I2S->write(inputl, inputr);

    return(0);
}
