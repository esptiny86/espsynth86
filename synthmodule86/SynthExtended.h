#ifndef SYNTHEXTENDED_H
#define SYNTHEXTENDED_H

#include "Synth.h"
#include "ModuleExternalInput.h"

class SynthExtended : public Synth
{
public:
    Input_Manager inputManager;
    virtual void defineSynth(Input_Manager * inputManager);
    void setup();
};

#endif // SYNTHEXTENDED_H
