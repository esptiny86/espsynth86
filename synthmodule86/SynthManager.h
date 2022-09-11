#ifndef SYNTHMANAGER_H
#define SYNTHMANAGER_H

#include "Module.h"
#include "ModuleExternalInput.h"
#include "Vector.h"
#include "SynthExtended.h"
#include "AnalogMultiplexer.h"
#include "OSCBundleReader.h"

#define SAMPLINGFREQUENCY 44100 // 44100 Hz
#define NOISE 4 //Noise filter for multiplexer

class SynthManager
{
public:
    SynthManager();
    void attachOscReader(OSCBundleReader * osc_reader);
    void attachMultiplexer(AnalogMultiplexerPin * multi_plexer);

    void addSynth(SynthExtended * synth);
    void setSynth(int idx);
    void run();
private:
    Vector<SynthExtended*> synthCollection;
    AnalogMultiplexerPin *multiplexer;
    OSCBundleReader * oscReader;
    int index;
    void slowLoop();
};

#endif // SYNTHMANAGER_H
