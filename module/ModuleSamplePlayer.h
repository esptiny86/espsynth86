/*
 *
 *      Module Sample Player
 *
 *
 */
 
#ifndef ModuleSamplePlayer_h
#define ModuleSamplePlayer_h

#include "Module.h"
#include "drum_sampler.h"

struct sample_data {
    const uint16_t * sample_loc;
    unsigned long length;
};

class ModuleSamplePlayer : public Module
{
  public:
    ModuleSamplePlayer();
    Module *trigger_input;
    Module *sample_select;
    uint16_t compute();
  private:
    bool clocked;
    uint32_t counter;
    sample_data sample[11] =
    {
        {BD16, BD16LEN},
        {CP16, CP16LEN},
        {CR16, CR16LEN},
        {HH16, HH16LEN},
        {HT16, HT16LEN},
        {LT16, LT16LEN},
        {MT16, MT16LEN},
        {OH16, OH16LEN},
        {RD16, RD16LEN},
        {RS16, RS16LEN},
        {SD16, SD16LEN}
    };
};

#endif
