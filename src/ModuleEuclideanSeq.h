#ifndef MODULEEUCLIDEANSEQUENCER_H
#define MODULEEUCLIDEANSEQUENCER_H

#include "Arduino.h"
#include "Module.h"

struct ModuleEuclidValue {
  uint8_t value;
  uint8_t prevValue;
};

class ModuleEuclideanSeq : public Module
{
public:
    ModuleEuclideanSeq();
    void setPattern(uint8_t step, uint8_t beat, uint8_t offset);
    void setPattern(uint8_t step, uint8_t beat);
    void setBeat(uint8_t beat);
    void setStep(uint8_t step);
    void setOffset(uint8_t offset);
    void setRollback();

    uint32_t nextPattern();
    uint32_t getPattern(uint8_t step);
    uint32_t getPatternTick(uint32_t step);

    uint16_t compute();

    // inputs
    Module *clock_input;
    Module *step_input;
    Module *beat_input;
    Module *offset_input;

    ModuleEuclidValue eu_step;
    ModuleEuclidValue eu_beat;
    ModuleEuclidValue eu_offset;

private:
    uint32_t pattern;
    uint32_t counter;

    uint8_t stepsize;
    uint8_t beatnum;
    uint8_t offsetnum;
    uint8_t curstep;

    bool rollback;
    bool clocked;
};

#endif // MODULEEUCLIDEANSEQUENCER_H
