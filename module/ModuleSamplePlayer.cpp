#include "ModuleSamplePlayer.h"
#include "defines.h"

ModuleSamplePlayer::ModuleSamplePlayer()
{

  this->counter = 0;  
  this->clocked = false;

  this->trigger_input = NULL;
  this->sample_select = NULL;

}

uint16_t ModuleSamplePlayer::compute()
{

    uint16_t clock = this->readInput(trigger_input);
    uint16_t samp_sel = constrain(this->readInput(sample_select,0,10),0,10) ;

    if (clocked == false && clock >= MAX_CV)
    {
        clocked = true;
        this->counter = 0;
    }

    if (clocked == true && clock < MAX_CV)
        clocked = false;

    if (this->counter<this->sample[samp_sel].length)
        return (pgm_read_word_near(this->sample[samp_sel].sample_loc + this->counter++)^32768);
    else
        return(0x8000);

}
