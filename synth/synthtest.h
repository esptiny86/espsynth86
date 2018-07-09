#ifndef SYNTHTEST_H
#define SYNTHTEST_H
#include "Synth.h"
#include "ModuleConstant.h"
#include "ModuleWavetableOsc.h"
#include "ModuleLowpassFilter.h"
#include "ModuleLFO.h"

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
        ModuleWavetableOsc *osc2 = new ModuleWavetableOsc();

        ModuleWavetableOsc *lfo = new ModuleWavetableOsc();
        ModuleWavetableOsc *lfo2 = new ModuleWavetableOsc();

        ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
        ModuleLFO *lfo3 = new ModuleLFO();

//        param[0].setValue(10);
//        param[1].setValue(19000);
//        param[2].setValue(1000);
//                param[0].setValue(1);
//                param[7].setValue(10);

//        lfo3->frequency_input = &param[0];
//        lfo3->wavetable_input = &param[1];

//        lfo->frequency_input = lfo3;
//        lfo->wavetable_input = &param[2];

//        lfo2->frequency_input = new ModuleConstant(1);
//        lfo2->wavetable_input = new ModuleConstant(1);

//        osc1->frequency_input = lfo;
//        osc1->wavetable_input = &param[1];
////        freeze->audio_input = osc1;
////        freeze->length_input = &param[1];


//        lowpass_filter->audio_input = lfo;
//        lowpass_filter->cutoff_input = lfo3;
//        lowpass_filter->resonance_input = &param[6];


////        wave->audio_input = osc1;
////        wave->mix_input =  &param[6];
////        wave->waveshaper_input =  &param[7];

//        delay->audio_input = lowpass_filter;
//        delay->feedback_input = &param[7];
//        delay->length_input = &param[3];
//        delay->mix_input = &param[5];

//        wave->audio_input = osc1;
//        wave->mix_input = &param[1];
//        wave->waveshaper_input = &param[2];

//        this->last_module = lfo;


//        beatbyte->param1_input = &param[0];
//        beatbyte->param2_input = &param[1];
//        beatbyte->param3_input = &param[2];
//        beatbyte->equation_input = &param[3];
//        beatbyte->sample_rate_input = &param[4];


//        this->last_module = osc1;


          //crazy shit
        osc1->frequency_input = &param[0];
        osc1->wavetable_input = &param[1];


        osc2->frequency_input = osc1;
        osc2->wavetable_input = &param[2];
//        freeze->audio_input = osc1;
//        freeze->length_input = &param[1];


        lowpass_filter->audio_input = osc2;
        lowpass_filter->cutoff_input = &param[5];
        lowpass_filter->resonance_input = &param[6];


//        wave->audio_input = osc1;
//        wave->mix_input =  &param[6];
//        wave->waveshaper_input =  &param[7];

        delay->audio_input = lowpass_filter;
        delay->feedback_input = &param[7];
        delay->length_input = &param[3];
        delay->mix_input = &param[4];

//        wave->audio_input = osc1;
//        wave->mix_input = &param[1];
//        wave->waveshaper_input = &param[2];

        this->last_module = delay;





    }
};
#endif // SYNTHTEST_H
