#include "ModuleEuclideanSeq.h"
#include "EuclidBjork.h"
#include "Defines.h"

// Todo: fix loop overflow

ModuleEuclideanSeq::ModuleEuclideanSeq()
{

    curstep = 0;
    pattern = 0;
    stepsize = 1;
    beatnum = 0;
    offsetnum = 0;
    counter = 0;
    clocked = false;
    rollback = false;

    this->beat_input = NULL;
    this->clock_input = NULL;
    this->offset_input = NULL;
    this->step_input = NULL;

    this->eu_beat.prevValue = 0;
    this->eu_step.prevValue = 0;
    this->eu_offset.prevValue = 0;

    this->setPattern(16,0);

}

uint16_t ModuleEuclideanSeq::compute()
{
    uint32_t clock = this->readInput(clock_input);

    this->eu_beat.value = this->readInput(beat_input, 0,16);
    this->eu_step.value = this->readInput(step_input, 0,16);
    this->eu_offset.value = this->readInput(offset_input, 0,16);

    if((clock < MID_CV) && clocked)
    {
        clocked = false;
    }

    //Change pattern when it receive high signal
    if((clock >= MID_CV) && !clocked)
    {
      clocked = true;
      counter = counter + 1;

      if(this->eu_beat.value != this->eu_beat.prevValue) {
          this->setBeat(this->eu_beat.value);
          this->eu_beat.prevValue = this->eu_beat.value;
      }

      if(this->eu_step.value != this->eu_step.prevValue) {
          this->setStep(this->eu_step.value);
          this->eu_step.prevValue = this->eu_step.value;
      }

      if(this->eu_offset.value != this->eu_offset.prevValue) {
          this->setOffset(this->eu_offset.value);
          this->eu_offset.prevValue = this->eu_offset.value;
      }

    }

    return getPatternTick(counter) * MAX_CV;

}

void ModuleEuclideanSeq::setPattern(uint8_t step, uint8_t beat, uint8_t offset)
{
    stepsize = step;
    beatnum = beat;
    offsetnum = offset;
    pattern = euclidean_arr(step, beat, offset);
}

void ModuleEuclideanSeq::setPattern(uint8_t step, uint8_t beat)
{
    setPattern(step,beat,0);
}

void ModuleEuclideanSeq::setBeat(uint8_t beat)
{
    if (beat>stepsize) stepsize = beat;
    setPattern(stepsize, beat, offsetnum);
}

void ModuleEuclideanSeq::setStep(uint8_t step)
{
    if (beatnum>step) beatnum = step;
    setPattern(step, beatnum, offsetnum);
}

void ModuleEuclideanSeq::setOffset(uint8_t offset)
{
    setPattern(stepsize, beatnum, offset);
}

void ModuleEuclideanSeq::setRollback()
{
    rollback = true;
}

uint32_t ModuleEuclideanSeq::nextPattern()
{
    uint32_t pat = getPattern(curstep);
    curstep++;
    if (curstep> (stepsize-1) ) curstep = 0;
    return pat;
}

uint32_t ModuleEuclideanSeq::getPattern(uint8_t step)
{
    return (pattern & (1<<step));
}

uint32_t ModuleEuclideanSeq::getPatternTick(uint32_t step)
{
    if (rollback){
       curstep = (curstep+1)%stepsize;
       rollback = false;
    }else{
       curstep = step%stepsize;
    }
    return (pattern & (1<<curstep));
}

