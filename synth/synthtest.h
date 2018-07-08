#ifndef SYNTHTEST_H
#define SYNTHTEST_H
#include "Synth.h"
#include "ModuleConstant.h"
#include "ModuleWavetableOsc.h"
#include "ModuleLowpassFilter.h"

class SynthTest : public Synth
{
public:
    ModuleConstant param[8];

    SynthTest()
    {
//         eq = new EquationBankSobek();
//         beatbyte = new ModuleEquationPlayer(eq);
//        ModuleFreeze *freeze = new ModuleFreeze();
        ModuleDelay *delay = new ModuleDelay();
        ModuleWavetableOsc *osc1 = new ModuleWavetableOsc();
        ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();


//        param[0].setValue(10);
//        param[1].setValue(19000);
//        param[2].setValue(1000);
//                param[0].setValue(1);
//                param[7].setValue(10);

        osc1->frequency_input = &param[0];
        osc1->wavetable_input = &param[1];
//        freeze->audio_input = osc1;
//        freeze->length_input = &param[1];


        lowpass_filter->audio_input = osc1;
        lowpass_filter->cutoff_input = &param[5];
        lowpass_filter->resonance_input = &param[6];


//        wave->audio_input = osc1;
//        wave->mix_input =  &param[6];
//        wave->waveshaper_input =  &param[7];

        delay->audio_input = lowpass_filter;
        delay->feedback_input = &param[2];
        delay->length_input = &param[3];
        delay->mix_input = &param[4];

//        wave->audio_input = osc1;
//        wave->mix_input = &param[1];
//        wave->waveshaper_input = &param[2];

        this->last_module = delay;


//        beatbyte->param1_input = &param[0];
//        beatbyte->param2_input = &param[1];
//        beatbyte->param3_input = &param[2];
//        beatbyte->equation_input = &param[3];
//        beatbyte->sample_rate_input = &param[4];


//        this->last_module = osc1;

    }
};
#endif // SYNTHTEST_H
