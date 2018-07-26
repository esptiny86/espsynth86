#ifndef SYNTHTEST_H
#define SYNTHTEST_H
#include "Synth.h"
//#include "ModuleConstant.h"
//#include "ModuleWavetableOsc.h"
//#include "ModuleLowpassFilter.h"
//#include "ModuleLFO.h"
//#include "ModuleMixer2.h"
//#include <ModuleBitReducer.h>
//#include <ModuleClock.h>
//#include <ModuleClockDivider.h>
//#include <ModuleMixer3.h>
//#include <ModuleReverb.h>
//#include <ModuleSamplePlayer.h>
//#include <ModuleVCA.h>
//#include <ModuleTinySynth.h>
//#include <Sample1.h>

#include "Modules.h"
#include <ModuleSamplePlayer.h>

class SynthTest : public Synth
{
public:
    ModuleConstant param[8];

    SynthTest()
    {
//         eq = new EquationBankSobek();
//         beatbyte = new ModuleEquationPlayer(eq);
//        ModuleFreeze *freeze = new ModuleFreeze();
//        ModuleDelay *delay = new ModuleDelay();
//        ModuleWavetableOsc *osc1 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *osc2 = new ModuleWavetableOsc();

//        ModuleLowpassFilter *lowpass_filter = new ModuleLowpassFilter();
//        ModuleLFO *lfo = new ModuleLFO();

//        param[0].setValue(10);
//        param[1].setValue(19000);
//        param[2].setValue(1000);
//                param[0].setValue(1);
//                param[7].setValue(10);

//        lfo->frequency_input = &param[0];
//        lfo->wavetable_input = &param[7];

//        osc2->frequency_input = &param[0];
//        osc2->wavetable_input = &param[2];


//        osc1->frequency_input = lfo;
//        osc1->wavetable_input = &param[1];

//        lfo->frequency_input = &param[5];
//        lfo->wavetable_input = &param[7];
////        freeze->audio_input = osc1;
////        freeze->length_input = &param[1];


////        lowpass_filter->audio_input = osc1;
////        lowpass_filter->cutoff_input = &param[5];
////        lowpass_filter->resonance_input = &param[6];


////        wave->audio_input = osc1;
////        wave->mix_input =  &param[6];
////        wave->waveshaper_input =  &param[7];

//        delay->audio_input = osc1;
//        delay->feedback_input = &param[2];
//        delay->length_input = &param[3];
//        delay->mix_input = &param[4];

////        wave->audio_input = osc1;
////        wave->mix_input = &param[1];
////        wave->waveshaper_input = &param[2];

//        this->last_module = delay;


//        beatbyte->param1_input = &param[0];
//        beatbyte->param2_input = &param[1];
//        beatbyte->param3_input = &param[2];
//        beatbyte->equation_input = &param[3];
//        beatbyte->sample_rate_input = &param[4];

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA2MGUw
        IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiA2MGUwCm5vZGUvYWRkLWlubGV0IDYwZTAgYzBkNiBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IDYwZTAgaWgxNyBlc3Bu
        b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCA2MGUwIG8zNWIgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGo1YXggZXNwbm9kZS9kZWxheSBBdWRpbyUyMERlbGF5Cm5vZGUv
        dHVybi1vbiBqNWF4Cm5vZGUvYWRkLWlubGV0IGo1YXggOWw0YiBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApub2RlL2FkZC1pbmxldCBqNWF4IGx1cHEgZXNwbm9kZS9zdHJpbmcgbWl4X2lucHV0IG1peF9pbnB1dApub2RlL2FkZC1pbmxl
        dCBqNWF4IGs3cW0gZXNwbm9kZS9zdHJpbmcgZmVlZGJhY2tfaW5wdXQgZmVlZGJhY2tfaW5wdXQKbm9kZS9hZGQtaW5sZXQgajVheCB5aGlvIGVzcG5vZGUvc3RyaW5nIGxlbmd0aF9pbnB1dCBsZW5ndGhfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGo1YXggbWp5eiBl
        c3Bub2RlL3N0cmluZyBvdXQgb3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgaHBrdSBlc3Bub2RlL2RhYyBBdWRpbyUyMERBQwpub2RlL3R1cm4tb24gaHBrdQpub2RlL2FkZC1pbmxldCBocGt1IHcwYnIgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5w
        dXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBxenhiIGVzcG5vZGUvbGZvIExGJTIwT3NjaWxsYXRvcgpub2RlL3R1cm4tb24gcXp4Ygpub2RlL2FkZC1pbmxldCBxenhiIGJob2wgZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApub2Rl
        L2FkZC1pbmxldCBxenhiIGZwcW0gZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxlX2lucHV0IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgcXp4YiAzNnZoIGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCAycW0yIGVzcG5vZGUv
        bXVsdGlwbGV4ZXIgTXVsdGlwbGV4ZXIKbm9kZS90dXJuLW9uIDJxbTIKbm9kZS9hZGQtb3V0bGV0IDJxbTIgd3B0NyBlc3Bub2RlL3N0cmluZyBQb3QxIFBvdDEKbm9kZS9hZGQtb3V0bGV0IDJxbTIgYmZpbCBlc3Bub2RlL3N0cmluZyBQb3QyIFBvdDIKbm9kZS9h
        ZGQtb3V0bGV0IDJxbTIgZnJnaiBlc3Bub2RlL3N0cmluZyBQb3QzIFBvdDMKbm9kZS9hZGQtb3V0bGV0IDJxbTIgZ2NjbSBlc3Bub2RlL3N0cmluZyBQb3Q0IFBvdDQKbm9kZS9hZGQtb3V0bGV0IDJxbTIgZm1wcCBlc3Bub2RlL3N0cmluZyBQb3Q1IFBvdDUKbm9k
        ZS9hZGQtb3V0bGV0IDJxbTIgMnFyZCBlc3Bub2RlL3N0cmluZyBQb3Q2IFBvdDYKbm9kZS9hZGQtb3V0bGV0IDJxbTIgMHRnYSBlc3Bub2RlL3N0cmluZyBQb3Q3IFBvdDcKbm9kZS9hZGQtb3V0bGV0IDJxbTIgZ2dpciBlc3Bub2RlL3N0cmluZyBQb3Q4IFBvdDgK
        bm9kZS9tb3ZlIGxmZzQgMzAgMjAKbm9kZS9tb3ZlIDYwZTAgNzc2IDI2Nwpub2RlL21vdmUgajVheCAxMDIxIDQyMQpub2RlL21vdmUgaHBrdSAxMjUyIDQ0NQpub2RlL21vdmUgcXp4YiA0OTUgMjMwCm5vZGUvbW92ZSAycW0yIDMxOSAyOTkKb3V0bGV0L2Nvbm5l
        Y3QgbWp5eiB3MGJyIHZpMDMKb3V0bGV0L2Nvbm5lY3QgbzM1YiA5bDRiIDBrMjAKb3V0bGV0L2Nvbm5lY3QgMzZ2aCBjMGQ2IG5nbzMKb3V0bGV0L2Nvbm5lY3Qgd3B0NyBiaG9sIHowZTcKb3V0bGV0L2Nvbm5lY3QgYmZpbCBmcHFtIHMwMzIKb3V0bGV0L2Nvbm5l
        Y3QgZnJnaiBpaDE3IGR0dDUKb3V0bGV0L2Nvbm5lY3QgZ2NjbSBsdXBxIHFmMjEKb3V0bGV0L2Nvbm5lY3QgZm1wcCBrN3FtIGhzaXcKb3V0bGV0L2Nvbm5lY3QgMnFyZCB5aGlvIGc5YjIKbm9kZS91cGRhdGUtaW5sZXQgNjBlMCBjMGQ2IGZyZXF1ZW5jeV9pbnB1
        dCAwCm5vZGUvdXBkYXRlLWlubGV0IDYwZTAgaWgxNyB3YXZldGFibGVfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBqNWF4IDlsNGIgYXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBqNWF4IGx1cHEgbWl4X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQg
        ajVheCBrN3FtIGZlZWRiYWNrX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgajVheCB5aGlvIGxlbmd0aF9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGhwa3UgdzBiciBhdWRpb19pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHF6eGIgYmhvbCBmcmVxdWVuY3lf
        aW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBxenhiIGZwcW0gd2F2ZXRhYmxlX2lucHV0IDA=
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
//        ModuleDelay *moduleDelay_1 = new ModuleDelay();
//        ModuleLFO *moduleLFO_1 = new ModuleLFO();


//        moduleDelay_1->audio_input=moduleWavetableOsc_2;

//        moduleWavetableOsc_2->frequency_input=moduleLFO_1;

//        moduleLFO_1->frequency_input= &param[0];
//        moduleLFO_1->wavetable_input= &param[1];

//        moduleWavetableOsc_2->wavetable_input= &param[2];

//        moduleDelay_1->mix_input= &param[3];
//        moduleDelay_1->feedback_input= &param[4];
//        moduleDelay_1->length_input= &param[5];


//        this->last_module = moduleDelay_1;


        // end of espnode86 generated code //


        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA2MGUw
        IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiA2MGUwCm5vZGUvYWRkLWlubGV0IDYwZTAgYzBkNiBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IDYwZTAgaWgxNyBlc3Bu
        b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCA2MGUwIG8zNWIgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGhwa3UgZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJu
        LW9uIGhwa3UKbm9kZS9hZGQtaW5sZXQgaHBrdSB3MGJyIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgMnFtMiBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5vZGUvdHVybi1vbiAycW0yCm5v
        ZGUvYWRkLW91dGxldCAycW0yIHdwdDcgZXNwbm9kZS9zdHJpbmcgUG90MSBQb3QxCm5vZGUvYWRkLW91dGxldCAycW0yIGJmaWwgZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCAycW0yIGZyZ2ogZXNwbm9kZS9zdHJpbmcgUG90MyBQb3Qz
        Cm5vZGUvYWRkLW91dGxldCAycW0yIGdjY20gZXNwbm9kZS9zdHJpbmcgUG90NCBQb3Q0Cm5vZGUvYWRkLW91dGxldCAycW0yIGZtcHAgZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCAycW0yIDJxcmQgZXNwbm9kZS9zdHJpbmcgUG90NiBQ
        b3Q2Cm5vZGUvYWRkLW91dGxldCAycW0yIDB0Z2EgZXNwbm9kZS9zdHJpbmcgUG90NyBQb3Q3Cm5vZGUvYWRkLW91dGxldCAycW0yIGdnaXIgZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4Cm5vZGUvbW92ZSBsZmc0IDIzIDIzCm5vZGUvbW92ZSA2MGUwIDY2OCAyMTIK
        bm9kZS9tb3ZlIGhwa3UgOTg3IDIxNwpub2RlL21vdmUgMnFtMiAzMDIgMTg5Cm91dGxldC9jb25uZWN0IHdwdDcgYzBkNiB6endsCm91dGxldC9jb25uZWN0IGJmaWwgaWgxNyB3aXJvCm91dGxldC9jb25uZWN0IG8zNWIgdzBiciBybjE3
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();


//        moduleWavetableOsc_2->frequency_input= &param[0];
//        moduleWavetableOsc_2->wavetable_input= &param[1];


//        this->last_module = moduleWavetableOsc_2;


        // end of espnode86 generated code //


        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA2MGUw
        IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiA2MGUwCm5vZGUvYWRkLWlubGV0IDYwZTAgYzBkNiBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IDYwZTAgaWgxNyBlc3Bu
        b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCA2MGUwIG8zNWIgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGhwa3UgZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJu
        LW9uIGhwa3UKbm9kZS9hZGQtaW5sZXQgaHBrdSB3MGJyIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgMnFtMiBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5vZGUvdHVybi1vbiAycW0yCm5v
        ZGUvYWRkLW91dGxldCAycW0yIHdwdDcgZXNwbm9kZS9zdHJpbmcgUG90MSBQb3QxCm5vZGUvYWRkLW91dGxldCAycW0yIGJmaWwgZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCAycW0yIGZyZ2ogZXNwbm9kZS9zdHJpbmcgUG90MyBQb3Qz
        Cm5vZGUvYWRkLW91dGxldCAycW0yIGdjY20gZXNwbm9kZS9zdHJpbmcgUG90NCBQb3Q0Cm5vZGUvYWRkLW91dGxldCAycW0yIGZtcHAgZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCAycW0yIDJxcmQgZXNwbm9kZS9zdHJpbmcgUG90NiBQ
        b3Q2Cm5vZGUvYWRkLW91dGxldCAycW0yIDB0Z2EgZXNwbm9kZS9zdHJpbmcgUG90NyBQb3Q3Cm5vZGUvYWRkLW91dGxldCAycW0yIGdnaXIgZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4CnBhdGNoL2FkZC1ub2RlIHNhZDQgZzJjOSBlc3Bub2RlL29zY2lsbGF0b3Ig
        T3NjaWxsYXRvcgpub2RlL3R1cm4tb24gZzJjOQpub2RlL2FkZC1pbmxldCBnMmM5IGlweDkgZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApub2RlL2FkZC1pbmxldCBnMmM5IDdnYXEgZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxl
        X2lucHV0IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgZzJjOSBzNG5iIGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKbm9kZS9tb3ZlIGxmZzQgMjMgMjMKbm9kZS9tb3ZlIDYwZTAgNTc1IDE4Nwpub2RlL21vdmUgaHBrdSAxMTc4IDI5NApub2RlL21vdmUg
        MnFtMiAzMDIgMTg5Cm5vZGUvbW92ZSBnMmM5IDg4NCAzMDAKb3V0bGV0L2Nvbm5lY3Qgd3B0NyBjMGQ2IHp6d2wKb3V0bGV0L2Nvbm5lY3QgYmZpbCBpaDE3IHdpcm8Kb3V0bGV0L2Nvbm5lY3QgbzM1YiBpcHg5IGt2bjUKb3V0bGV0L2Nvbm5lY3QgczRuYiB3MGJy
        IHFwMDkKb3V0bGV0L2Nvbm5lY3QgZnJnaiA3Z2FxIDl1ZTkKbm9kZS91cGRhdGUtaW5sZXQgZzJjOSBpcHg5IGZyZXF1ZW5jeV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGcyYzkgN2dhcSB3YXZldGFibGVfaW5wdXQgMA==
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();


//        moduleWavetableOsc_2->frequency_input= &param[0];
//        moduleWavetableOsc_2->wavetable_input= &param[1];
//        moduleWavetableOsc_3->frequency_input=moduleWavetableOsc_2;
//        moduleWavetableOsc_3->wavetable_input= &param[2];


//        this->last_module = moduleWavetableOsc_3;


        // end of espnode86 generated code //


        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA2MGUw
        IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiA2MGUwCm5vZGUvYWRkLWlubGV0IDYwZTAgYzBkNiBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IDYwZTAgaWgxNyBlc3Bu
        b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCA2MGUwIG8zNWIgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGhwa3UgZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJu
        LW9uIGhwa3UKbm9kZS9hZGQtaW5sZXQgaHBrdSB3MGJyIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgMnFtMiBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5vZGUvdHVybi1vbiAycW0yCm5v
        ZGUvYWRkLW91dGxldCAycW0yIHdwdDcgZXNwbm9kZS9zdHJpbmcgUG90MSBQb3QxCm5vZGUvYWRkLW91dGxldCAycW0yIGJmaWwgZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCAycW0yIGZyZ2ogZXNwbm9kZS9zdHJpbmcgUG90MyBQb3Qz
        Cm5vZGUvYWRkLW91dGxldCAycW0yIGdjY20gZXNwbm9kZS9zdHJpbmcgUG90NCBQb3Q0Cm5vZGUvYWRkLW91dGxldCAycW0yIGZtcHAgZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCAycW0yIDJxcmQgZXNwbm9kZS9zdHJpbmcgUG90NiBQ
        b3Q2Cm5vZGUvYWRkLW91dGxldCAycW0yIDB0Z2EgZXNwbm9kZS9zdHJpbmcgUG90NyBQb3Q3Cm5vZGUvYWRkLW91dGxldCAycW0yIGdnaXIgZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4CnBhdGNoL2FkZC1ub2RlIHNhZDQgZzJjOSBlc3Bub2RlL29zY2lsbGF0b3Ig
        T3NjaWxsYXRvcgpub2RlL3R1cm4tb24gZzJjOQpub2RlL2FkZC1pbmxldCBnMmM5IGlweDkgZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApub2RlL2FkZC1pbmxldCBnMmM5IDdnYXEgZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxl
        X2lucHV0IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgZzJjOSBzNG5iIGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCByMGQ5IGVzcG5vZGUvbG93cGFzcyBMb3clMjBQYXNzJTIwRmlsdGVyCm5vZGUvdHVybi1vbiByMGQ5
        Cm5vZGUvYWRkLWlubGV0IHIwZDkgYWQ5YiBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApub2RlL2FkZC1pbmxldCByMGQ5IGR0dW8gZXNwbm9kZS9zdHJpbmcgY3V0b2ZmX2lucHV0IGN1dG9mZl9pbnB1dApub2RlL2FkZC1pbmxldCByMGQ5
        IG1zeTMgZXNwbm9kZS9zdHJpbmcgcmVzb25hbmNlX2lucHV0IHJlc29uYW5jZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgcjBkOSB5NWl5IGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKbm9kZS9tb3ZlIGxmZzQgMjMgMjMKbm9kZS9tb3ZlIDYwZTAgNDc4IDY0Cm5vZGUv
        bW92ZSBocGt1IDEyNDcgMjg5Cm5vZGUvbW92ZSAycW0yIDMwMiAxODkKbm9kZS9tb3ZlIGcyYzkgNzIxIDE5NApub2RlL21vdmUgcjBkOSA5ODYgMjIyCm91dGxldC9jb25uZWN0IHdwdDcgYzBkNiB6endsCm91dGxldC9jb25uZWN0IGJmaWwgaWgxNyB3aXJvCm91
        dGxldC9jb25uZWN0IG8zNWIgaXB4OSBrdm41Cm91dGxldC9jb25uZWN0IGZyZ2ogN2dhcSA5dWU5Cm91dGxldC9jb25uZWN0IHM0bmIgYWQ5YiA0cTd5Cm91dGxldC9jb25uZWN0IHk1aXkgdzBiciBxbjBoCm91dGxldC9jb25uZWN0IGdjY20gZHR1byB5N3YwCm91
        dGxldC9jb25uZWN0IGZtcHAgbXN5MyBidHpiCm5vZGUvdXBkYXRlLWlubGV0IGcyYzkgaXB4OSBmcmVxdWVuY3lfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBnMmM5IDdnYXEgd2F2ZXRhYmxlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgcjBkOSBhZDliIGF1
        ZGlvX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgcjBkOSBkdHVvIGN1dG9mZl9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHIwZDkgbXN5MyByZXNvbmFuY2VfaW5wdXQgMA==
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();


//        moduleWavetableOsc_2->frequency_input= &param[0];
//        moduleWavetableOsc_2->wavetable_input= &param[1];
//        moduleWavetableOsc_3->frequency_input=moduleWavetableOsc_2;
//        moduleWavetableOsc_3->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_3;
//        moduleLowpassFilter_1->cutoff_input= &param[3];
//        moduleLowpassFilter_1->resonance_input= &param[4];


//        this->last_module = moduleLowpassFilter_1;


//        // end of espnode86 generated code //


        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA2MGUw
        IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiA2MGUwCm5vZGUvYWRkLWlubGV0IDYwZTAgYzBkNiBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IDYwZTAgaWgxNyBlc3Bu
        b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCA2MGUwIG8zNWIgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGhwa3UgZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJu
        LW9uIGhwa3UKbm9kZS9hZGQtaW5sZXQgaHBrdSB3MGJyIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgMnFtMiBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5vZGUvdHVybi1vbiAycW0yCm5v
        ZGUvYWRkLW91dGxldCAycW0yIHdwdDcgZXNwbm9kZS9zdHJpbmcgUG90MSBQb3QxCm5vZGUvYWRkLW91dGxldCAycW0yIGJmaWwgZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCAycW0yIGZyZ2ogZXNwbm9kZS9zdHJpbmcgUG90MyBQb3Qz
        Cm5vZGUvYWRkLW91dGxldCAycW0yIGdjY20gZXNwbm9kZS9zdHJpbmcgUG90NCBQb3Q0Cm5vZGUvYWRkLW91dGxldCAycW0yIGZtcHAgZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCAycW0yIDJxcmQgZXNwbm9kZS9zdHJpbmcgUG90NiBQ
        b3Q2Cm5vZGUvYWRkLW91dGxldCAycW0yIDB0Z2EgZXNwbm9kZS9zdHJpbmcgUG90NyBQb3Q3Cm5vZGUvYWRkLW91dGxldCAycW0yIGdnaXIgZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4CnBhdGNoL2FkZC1ub2RlIHNhZDQgZzJjOSBlc3Bub2RlL29zY2lsbGF0b3Ig
        T3NjaWxsYXRvcgpub2RlL3R1cm4tb24gZzJjOQpub2RlL2FkZC1pbmxldCBnMmM5IGlweDkgZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApub2RlL2FkZC1pbmxldCBnMmM5IDdnYXEgZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxl
        X2lucHV0IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgZzJjOSBzNG5iIGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCByMGQ5IGVzcG5vZGUvbG93cGFzcyBMb3clMjBQYXNzJTIwRmlsdGVyCm5vZGUvdHVybi1vbiByMGQ5
        Cm5vZGUvYWRkLWlubGV0IHIwZDkgYWQ5YiBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApub2RlL2FkZC1pbmxldCByMGQ5IGR0dW8gZXNwbm9kZS9zdHJpbmcgY3V0b2ZmX2lucHV0IGN1dG9mZl9pbnB1dApub2RlL2FkZC1pbmxldCByMGQ5
        IG1zeTMgZXNwbm9kZS9zdHJpbmcgcmVzb25hbmNlX2lucHV0IHJlc29uYW5jZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgcjBkOSB5NWl5IGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKbm9kZS9tb3ZlIGxmZzQgMjMgMjMKbm9kZS9tb3ZlIDYwZTAgNDc4IDY0Cm5vZGUv
        bW92ZSBocGt1IDEyNDcgMjg5Cm5vZGUvbW92ZSAycW0yIDMwMiAxODkKbm9kZS9tb3ZlIGcyYzkgNzIxIDE5NApub2RlL21vdmUgcjBkOSA5ODYgMjIyCm91dGxldC9jb25uZWN0IHdwdDcgYzBkNiB6endsCm91dGxldC9jb25uZWN0IGJmaWwgaWgxNyB3aXJvCm91
        dGxldC9jb25uZWN0IG8zNWIgaXB4OSBrdm41Cm91dGxldC9jb25uZWN0IGZyZ2ogN2dhcSA5dWU5Cm91dGxldC9jb25uZWN0IHM0bmIgYWQ5YiA0cTd5Cm91dGxldC9jb25uZWN0IHk1aXkgdzBiciBxbjBoCm91dGxldC9jb25uZWN0IGdjY20gZHR1byB5N3YwCm91
        dGxldC9jb25uZWN0IGZtcHAgbXN5MyBidHpiCm5vZGUvdXBkYXRlLWlubGV0IGcyYzkgaXB4OSBmcmVxdWVuY3lfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBnMmM5IDdnYXEgd2F2ZXRhYmxlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgcjBkOSBhZDliIGF1
        ZGlvX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgcjBkOSBkdHVvIGN1dG9mZl9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHIwZDkgbXN5MyByZXNvbmFuY2VfaW5wdXQgMA==
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();


//        moduleWavetableOsc_2->frequency_input= &param[0];
//        moduleWavetableOsc_2->wavetable_input= &param[1];
//        moduleWavetableOsc_3->frequency_input=moduleWavetableOsc_2;
//        moduleWavetableOsc_3->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_3;
//        moduleLowpassFilter_1->cutoff_input= &param[3];
//        moduleLowpassFilter_1->resonance_input= &param[4];


//        this->last_module = moduleLowpassFilter_1;


        // end of espnode86 generated code //

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA2MGUw
        IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiA2MGUwCm5vZGUvYWRkLWlubGV0IDYwZTAgYzBkNiBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IDYwZTAgaWgxNyBlc3Bu
        b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCA2MGUwIG8zNWIgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGhwa3UgZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJu
        LW9uIGhwa3UKbm9kZS9hZGQtaW5sZXQgaHBrdSB3MGJyIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgMnFtMiBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5vZGUvdHVybi1vbiAycW0yCm5v
        ZGUvYWRkLW91dGxldCAycW0yIHdwdDcgZXNwbm9kZS9zdHJpbmcgUG90MSBQb3QxCm5vZGUvYWRkLW91dGxldCAycW0yIGJmaWwgZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCAycW0yIGZyZ2ogZXNwbm9kZS9zdHJpbmcgUG90MyBQb3Qz
        Cm5vZGUvYWRkLW91dGxldCAycW0yIGdjY20gZXNwbm9kZS9zdHJpbmcgUG90NCBQb3Q0Cm5vZGUvYWRkLW91dGxldCAycW0yIGZtcHAgZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCAycW0yIDJxcmQgZXNwbm9kZS9zdHJpbmcgUG90NiBQ
        b3Q2Cm5vZGUvYWRkLW91dGxldCAycW0yIDB0Z2EgZXNwbm9kZS9zdHJpbmcgUG90NyBQb3Q3Cm5vZGUvYWRkLW91dGxldCAycW0yIGdnaXIgZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4CnBhdGNoL2FkZC1ub2RlIHNhZDQgZzJjOSBlc3Bub2RlL29zY2lsbGF0b3Ig
        T3NjaWxsYXRvcgpub2RlL3R1cm4tb24gZzJjOQpub2RlL2FkZC1pbmxldCBnMmM5IGlweDkgZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApub2RlL2FkZC1pbmxldCBnMmM5IDdnYXEgZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxl
        X2lucHV0IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgZzJjOSBzNG5iIGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCByMGQ5IGVzcG5vZGUvbG93cGFzcyBMb3clMjBQYXNzJTIwRmlsdGVyCm5vZGUvdHVybi1vbiByMGQ5
        Cm5vZGUvYWRkLWlubGV0IHIwZDkgYWQ5YiBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApub2RlL2FkZC1pbmxldCByMGQ5IGR0dW8gZXNwbm9kZS9zdHJpbmcgY3V0b2ZmX2lucHV0IGN1dG9mZl9pbnB1dApub2RlL2FkZC1pbmxldCByMGQ5
        IG1zeTMgZXNwbm9kZS9zdHJpbmcgcmVzb25hbmNlX2lucHV0IHJlc29uYW5jZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgcjBkOSB5NWl5IGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBxemN0IGVzcG5vZGUvbGZvIExGJTIwT3NjaWxs
        YXRvcgpub2RlL3R1cm4tb24gcXpjdApub2RlL2FkZC1pbmxldCBxemN0IGwzYXYgZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApub2RlL2FkZC1pbmxldCBxemN0IDFqc2IgZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxlX2lucHV0
        IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgcXpjdCB6bTZ3IGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKbm9kZS9tb3ZlIGxmZzQgMjMgMjMKbm9kZS9tb3ZlIDYwZTAgNDc4IDY0Cm5vZGUvbW92ZSBocGt1IDEyMTYgMTU2Cm5vZGUvbW92ZSAycW0yIDI4
        NyA5OApub2RlL21vdmUgZzJjOSA3MzkgMTE1Cm5vZGUvbW92ZSByMGQ5IDk4MSAxNDMKbm9kZS9tb3ZlIHF6Y3QgNjE3IDI2NgpvdXRsZXQvY29ubmVjdCB3cHQ3IGMwZDYgenp3bApvdXRsZXQvY29ubmVjdCBiZmlsIGloMTcgd2lybwpvdXRsZXQvY29ubmVjdCBv
        MzViIGlweDkga3ZuNQpvdXRsZXQvY29ubmVjdCBmcmdqIDdnYXEgOXVlOQpvdXRsZXQvY29ubmVjdCBzNG5iIGFkOWIgNHE3eQpvdXRsZXQvY29ubmVjdCB5NWl5IHcwYnIgcW4waApvdXRsZXQvY29ubmVjdCBmbXBwIG1zeTMgYnR6YgpvdXRsZXQvY29ubmVjdCBn
        Y2NtIGR0dW8gdjEzcApub2RlL3VwZGF0ZS1pbmxldCBnMmM5IGlweDkgZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgZzJjOSA3Z2FxIHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHIwZDkgYWQ5YiBhdWRpb19pbnB1dCAwCm5v
        ZGUvdXBkYXRlLWlubGV0IHIwZDkgbXN5MyByZXNvbmFuY2VfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBxemN0IDFqc2Igd2F2ZXRhYmxlX2lucHV0IDA=
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleLFO *moduleLFO_3 = new ModuleLFO();


//        moduleWavetableOsc_2->frequency_input= &param[0];
//        moduleWavetableOsc_2->wavetable_input= &param[1];
//        moduleWavetableOsc_3->frequency_input=moduleWavetableOsc_2;
//        moduleWavetableOsc_3->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_3;
//        moduleLowpassFilter_1->resonance_input= &param[4];
//        moduleLowpassFilter_1->cutoff_input= &param[3];


//        this->last_module = moduleLowpassFilter_1;


        // end of espnode86 generated code //

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBocGt1
        IGVzcG5vZGUvZGFjIEF1ZGlvJTIwREFDCm5vZGUvdHVybi1vbiBocGt1Cm5vZGUvYWRkLWlubGV0IGhwa3UgdzBiciBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDJxbTIgZXNwbm9kZS9tdWx0aXBsZXhl
        ciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gMnFtMgpub2RlL2FkZC1vdXRsZXQgMnFtMiB3cHQ3IGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgMnFtMiBiZmlsIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQg
        MnFtMiBmcmdqIGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnY2NtIGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgMnFtMiBmbXBwIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRs
        ZXQgMnFtMiAycXJkIGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgMnFtMiAwdGdhIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnZ2lyIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQt
        bm9kZSBzYWQ0IGcyYzkgZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIGcyYzkKbm9kZS9hZGQtaW5sZXQgZzJjOSBpcHg5IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQg
        ZzJjOSA3Z2FxIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGcyYzkgczRuYiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgcjBkOSBlc3Bub2RlL2xvd3Bhc3MgTG93
        JTIwUGFzcyUyMEZpbHRlcgpub2RlL3R1cm4tb24gcjBkOQpub2RlL2FkZC1pbmxldCByMGQ5IGFkOWIgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBkdHVvIGVzcG5vZGUvc3RyaW5nIGN1dG9mZl9pbnB1
        dCBjdXRvZmZfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBtc3kzIGVzcG5vZGUvc3RyaW5nIHJlc29uYW5jZV9pbnB1dCByZXNvbmFuY2VfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHIwZDkgeTVpeSBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2Rl
        IHNhZDQgcXpjdCBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIHF6Y3QKbm9kZS9hZGQtaW5sZXQgcXpjdCBsM2F2IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcXpjdCAx
        anNiIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHF6Y3Qgem02dyBlc3Bub2RlL3N0cmluZyBPdXQgT3V0Cm5vZGUvbW92ZSBsZmc0IDIzIDIzCm5vZGUvbW92ZSBocGt1IDEyMTYgMTU2Cm5vZGUv
        bW92ZSAycW0yIDI4NyA5OApub2RlL21vdmUgZzJjOSA1MjYgMTAxCm5vZGUvbW92ZSByMGQ5IDk4MSAxNDMKbm9kZS9tb3ZlIHF6Y3QgNjE3IDI2NgpvdXRsZXQvY29ubmVjdCBmcmdqIDdnYXEgOXVlOQpvdXRsZXQvY29ubmVjdCBzNG5iIGFkOWIgNHE3eQpvdXRs
        ZXQvY29ubmVjdCB5NWl5IHcwYnIgcW4waApvdXRsZXQvY29ubmVjdCBmbXBwIG1zeTMgYnR6YgpvdXRsZXQvY29ubmVjdCBnY2NtIGR0dW8gdjEzcApvdXRsZXQvY29ubmVjdCB3cHQ3IGlweDkgNGs3aApub2RlL3VwZGF0ZS1pbmxldCBnMmM5IDdnYXEgd2F2ZXRh
        YmxlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgcjBkOSBhZDliIGF1ZGlvX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgcjBkOSBtc3kzIHJlc29uYW5jZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHF6Y3QgMWpzYiB3YXZldGFibGVfaW5wdXQgMA==
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleLFO *moduleLFO_3 = new ModuleLFO();


//        moduleWavetableOsc_3->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_3;
//        moduleLowpassFilter_1->resonance_input= &param[4];
//        moduleLowpassFilter_1->cutoff_input= &param[3];
//        moduleWavetableOsc_3->frequency_input= &param[0];


//        this->last_module = moduleLowpassFilter_1;


        // end of espnode86 generated code //


        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBocGt1
        IGVzcG5vZGUvZGFjIEF1ZGlvJTIwREFDCm5vZGUvdHVybi1vbiBocGt1Cm5vZGUvYWRkLWlubGV0IGhwa3UgdzBiciBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDJxbTIgZXNwbm9kZS9tdWx0aXBsZXhl
        ciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gMnFtMgpub2RlL2FkZC1vdXRsZXQgMnFtMiB3cHQ3IGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgMnFtMiBiZmlsIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQg
        MnFtMiBmcmdqIGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnY2NtIGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgMnFtMiBmbXBwIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRs
        ZXQgMnFtMiAycXJkIGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgMnFtMiAwdGdhIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnZ2lyIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQt
        bm9kZSBzYWQ0IGcyYzkgZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIGcyYzkKbm9kZS9hZGQtaW5sZXQgZzJjOSBpcHg5IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQg
        ZzJjOSA3Z2FxIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGcyYzkgczRuYiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgcjBkOSBlc3Bub2RlL2xvd3Bhc3MgTG93
        JTIwUGFzcyUyMEZpbHRlcgpub2RlL3R1cm4tb24gcjBkOQpub2RlL2FkZC1pbmxldCByMGQ5IGFkOWIgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBkdHVvIGVzcG5vZGUvc3RyaW5nIGN1dG9mZl9pbnB1
        dCBjdXRvZmZfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBtc3kzIGVzcG5vZGUvc3RyaW5nIHJlc29uYW5jZV9pbnB1dCByZXNvbmFuY2VfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHIwZDkgeTVpeSBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2Rl
        IHNhZDQgcXpjdCBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIHF6Y3QKbm9kZS9hZGQtaW5sZXQgcXpjdCBsM2F2IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcXpjdCAx
        anNiIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHF6Y3Qgem02dyBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgZWd3NiBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0
        b3IKbm9kZS90dXJuLW9uIGVndzYKbm9kZS9hZGQtaW5sZXQgZWd3NiAyaHhtIGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgZWd3NiB3Zm45IGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3
        YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGVndzYgNDJneiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0Cm5vZGUvbW92ZSBsZmc0IDIzIDIzCm5vZGUvbW92ZSBocGt1IDEyMTYgMTU2Cm5vZGUvbW92ZSAycW0yIDI4NyA5OApub2RlL21vdmUgZzJjOSA1MTEg
        NzUKbm9kZS9tb3ZlIHIwZDkgOTgxIDE0Mwpub2RlL21vdmUgcXpjdCA1OTIgMzU0Cm5vZGUvbW92ZSBlZ3c2IDU5OCAyNTMKb3V0bGV0L2Nvbm5lY3QgZnJnaiA3Z2FxIDl1ZTkKb3V0bGV0L2Nvbm5lY3QgczRuYiBhZDliIDRxN3kKb3V0bGV0L2Nvbm5lY3QgeTVp
        eSB3MGJyIHFuMGgKb3V0bGV0L2Nvbm5lY3Qgd3B0NyBpcHg5IDRrN2gKb3V0bGV0L2Nvbm5lY3QgZm1wcCBsM2F2IGFpZ2gKb3V0bGV0L2Nvbm5lY3Qgem02dyBtc3kzIGRhdjgKb3V0bGV0L2Nvbm5lY3QgZ2NjbSAyaHhtIGFjam0Kb3V0bGV0L2Nvbm5lY3QgNDJn
        eiBkdHVvIG05dTYKbm9kZS91cGRhdGUtaW5sZXQgZzJjOSA3Z2FxIHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHIwZDkgYWQ5YiBhdWRpb19pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHF6Y3QgMWpzYiB3YXZldGFibGVfaW5wdXQgMApub2Rl
        L3VwZGF0ZS1pbmxldCBlZ3c2IDJoeG0gZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgZWd3NiB3Zm45IHdhdmV0YWJsZV9pbnB1dCAw
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleLFO *moduleLFO_3 = new ModuleLFO();
//        ModuleLFO *moduleLFO_4 = new ModuleLFO();


//        moduleWavetableOsc_3->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_3;
//        moduleWavetableOsc_3->frequency_input= &param[0];
//        moduleLFO_3->frequency_input= &param[4];
//        moduleLowpassFilter_1->resonance_input=moduleLFO_3;
//        moduleLFO_4->frequency_input= &param[3];
//        moduleLowpassFilter_1->cutoff_input=moduleLFO_4;


//        this->last_module = moduleLowpassFilter_1;


        // end of espnode86 generated code //

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBocGt1
        IGVzcG5vZGUvZGFjIEF1ZGlvJTIwREFDCm5vZGUvdHVybi1vbiBocGt1Cm5vZGUvYWRkLWlubGV0IGhwa3UgdzBiciBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDJxbTIgZXNwbm9kZS9tdWx0aXBsZXhl
        ciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gMnFtMgpub2RlL2FkZC1vdXRsZXQgMnFtMiB3cHQ3IGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgMnFtMiBiZmlsIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQg
        MnFtMiBmcmdqIGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnY2NtIGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgMnFtMiBmbXBwIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRs
        ZXQgMnFtMiAycXJkIGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgMnFtMiAwdGdhIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnZ2lyIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQt
        bm9kZSBzYWQ0IGcyYzkgZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIGcyYzkKbm9kZS9hZGQtaW5sZXQgZzJjOSBpcHg5IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQg
        ZzJjOSA3Z2FxIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGcyYzkgczRuYiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgcjBkOSBlc3Bub2RlL2xvd3Bhc3MgTG93
        JTIwUGFzcyUyMEZpbHRlcgpub2RlL3R1cm4tb24gcjBkOQpub2RlL2FkZC1pbmxldCByMGQ5IGFkOWIgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBkdHVvIGVzcG5vZGUvc3RyaW5nIGN1dG9mZl9pbnB1
        dCBjdXRvZmZfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBtc3kzIGVzcG5vZGUvc3RyaW5nIHJlc29uYW5jZV9pbnB1dCByZXNvbmFuY2VfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHIwZDkgeTVpeSBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2Rl
        IHNhZDQgcXpjdCBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIHF6Y3QKbm9kZS9hZGQtaW5sZXQgcXpjdCBsM2F2IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcXpjdCAx
        anNiIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHF6Y3Qgem02dyBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgZWd3NiBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0
        b3IKbm9kZS90dXJuLW9uIGVndzYKbm9kZS9hZGQtaW5sZXQgZWd3NiAyaHhtIGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgZWd3NiB3Zm45IGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3
        YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGVndzYgNDJneiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgbHMzMCBlc3Bub2RlL2RlbGF5IEF1ZGlvJTIwRGVsYXkKbm9kZS90dXJuLW9uIGxzMzAKbm9kZS9hZGQtaW5sZXQg
        bHMzMCA1NHQwIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0Cm5vZGUvYWRkLWlubGV0IGxzMzAgZjY5NSBlc3Bub2RlL3N0cmluZyBtaXhfaW5wdXQgbWl4X2lucHV0Cm5vZGUvYWRkLWlubGV0IGxzMzAgdnY1YyBlc3Bub2RlL3N0cmluZyBm
        ZWVkYmFja19pbnB1dCBmZWVkYmFja19pbnB1dApub2RlL2FkZC1pbmxldCBsczMwIGR1NjMgZXNwbm9kZS9zdHJpbmcgbGVuZ3RoX2lucHV0IGxlbmd0aF9pbnB1dApub2RlL2FkZC1vdXRsZXQgbHMzMCBqZ2d1IGVzcG5vZGUvc3RyaW5nIG91dCBvdXQKcGF0Y2gv
        YWRkLW5vZGUgc2FkNCBid3VkIGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIGJ3dWQKbm9kZS9hZGQtaW5sZXQgYnd1ZCAwZjIzIGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUgdXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgYnd1ZCBoemI5
        IGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKcGF0Y2gvYWRkLW5vZGUgc2FkNCAyaWhxIGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIDJpaHEKbm9kZS9hZGQtaW5sZXQgMmlocSBsdXUyIGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUg
        dXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgMmlocSBuM2ttIGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKcGF0Y2gvYWRkLW5vZGUgc2FkNCBkemVrIGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIGR6ZWsKbm9kZS9hZGQtaW5sZXQg
        ZHplayBpenM0IGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUgdXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgZHplayBxZnU5IGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKbm9kZS9tb3ZlIGxmZzQgMjMgMjMKbm9kZS9tb3ZlIGhwa3UgMTI3MiAxNTQKbm9k
        ZS9tb3ZlIDJxbTIgMjg3IDk4Cm5vZGUvbW92ZSBnMmM5IDUxMSA3NQpub2RlL21vdmUgcjBkOSA5ODEgMTQzCm5vZGUvbW92ZSBxemN0IDUxNSAyODAKbm9kZS9tb3ZlIGVndzYgNTIwIDE3Nwpub2RlL21vdmUgbHMzMCA5ODAgMjY5Cm5vZGUvbW92ZSBid3VkIDYw
        MyAzNzgKbm9kZS9tb3ZlIDJpaHEgNTkzIDQ3NApub2RlL21vdmUgZHplayA5MDUgNTc3Cm91dGxldC9jb25uZWN0IGZyZ2ogN2dhcSA5dWU5Cm91dGxldC9jb25uZWN0IHM0bmIgYWQ5YiA0cTd5Cm91dGxldC9jb25uZWN0IHdwdDcgaXB4OSA0azdoCm91dGxldC9j
        b25uZWN0IGZtcHAgbDNhdiBhaWdoCm91dGxldC9jb25uZWN0IHptNncgbXN5MyBkYXY4Cm91dGxldC9jb25uZWN0IGdjY20gMmh4bSBhY2ptCm91dGxldC9jb25uZWN0IDQyZ3ogZHR1byBtOXU2Cm91dGxldC9jb25uZWN0IHk1aXkgNTR0MCB6ZnNpCm91dGxldC9j
        b25uZWN0IGpnZ3UgdzBiciBmbWR3Cm91dGxldC9jb25uZWN0IGh6YjkgZjY5NSB1bTI1Cm91dGxldC9jb25uZWN0IG4za20gdnY1YyBqYjEzCm91dGxldC9jb25uZWN0IHFmdTkgZHU2MyA0NGd5Cm5vZGUvdXBkYXRlLWlubGV0IGcyYzkgN2dhcSB3YXZldGFibGVf
        aW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCByMGQ5IGFkOWIgYXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBxemN0IDFqc2Igd2F2ZXRhYmxlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgZWd3NiAyaHhtIGZyZXF1ZW5jeV9pbnB1dCAwCm5vZGUvdXBk
        YXRlLWlubGV0IGVndzYgd2ZuOSB3YXZldGFibGVfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBsczMwIDU0dDAgYXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBsczMwIGY2OTUgbWl4X2lucHV0IDIwMDAKbm9kZS91cGRhdGUtaW5sZXQgbHMzMCB2djVj
        IGZlZWRiYWNrX2lucHV0IDIwMDAKbm9kZS91cGRhdGUtaW5sZXQgbHMzMCBkdTYzIGxlbmd0aF9pbnB1dCA1MDAwCm5vZGUvdXBkYXRlLW91dGxldCBid3VkIGh6YjkgbnVtYmVyIDIwMDAKbm9kZS91cGRhdGUtaW5sZXQgYnd1ZCAwZjIzIHVzZXItdmFsdWUgMjAw
        MApub2RlL3VwZGF0ZS1vdXRsZXQgMmlocSBuM2ttIG51bWJlciAyMDAwCm5vZGUvdXBkYXRlLWlubGV0IDJpaHEgbHV1MiB1c2VyLXZhbHVlIDIwMDAKbm9kZS91cGRhdGUtb3V0bGV0IGR6ZWsgcWZ1OSBudW1iZXIgNTAwMApub2RlL3VwZGF0ZS1pbmxldCBkemVr
        IGl6czQgdXNlci12YWx1ZSA1MDAw
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleLFO *moduleLFO_3 = new ModuleLFO();
//        ModuleLFO *moduleLFO_4 = new ModuleLFO();
//        ModuleDelay *moduleDelay_2 = new ModuleDelay();


//        moduleDelay_2->mix_input = new ModuleConstant(2000);
//        moduleDelay_2->feedback_input = new ModuleConstant(2000);
//        moduleDelay_2->length_input = new ModuleConstant(5000);
//        moduleWavetableOsc_3->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_3;
//        moduleWavetableOsc_3->frequency_input= &param[0];
//        moduleLFO_3->frequency_input= &param[4];
//        moduleLowpassFilter_1->resonance_input=moduleLFO_3;
//        moduleLFO_4->frequency_input= &param[3];
//        moduleLowpassFilter_1->cutoff_input=moduleLFO_4;
//        moduleDelay_2->audio_input=moduleLowpassFilter_1;


//        this->last_module = moduleDelay_2;
        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBocGt1
        IGVzcG5vZGUvZGFjIEF1ZGlvJTIwREFDCm5vZGUvdHVybi1vbiBocGt1Cm5vZGUvYWRkLWlubGV0IGhwa3UgdzBiciBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDJxbTIgZXNwbm9kZS9tdWx0aXBsZXhl
        ciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gMnFtMgpub2RlL2FkZC1vdXRsZXQgMnFtMiB3cHQ3IGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgMnFtMiBiZmlsIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQg
        MnFtMiBmcmdqIGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnY2NtIGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgMnFtMiBmbXBwIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRs
        ZXQgMnFtMiAycXJkIGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgMnFtMiAwdGdhIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnZ2lyIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQt
        bm9kZSBzYWQ0IGcyYzkgZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIGcyYzkKbm9kZS9hZGQtaW5sZXQgZzJjOSBpcHg5IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQg
        ZzJjOSA3Z2FxIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGcyYzkgczRuYiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgcjBkOSBlc3Bub2RlL2xvd3Bhc3MgTG93
        JTIwUGFzcyUyMEZpbHRlcgpub2RlL3R1cm4tb24gcjBkOQpub2RlL2FkZC1pbmxldCByMGQ5IGFkOWIgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBkdHVvIGVzcG5vZGUvc3RyaW5nIGN1dG9mZl9pbnB1
        dCBjdXRvZmZfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBtc3kzIGVzcG5vZGUvc3RyaW5nIHJlc29uYW5jZV9pbnB1dCByZXNvbmFuY2VfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHIwZDkgeTVpeSBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2Rl
        IHNhZDQgcXpjdCBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIHF6Y3QKbm9kZS9hZGQtaW5sZXQgcXpjdCBsM2F2IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcXpjdCAx
        anNiIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHF6Y3Qgem02dyBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgZWd3NiBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0
        b3IKbm9kZS90dXJuLW9uIGVndzYKbm9kZS9hZGQtaW5sZXQgZWd3NiAyaHhtIGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgZWd3NiB3Zm45IGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3
        YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGVndzYgNDJneiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgbHMzMCBlc3Bub2RlL2RlbGF5IEF1ZGlvJTIwRGVsYXkKbm9kZS90dXJuLW9uIGxzMzAKbm9kZS9hZGQtaW5sZXQg
        bHMzMCA1NHQwIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0Cm5vZGUvYWRkLWlubGV0IGxzMzAgZjY5NSBlc3Bub2RlL3N0cmluZyBtaXhfaW5wdXQgbWl4X2lucHV0Cm5vZGUvYWRkLWlubGV0IGxzMzAgdnY1YyBlc3Bub2RlL3N0cmluZyBm
        ZWVkYmFja19pbnB1dCBmZWVkYmFja19pbnB1dApub2RlL2FkZC1pbmxldCBsczMwIGR1NjMgZXNwbm9kZS9zdHJpbmcgbGVuZ3RoX2lucHV0IGxlbmd0aF9pbnB1dApub2RlL2FkZC1vdXRsZXQgbHMzMCBqZ2d1IGVzcG5vZGUvc3RyaW5nIG91dCBvdXQKcGF0Y2gv
        YWRkLW5vZGUgc2FkNCBid3VkIGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIGJ3dWQKbm9kZS9hZGQtaW5sZXQgYnd1ZCAwZjIzIGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUgdXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgYnd1ZCBoemI5
        IGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKcGF0Y2gvYWRkLW5vZGUgc2FkNCAyaWhxIGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIDJpaHEKbm9kZS9hZGQtaW5sZXQgMmlocSBsdXUyIGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUg
        dXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgMmlocSBuM2ttIGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKcGF0Y2gvYWRkLW5vZGUgc2FkNCBkemVrIGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIGR6ZWsKbm9kZS9hZGQtaW5sZXQg
        ZHplayBpenM0IGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUgdXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgZHplayBxZnU5IGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKbm9kZS9tb3ZlIGxmZzQgMjMgMjMKbm9kZS9tb3ZlIGhwa3UgMTI3MiAxNTQKbm9k
        ZS9tb3ZlIDJxbTIgMjg3IDk4Cm5vZGUvbW92ZSBnMmM5IDUxMSA3NQpub2RlL21vdmUgcjBkOSA5ODEgMTQzCm5vZGUvbW92ZSBxemN0IDUxNSAyODAKbm9kZS9tb3ZlIGVndzYgNTIwIDE3Nwpub2RlL21vdmUgbHMzMCA5ODAgMjY5Cm5vZGUvbW92ZSBid3VkIDYw
        MyAzNzgKbm9kZS9tb3ZlIDJpaHEgNTkzIDQ3NApub2RlL21vdmUgZHplayA5MDUgNTc3Cm91dGxldC9jb25uZWN0IGZyZ2ogN2dhcSA5dWU5Cm91dGxldC9jb25uZWN0IHM0bmIgYWQ5YiA0cTd5Cm91dGxldC9jb25uZWN0IHdwdDcgaXB4OSA0azdoCm91dGxldC9j
        b25uZWN0IGZtcHAgbDNhdiBhaWdoCm91dGxldC9jb25uZWN0IHptNncgbXN5MyBkYXY4Cm91dGxldC9jb25uZWN0IGdjY20gMmh4bSBhY2ptCm91dGxldC9jb25uZWN0IDQyZ3ogZHR1byBtOXU2Cm91dGxldC9jb25uZWN0IHk1aXkgNTR0MCB6ZnNpCm91dGxldC9j
        b25uZWN0IGpnZ3UgdzBiciBmbWR3Cm91dGxldC9jb25uZWN0IGh6YjkgZjY5NSB1bTI1Cm91dGxldC9jb25uZWN0IG4za20gdnY1YyBqYjEzCm91dGxldC9jb25uZWN0IHFmdTkgZHU2MyA0NGd5Cm5vZGUvdXBkYXRlLWlubGV0IGcyYzkgN2dhcSB3YXZldGFibGVf
        aW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCByMGQ5IGFkOWIgYXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBxemN0IDFqc2Igd2F2ZXRhYmxlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgZWd3NiAyaHhtIGZyZXF1ZW5jeV9pbnB1dCAwCm5vZGUvdXBk
        YXRlLWlubGV0IGVndzYgd2ZuOSB3YXZldGFibGVfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBsczMwIDU0dDAgYXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBsczMwIGY2OTUgbWl4X2lucHV0IDEwMApub2RlL3VwZGF0ZS1pbmxldCBsczMwIHZ2NWMg
        ZmVlZGJhY2tfaW5wdXQgMTAwCm5vZGUvdXBkYXRlLWlubGV0IGxzMzAgZHU2MyBsZW5ndGhfaW5wdXQgMTAwCm5vZGUvdXBkYXRlLW91dGxldCBid3VkIGh6YjkgbnVtYmVyIDEwMApub2RlL3VwZGF0ZS1pbmxldCBid3VkIDBmMjMgdXNlci12YWx1ZSAxMDAKbm9k
        ZS91cGRhdGUtb3V0bGV0IDJpaHEgbjNrbSBudW1iZXIgMTAwCm5vZGUvdXBkYXRlLWlubGV0IDJpaHEgbHV1MiB1c2VyLXZhbHVlIDEwMApub2RlL3VwZGF0ZS1vdXRsZXQgZHplayBxZnU5IG51bWJlciAxMDAKbm9kZS91cGRhdGUtaW5sZXQgZHplayBpenM0IHVz
        ZXItdmFsdWUgMTAw
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleLFO *moduleLFO_3 = new ModuleLFO();
//        ModuleLFO *moduleLFO_4 = new ModuleLFO();
//        ModuleDelay *moduleDelay_2 = new ModuleDelay();


//        moduleDelay_2->mix_input = new ModuleConstant(700);
//        moduleDelay_2->feedback_input = new ModuleConstant(400);
//        moduleDelay_2->length_input = new ModuleConstant(1023);
//        moduleWavetableOsc_3->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_3;
//        moduleWavetableOsc_3->frequency_input= &param[0];
//        moduleLFO_3->frequency_input= &param[4];
//        moduleLowpassFilter_1->resonance_input=moduleLFO_3;
//        moduleLFO_4->frequency_input= &param[3];
//        moduleLowpassFilter_1->cutoff_input=moduleLFO_4;
//        moduleDelay_2->audio_input=moduleLowpassFilter_1;


//        this->last_module = moduleDelay_2;


        // end of espnode86 generated code //

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBocGt1
        IGVzcG5vZGUvZGFjIEF1ZGlvJTIwREFDCm5vZGUvdHVybi1vbiBocGt1Cm5vZGUvYWRkLWlubGV0IGhwa3UgdzBiciBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDJxbTIgZXNwbm9kZS9tdWx0aXBsZXhl
        ciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gMnFtMgpub2RlL2FkZC1vdXRsZXQgMnFtMiB3cHQ3IGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgMnFtMiBiZmlsIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQg
        MnFtMiBmcmdqIGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnY2NtIGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgMnFtMiBmbXBwIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRs
        ZXQgMnFtMiAycXJkIGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgMnFtMiAwdGdhIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnZ2lyIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQt
        bm9kZSBzYWQ0IGcyYzkgZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIGcyYzkKbm9kZS9hZGQtaW5sZXQgZzJjOSBpcHg5IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQg
        ZzJjOSA3Z2FxIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGcyYzkgczRuYiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgcjBkOSBlc3Bub2RlL2xvd3Bhc3MgTG93
        JTIwUGFzcyUyMEZpbHRlcgpub2RlL3R1cm4tb24gcjBkOQpub2RlL2FkZC1pbmxldCByMGQ5IGFkOWIgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBkdHVvIGVzcG5vZGUvc3RyaW5nIGN1dG9mZl9pbnB1
        dCBjdXRvZmZfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBtc3kzIGVzcG5vZGUvc3RyaW5nIHJlc29uYW5jZV9pbnB1dCByZXNvbmFuY2VfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHIwZDkgeTVpeSBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2Rl
        IHNhZDQgcXpjdCBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIHF6Y3QKbm9kZS9hZGQtaW5sZXQgcXpjdCBsM2F2IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcXpjdCAx
        anNiIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHF6Y3Qgem02dyBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgZWd3NiBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0
        b3IKbm9kZS90dXJuLW9uIGVndzYKbm9kZS9hZGQtaW5sZXQgZWd3NiAyaHhtIGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgZWd3NiB3Zm45IGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3
        YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGVndzYgNDJneiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgbHMzMCBlc3Bub2RlL2RlbGF5IEF1ZGlvJTIwRGVsYXkKbm9kZS90dXJuLW9uIGxzMzAKbm9kZS9hZGQtaW5sZXQg
        bHMzMCA1NHQwIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0Cm5vZGUvYWRkLWlubGV0IGxzMzAgZjY5NSBlc3Bub2RlL3N0cmluZyBtaXhfaW5wdXQgbWl4X2lucHV0Cm5vZGUvYWRkLWlubGV0IGxzMzAgdnY1YyBlc3Bub2RlL3N0cmluZyBm
        ZWVkYmFja19pbnB1dCBmZWVkYmFja19pbnB1dApub2RlL2FkZC1pbmxldCBsczMwIGR1NjMgZXNwbm9kZS9zdHJpbmcgbGVuZ3RoX2lucHV0IGxlbmd0aF9pbnB1dApub2RlL2FkZC1vdXRsZXQgbHMzMCBqZ2d1IGVzcG5vZGUvc3RyaW5nIG91dCBvdXQKcGF0Y2gv
        YWRkLW5vZGUgc2FkNCBkemVrIGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIGR6ZWsKbm9kZS9hZGQtaW5sZXQgZHplayBpenM0IGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUgdXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgZHplayBxZnU5
        IGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKcGF0Y2gvYWRkLW5vZGUgc2FkNCBpMW52IGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIGkxbnYKbm9kZS9hZGQtaW5sZXQgaTFudiBweDgxIGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUg
        dXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgaTFudiBiNGJhIGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKcGF0Y2gvYWRkLW5vZGUgc2FkNCB2d2xxIGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIHZ3bHEKbm9kZS9hZGQtaW5sZXQg
        dndscSB5OGJhIGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUgdXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgdndscSBodm9yIGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKbm9kZS9tb3ZlIGxmZzQgMjMgMjMKbm9kZS9tb3ZlIGhwa3UgOTkxIDQyNApub2Rl
        L21vdmUgMnFtMiAyODcgOTgKbm9kZS9tb3ZlIGcyYzkgNTY2IDQ5Cm5vZGUvbW92ZSByMGQ5IDk4MSAxNDMKbm9kZS9tb3ZlIHF6Y3QgNTE1IDI4MApub2RlL21vdmUgZWd3NiA2MDAgMTY1Cm5vZGUvbW92ZSBsczMwIDk4MCAyNjkKbm9kZS9tb3ZlIGR6ZWsgNjg0
        IDUyNgpub2RlL21vdmUgaTFudiA2NzggNDMxCm5vZGUvbW92ZSB2d2xxIDcwOSAzMzQKb3V0bGV0L2Nvbm5lY3QgZnJnaiA3Z2FxIDl1ZTkKb3V0bGV0L2Nvbm5lY3QgczRuYiBhZDliIDRxN3kKb3V0bGV0L2Nvbm5lY3Qgd3B0NyBpcHg5IDRrN2gKb3V0bGV0L2Nv
        bm5lY3QgZm1wcCBsM2F2IGFpZ2gKb3V0bGV0L2Nvbm5lY3Qgem02dyBtc3kzIGRhdjgKb3V0bGV0L2Nvbm5lY3QgZ2NjbSAyaHhtIGFjam0Kb3V0bGV0L2Nvbm5lY3QgNDJneiBkdHVvIG05dTYKb3V0bGV0L2Nvbm5lY3QgeTVpeSA1NHQwIHpmc2kKb3V0bGV0L2Nv
        bm5lY3QgamdndSB3MGJyIGZtZHcKb3V0bGV0L2Nvbm5lY3QgcWZ1OSBkdTYzIDQ0Z3kKb3V0bGV0L2Nvbm5lY3QgMnFyZCBmNjk1IDhiMG4Kb3V0bGV0L2Nvbm5lY3QgMHRnYSB2djVjIHpoZGoKbm9kZS91cGRhdGUtaW5sZXQgZzJjOSA3Z2FxIHdhdmV0YWJsZV9p
        bnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHIwZDkgYWQ5YiBhdWRpb19pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHF6Y3QgMWpzYiB3YXZldGFibGVfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBlZ3c2IDJoeG0gZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRh
        dGUtaW5sZXQgZWd3NiB3Zm45IHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGxzMzAgNTR0MCBhdWRpb19pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGxzMzAgZHU2MyBsZW5ndGhfaW5wdXQgMTAwCm5vZGUvdXBkYXRlLW91dGxldCBkemVrIHFm
        dTkgbnVtYmVyIDEwMjMKbm9kZS91cGRhdGUtaW5sZXQgZHplayBpenM0IHVzZXItdmFsdWUgMTAyMwpub2RlL3VwZGF0ZS1vdXRsZXQgaTFudiBiNGJhIG51bWJlciA0MDAKbm9kZS91cGRhdGUtaW5sZXQgaTFudiBweDgxIHVzZXItdmFsdWUgNDAwCm5vZGUvdXBk
        YXRlLW91dGxldCB2d2xxIGh2b3IgbnVtYmVyIDcwMApub2RlL3VwZGF0ZS1pbmxldCB2d2xxIHk4YmEgdXNlci12YWx1ZSA3MDA=
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleLFO *moduleLFO_3 = new ModuleLFO();
//        ModuleLFO *moduleLFO_4 = new ModuleLFO();
//        ModuleDelay *moduleDelay_2 = new ModuleDelay();


//        moduleDelay_2->length_input = new ModuleConstant(100);
//        moduleWavetableOsc_3->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_3;
//        moduleWavetableOsc_3->frequency_input= &param[0];
//        moduleLFO_3->frequency_input= &param[4];
//        moduleLowpassFilter_1->resonance_input=moduleLFO_3;
//        moduleLFO_4->frequency_input= &param[3];
//        moduleLowpassFilter_1->cutoff_input=moduleLFO_4;
//        moduleDelay_2->audio_input=moduleLowpassFilter_1;
//        moduleDelay_2->mix_input= &param[5];
//        moduleDelay_2->feedback_input= &param[6];


//        this->last_module = moduleDelay_2;


        // end of espnode86 generated code //



        // end of espnode86 generated code //

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBsZmc0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGxmZzQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBocGt1
        IGVzcG5vZGUvZGFjIEF1ZGlvJTIwREFDCm5vZGUvdHVybi1vbiBocGt1Cm5vZGUvYWRkLWlubGV0IGhwa3UgdzBiciBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDJxbTIgZXNwbm9kZS9tdWx0aXBsZXhl
        ciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gMnFtMgpub2RlL2FkZC1vdXRsZXQgMnFtMiB3cHQ3IGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgMnFtMiBiZmlsIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQg
        MnFtMiBmcmdqIGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnY2NtIGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgMnFtMiBmbXBwIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRs
        ZXQgMnFtMiAycXJkIGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgMnFtMiAwdGdhIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgMnFtMiBnZ2lyIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQt
        bm9kZSBzYWQ0IGcyYzkgZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIGcyYzkKbm9kZS9hZGQtaW5sZXQgZzJjOSBpcHg5IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQg
        ZzJjOSA3Z2FxIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGcyYzkgczRuYiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgcjBkOSBlc3Bub2RlL2xvd3Bhc3MgTG93
        JTIwUGFzcyUyMEZpbHRlcgpub2RlL3R1cm4tb24gcjBkOQpub2RlL2FkZC1pbmxldCByMGQ5IGFkOWIgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBkdHVvIGVzcG5vZGUvc3RyaW5nIGN1dG9mZl9pbnB1
        dCBjdXRvZmZfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcjBkOSBtc3kzIGVzcG5vZGUvc3RyaW5nIHJlc29uYW5jZV9pbnB1dCByZXNvbmFuY2VfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHIwZDkgeTVpeSBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2Rl
        IHNhZDQgcXpjdCBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIHF6Y3QKbm9kZS9hZGQtaW5sZXQgcXpjdCBsM2F2IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgcXpjdCAx
        anNiIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHF6Y3Qgem02dyBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgZWd3NiBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0
        b3IKbm9kZS90dXJuLW9uIGVndzYKbm9kZS9hZGQtaW5sZXQgZWd3NiAyaHhtIGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgZWd3NiB3Zm45IGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3
        YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGVndzYgNDJneiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgbHMzMCBlc3Bub2RlL2RlbGF5IEF1ZGlvJTIwRGVsYXkKbm9kZS90dXJuLW9uIGxzMzAKbm9kZS9hZGQtaW5sZXQg
        bHMzMCA1NHQwIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0Cm5vZGUvYWRkLWlubGV0IGxzMzAgZjY5NSBlc3Bub2RlL3N0cmluZyBtaXhfaW5wdXQgbWl4X2lucHV0Cm5vZGUvYWRkLWlubGV0IGxzMzAgdnY1YyBlc3Bub2RlL3N0cmluZyBm
        ZWVkYmFja19pbnB1dCBmZWVkYmFja19pbnB1dApub2RlL2FkZC1pbmxldCBsczMwIGR1NjMgZXNwbm9kZS9zdHJpbmcgbGVuZ3RoX2lucHV0IGxlbmd0aF9pbnB1dApub2RlL2FkZC1vdXRsZXQgbHMzMCBqZ2d1IGVzcG5vZGUvc3RyaW5nIG91dCBvdXQKbm9kZS9t
        b3ZlIGxmZzQgMjMgMjMKbm9kZS9tb3ZlIGhwa3UgMTIxMiAyMjkKbm9kZS9tb3ZlIDJxbTIgMjk1IDIwOQpub2RlL21vdmUgZzJjOSA1MTIgMzgKbm9kZS9tb3ZlIHIwZDkgNzU5IDEyNgpub2RlL21vdmUgcXpjdCA1MDIgMjM4Cm5vZGUvbW92ZSBlZ3c2IDUwNyAx
        MzgKbm9kZS9tb3ZlIGxzMzAgOTczIDIwMApvdXRsZXQvY29ubmVjdCBmcmdqIDdnYXEgOXVlOQpvdXRsZXQvY29ubmVjdCBzNG5iIGFkOWIgNHE3eQpvdXRsZXQvY29ubmVjdCB3cHQ3IGlweDkgNGs3aApvdXRsZXQvY29ubmVjdCBmbXBwIGwzYXYgYWlnaApvdXRs
        ZXQvY29ubmVjdCB6bTZ3IG1zeTMgZGF2OApvdXRsZXQvY29ubmVjdCBnY2NtIDJoeG0gYWNqbQpvdXRsZXQvY29ubmVjdCA0Mmd6IGR0dW8gbTl1NgpvdXRsZXQvY29ubmVjdCB5NWl5IDU0dDAgemZzaQpvdXRsZXQvY29ubmVjdCBqZ2d1IHcwYnIgZm1kdwpvdXRs
        ZXQvY29ubmVjdCAycXJkIGY2OTUgOGIwbgpvdXRsZXQvY29ubmVjdCAwdGdhIHZ2NWMgemhkagpvdXRsZXQvY29ubmVjdCBnZ2lyIGR1NjMgZHMwdgpub2RlL3VwZGF0ZS1pbmxldCBnMmM5IDdnYXEgd2F2ZXRhYmxlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQg
        cjBkOSBhZDliIGF1ZGlvX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgcXpjdCAxanNiIHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGVndzYgMmh4bSBmcmVxdWVuY3lfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBlZ3c2IHdmbjkgd2F2ZXRh
        YmxlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgbHMzMCA1NHQwIGF1ZGlvX2lucHV0IDA=
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleLFO *moduleLFO_3 = new ModuleLFO();
//        ModuleLFO *moduleLFO_4 = new ModuleLFO();
//        ModuleDelay *moduleDelay_2 = new ModuleDelay();


//        moduleWavetableOsc_3->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_3;
//        moduleWavetableOsc_3->frequency_input= &param[0];
//        moduleLFO_3->frequency_input= &param[4];
//        moduleLowpassFilter_1->resonance_input=moduleLFO_3;
//        moduleLFO_4->frequency_input= &param[3];
//        moduleLowpassFilter_1->cutoff_input=moduleLFO_4;
//        moduleDelay_2->audio_input=moduleLowpassFilter_1;
//        moduleDelay_2->mix_input= &param[5];
//        moduleDelay_2->feedback_input= &param[6];
//        moduleDelay_2->length_input= &param[7];


//        this->last_module = moduleDelay_2;


        // end of espnode86 generated code //
        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBrYXM4IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGthczgKcGF0Y2gvYWRkLW5vZGUgc2FkNCBwejJh
        IGVzcG5vZGUvZGFjIEF1ZGlvJTIwREFDCm5vZGUvdHVybi1vbiBwejJhCm5vZGUvYWRkLWlubGV0IHB6MmEgamxmMyBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApwYXRjaC9hZGQtbm9kZSBzYWQ0IHdnbmEgZXNwbm9kZS9tdWx0aXBsZXhl
        ciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gd2duYQpub2RlL2FkZC1vdXRsZXQgd2duYSA1dHcwIGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgd2duYSAwZDloIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQg
        d2duYSBqMjZnIGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgd2duYSA2M254IGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgd2duYSBscWl5IGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRs
        ZXQgd2duYSBrdDEwIGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgd2duYSBjNDdzIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgd2duYSB5cWxjIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQt
        bm9kZSBzYWQ0IHFwZ2UgZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIHFwZ2UKbm9kZS9hZGQtaW5sZXQgcXBnZSA2ZzVuIGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQg
        cXBnZSAzZTd5IGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHFwZ2UgenduMyBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgaXE2ZSBlc3Bub2RlL2xvd3Bhc3MgTG93
        JTIwUGFzcyUyMEZpbHRlcgpub2RlL3R1cm4tb24gaXE2ZQpub2RlL2FkZC1pbmxldCBpcTZlIHF2MjIgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgaXE2ZSB1YzA1IGVzcG5vZGUvc3RyaW5nIGN1dG9mZl9pbnB1
        dCBjdXRvZmZfaW5wdXQKbm9kZS9hZGQtaW5sZXQgaXE2ZSBzMGJzIGVzcG5vZGUvc3RyaW5nIHJlc29uYW5jZV9pbnB1dCByZXNvbmFuY2VfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGlxNmUgcWYyOCBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2Rl
        IHNhZDQgY3JmbiBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIGNyZm4Kbm9kZS9hZGQtaW5sZXQgY3JmbiBqaTJhIGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgY3JmbiBs
        OXdkIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGNyZm4gaG4xeCBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgb21rdCBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0
        b3IKbm9kZS90dXJuLW9uIG9ta3QKbm9kZS9hZGQtaW5sZXQgb21rdCA3YzZmIGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgb21rdCBjOWduIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3
        YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IG9ta3QgbWVnaiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgZ2I5byBlc3Bub2RlL2RlbGF5IEF1ZGlvJTIwRGVsYXkKbm9kZS90dXJuLW9uIGdiOW8Kbm9kZS9hZGQtaW5sZXQg
        Z2I5byBpZm0wIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0Cm5vZGUvYWRkLWlubGV0IGdiOW8gaG9rayBlc3Bub2RlL3N0cmluZyBtaXhfaW5wdXQgbWl4X2lucHV0Cm5vZGUvYWRkLWlubGV0IGdiOW8gcDRseCBlc3Bub2RlL3N0cmluZyBm
        ZWVkYmFja19pbnB1dCBmZWVkYmFja19pbnB1dApub2RlL2FkZC1pbmxldCBnYjlvIDZwYTQgZXNwbm9kZS9zdHJpbmcgbGVuZ3RoX2lucHV0IGxlbmd0aF9pbnB1dApub2RlL2FkZC1vdXRsZXQgZ2I5byBwa2lyIGVzcG5vZGUvc3RyaW5nIG91dCBvdXQKcGF0Y2gv
        YWRkLW5vZGUgc2FkNCBjMHdhIGVzcG5vZGUvbWl4ZXIyIDIlMjBDaCUyME1peGVyCm5vZGUvdHVybi1vbiBjMHdhCm5vZGUvYWRkLWlubGV0IGMwd2EgZW9ibyBlc3Bub2RlL3N0cmluZyBjaDEgY2gxCm5vZGUvYWRkLWlubGV0IGMwd2EgcWFmbSBlc3Bub2RlL3N0
        cmluZyBjaDIgY2gyCm5vZGUvYWRkLW91dGxldCBjMHdhIDNwNGcgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IHZna3kgZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIHZna3kKbm9kZS9hZGQtaW5sZXQg
        dmdreSA4MW91IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgdmdreSA0NXp6IGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHZna3kg
        N2w5aSBlc3Bub2RlL3N0cmluZyBPdXQgT3V0Cm5vZGUvbW92ZSBrYXM4IDIzIDIzCm5vZGUvbW92ZSBwejJhIDEwNTQgMzI4Cm5vZGUvbW92ZSB3Z25hIDI3MiAxMTgKbm9kZS9tb3ZlIHFwZ2UgNDQxIDcKbm9kZS9tb3ZlIGlxNmUgNzAxIDg3Cm5vZGUvbW92ZSBj
        cmZuIDQ0NCAxOTYKbm9kZS9tb3ZlIG9ta3QgNDQyIDEwMgpub2RlL21vdmUgZ2I5byA3MDAgMjMxCm5vZGUvbW92ZSBjMHdhIDkxNyAzMjQKbm9kZS9tb3ZlIHZna3kgNDUyIDM1NgpvdXRsZXQvY29ubmVjdCBqMjZnIDNlN3kgOXdqMQpvdXRsZXQvY29ubmVjdCB6
        d24zIHF2MjIgNmE2ZwpvdXRsZXQvY29ubmVjdCA1dHcwIDZnNW4gaTZycQpvdXRsZXQvY29ubmVjdCBscWl5IGppMmEgbjl6ZQpvdXRsZXQvY29ubmVjdCBobjF4IHMwYnMgcmdjawpvdXRsZXQvY29ubmVjdCA2M254IDdjNmYgNXUxNgpvdXRsZXQvY29ubmVjdCBt
        ZWdqIHVjMDUgejRpYwpvdXRsZXQvY29ubmVjdCBxZjI4IGlmbTAgY2Z0MQpvdXRsZXQvY29ubmVjdCBrdDEwIGhva2sgZzV1ZApvdXRsZXQvY29ubmVjdCBjNDdzIHA0bHggd3k1dgpvdXRsZXQvY29ubmVjdCB5cWxjIDZwYTQgczczYQpvdXRsZXQvY29ubmVjdCBw
        a2lyIGVvYm8gNGM3NQpvdXRsZXQvY29ubmVjdCAzcDRnIGpsZjMgYmZnNwpvdXRsZXQvY29ubmVjdCA1dHcwIDgxb3UgZjh2dApvdXRsZXQvY29ubmVjdCBqMjZnIDQ1enogM3ZmeApvdXRsZXQvY29ubmVjdCA3bDlpIHFhZm0gMXhibApub2RlL3VwZGF0ZS1pbmxl
        dCBxcGdlIDZnNW4gZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgcXBnZSAzZTd5IHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGlxNmUgcXYyMiBhdWRpb19pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGlxNmUgdWMwNSBjdXRv
        ZmZfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBpcTZlIHMwYnMgcmVzb25hbmNlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgY3JmbiBqaTJhIGZyZXF1ZW5jeV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGNyZm4gbDl3ZCB3YXZldGFibGVfaW5wdXQgMApu
        b2RlL3VwZGF0ZS1pbmxldCBvbWt0IDdjNmYgZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgb21rdCBjOWduIHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGdiOW8gaWZtMCBhdWRpb19pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0
        IGdiOW8gaG9rayBtaXhfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBnYjlvIHA0bHggZmVlZGJhY2tfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBnYjlvIDZwYTQgbGVuZ3RoX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgdmdreSA4MW91IGZyZXF1ZW5jeV9p
        bnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHZna3kgNDV6eiB3YXZldGFibGVfaW5wdXQgMA==
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleLFO *moduleLFO_1 = new ModuleLFO();
//        ModuleLFO *moduleLFO_2 = new ModuleLFO();
//        ModuleDelay *moduleDelay_1 = new ModuleDelay();
//        ModuleMixer2 *moduleMixer2_1 = new ModuleMixer2();
//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();


//        moduleWavetableOsc_1->wavetable_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleWavetableOsc_1;
//        moduleWavetableOsc_1->frequency_input= &param[0];
//        moduleLFO_1->frequency_input= &param[4];
//        moduleLowpassFilter_1->resonance_input=moduleLFO_1;
//        moduleLFO_2->frequency_input= &param[3];
//        moduleLowpassFilter_1->cutoff_input=moduleLFO_2;
//        moduleDelay_1->audio_input=moduleLowpassFilter_1;
//        moduleDelay_1->mix_input= &param[5];
//        moduleDelay_1->feedback_input= &param[6];
//        moduleDelay_1->length_input= &param[7];
//        moduleMixer2_1->ch1=moduleDelay_1;
//        moduleWavetableOsc_2->frequency_input= &param[0];
//        moduleWavetableOsc_2->wavetable_input= &param[2];
//        moduleMixer2_1->ch2=moduleWavetableOsc_2;


//        this->last_module = moduleMixer2_1;


        // end of espnode86 generated code //

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCAzMWJtIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIDMxYm0KcGF0Y2gvYWRkLW5vZGUgc2FkNCA2eXNw
        IGVzcG5vZGUvYml0Y3J1c2hlciBCaXQlMjBDcnVzaGVyCm5vZGUvdHVybi1vbiA2eXNwCm5vZGUvYWRkLWlubGV0IDZ5c3AgbXd6OSBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApub2RlL2FkZC1pbmxldCA2eXNwIDFneHggZXNwbm9kZS9z
        dHJpbmcgYml0X2lucHV0IGJpdF9pbnB1dApub2RlL2FkZC1vdXRsZXQgNnlzcCA4N2R4IGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBrYm04IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiBrYm04Cm5v
        ZGUvYWRkLWlubGV0IGtibTggbDR5biBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IGtibTggaGpmcSBlc3Bub2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRk
        LW91dGxldCBrYm04IG84N3ggZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGp3bXIgZXNwbm9kZS9tdWx0aXBsZXhlciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gandtcgpub2RlL2FkZC1vdXRsZXQgandtciA3Mm8wIGVzcG5vZGUv
        c3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgandtciBuYTI2IGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQgandtciBuODg5IGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgandtciAzNHV0IGVzcG5v
        ZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgandtciA5ZHpqIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRsZXQgandtciBvd290IGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgandtciA4MGYwIGVz
        cG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgandtciBjM2FoIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQtbm9kZSBzYWQ0IDc0YXEgZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJuLW9uIDc0YXEKbm9kZS9hZGQt
        aW5sZXQgNzRhcSAzMG11IGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0Cm5vZGUvbW92ZSAzMWJtIDMwIDIwCm5vZGUvbW92ZSA2eXNwIDg3NyA2Mgpub2RlL21vdmUga2JtOCA2MjcgNDgKbm9kZS9tb3ZlIGp3bXIgNDM2IDg1Cm5vZGUvbW92
        ZSA3NGFxIDEwOTYgNjcKb3V0bGV0L2Nvbm5lY3Qgbzg3eCBtd3o5IGl3dXkKb3V0bGV0L2Nvbm5lY3QgODdkeCAzMG11IHo3MHAKb3V0bGV0L2Nvbm5lY3QgNzJvMCBsNHluIGt1NWMKb3V0bGV0L2Nvbm5lY3QgbmEyNiBoamZxIGt2b3MKb3V0bGV0L2Nvbm5lY3Qg
        bjg4OSAxZ3h4IHhtYWEKbm9kZS91cGRhdGUtaW5sZXQgNnlzcCBtd3o5IGF1ZGlvX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgNnlzcCAxZ3h4IGJpdF9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGtibTggbDR5biBmcmVxdWVuY3lfaW5wdXQgMApub2RlL3Vw
        ZGF0ZS1pbmxldCBrYm04IGhqZnEgd2F2ZXRhYmxlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgNzRhcSAzMG11IGF1ZGlvX2lucHV0IDA=
        --ENDESPNODEPATCH--

        */



//        ModuleBitReducer *moduleBitReducer_1 = new ModuleBitReducer();
//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();


//        moduleBitReducer_1->audio_input=moduleWavetableOsc_1;
//        moduleWavetableOsc_1->frequency_input= &param[0];
//        moduleWavetableOsc_1->wavetable_input= &param[1];
//        moduleBitReducer_1->bit_input= &param[2];


//        this->last_module = moduleBitReducer_1;


        // end of espnode86 generated code //

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCAzMWJtIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIDMxYm0KcGF0Y2gvYWRkLW5vZGUgc2FkNCA2eXNw
        IGVzcG5vZGUvYml0Y3J1c2hlciBCaXQlMjBDcnVzaGVyCm5vZGUvdHVybi1vbiA2eXNwCm5vZGUvYWRkLWlubGV0IDZ5c3AgbXd6OSBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApub2RlL2FkZC1pbmxldCA2eXNwIDFneHggZXNwbm9kZS9z
        dHJpbmcgYml0X2lucHV0IGJpdF9pbnB1dApub2RlL2FkZC1vdXRsZXQgNnlzcCA4N2R4IGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBrYm04IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiBrYm04Cm5v
        ZGUvYWRkLWlubGV0IGtibTggbDR5biBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IGtibTggaGpmcSBlc3Bub2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRk
        LW91dGxldCBrYm04IG84N3ggZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGp3bXIgZXNwbm9kZS9tdWx0aXBsZXhlciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gandtcgpub2RlL2FkZC1vdXRsZXQgandtciA3Mm8wIGVzcG5vZGUv
        c3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgandtciBuYTI2IGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQgandtciBuODg5IGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgandtciAzNHV0IGVzcG5v
        ZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgandtciA5ZHpqIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRsZXQgandtciBvd290IGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgandtciA4MGYwIGVz
        cG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgandtciBjM2FoIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQtbm9kZSBzYWQ0IDc0YXEgZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJuLW9uIDc0YXEKbm9kZS9hZGQt
        aW5sZXQgNzRhcSAzMG11IGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgYXVkNyBlc3Bub2RlL2xmbyBMRiUyME9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIGF1ZDcKbm9kZS9hZGQtaW5sZXQgYXVkNyAwaDhz
        IGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgYXVkNyBjcXR2IGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IGF1ZDcgczZweCBlc3Bu
        b2RlL3N0cmluZyBPdXQgT3V0Cm5vZGUvbW92ZSAzMWJtIDMwIDIwCm5vZGUvbW92ZSA2eXNwIDg3NyA2Mgpub2RlL21vdmUga2JtOCA2MjcgNDgKbm9kZS9tb3ZlIGp3bXIgNDM2IDg1Cm5vZGUvbW92ZSA3NGFxIDEwOTYgNjcKbm9kZS9tb3ZlIGF1ZDcgNjI5IDE0
        MApvdXRsZXQvY29ubmVjdCBvODd4IG13ejkgaXd1eQpvdXRsZXQvY29ubmVjdCA4N2R4IDMwbXUgejcwcApvdXRsZXQvY29ubmVjdCA3Mm8wIGw0eW4ga3U1YwpvdXRsZXQvY29ubmVjdCBuYTI2IGhqZnEga3ZvcwpvdXRsZXQvY29ubmVjdCBuODg5IDBoOHMgNnB6
        aApvdXRsZXQvY29ubmVjdCBzNnB4IDFneHggbHoyYwpvdXRsZXQvY29ubmVjdCAzNHV0IGNxdHYgYXM0OQpub2RlL3VwZGF0ZS1pbmxldCA2eXNwIG13ejkgYXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBrYm04IGw0eW4gZnJlcXVlbmN5X2lucHV0IDAK
        bm9kZS91cGRhdGUtaW5sZXQga2JtOCBoamZxIHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IDc0YXEgMzBtdSBhdWRpb19pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGF1ZDcgMGg4cyBmcmVxdWVuY3lfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxl
        dCBhdWQ3IGNxdHYgd2F2ZXRhYmxlX2lucHV0IDA=
        --ENDESPNODEPATCH--

        */



//        ModuleBitReducer *moduleBitReducer_1 = new ModuleBitReducer();
//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
//        ModuleLFO *moduleLFO_1 = new ModuleLFO();


//        moduleBitReducer_1->audio_input=moduleWavetableOsc_1;
//        moduleWavetableOsc_1->frequency_input= &param[0];
//        moduleWavetableOsc_1->wavetable_input= &param[1];
//        moduleLFO_1->frequency_input= &param[2];
//        moduleBitReducer_1->bit_input=moduleLFO_1;
//        moduleLFO_1->wavetable_input= &param[3];


//        this->last_module = moduleBitReducer_1;


        // end of espnode86 generated code //

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCAzMWJtIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIDMxYm0KcGF0Y2gvYWRkLW5vZGUgc2FkNCBrYm04
        IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiBrYm04Cm5vZGUvYWRkLWlubGV0IGtibTggbDR5biBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IGtibTggaGpmcSBlc3Bu
        b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCBrYm04IG84N3ggZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGp3bXIgZXNwbm9kZS9tdWx0aXBsZXhlciBNdWx0aXBsZXhlcgpu
        b2RlL3R1cm4tb24gandtcgpub2RlL2FkZC1vdXRsZXQgandtciA3Mm8wIGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgandtciBuYTI2IGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQgandtciBuODg5IGVzcG5v
        ZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgandtciAzNHV0IGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgandtciA5ZHpqIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRsZXQgandtciBvd290IGVz
        cG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgandtciA4MGYwIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgandtciBjM2FoIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQtbm9kZSBzYWQ0IDc0YXEg
        ZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJuLW9uIDc0YXEKbm9kZS9hZGQtaW5sZXQgNzRhcSAzMG11IGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgaTZ4MyBlc3Bub2RlL29zY2lsbGF0b3Ig
        T3NjaWxsYXRvcgpub2RlL3R1cm4tb24gaTZ4Mwpub2RlL2FkZC1pbmxldCBpNngzIHdoMjYgZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApub2RlL2FkZC1pbmxldCBpNngzIG10bXQgZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxl
        X2lucHV0IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgaTZ4MyByNzNyIGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCByMWJxIGVzcG5vZGUvbWl4ZXIyIDIlMjBDaCUyME1peGVyCm5vZGUvdHVybi1vbiByMWJxCm5vZGUv
        YWRkLWlubGV0IHIxYnEganp6ciBlc3Bub2RlL3N0cmluZyBjaDEgY2gxCm5vZGUvYWRkLWlubGV0IHIxYnEgZGVrZyBlc3Bub2RlL3N0cmluZyBjaDIgY2gyCm5vZGUvYWRkLW91dGxldCByMWJxIDRxY3AgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApub2RlL21vdmUg
        MzFibSAzMCAyMApub2RlL21vdmUga2JtOCA2MjcgNDgKbm9kZS9tb3ZlIGp3bXIgNDM2IDg1Cm5vZGUvbW92ZSA3NGFxIDEwOTYgNjcKbm9kZS9tb3ZlIGk2eDMgNjI0IDE0NApub2RlL21vdmUgcjFicSA4NzggODkKb3V0bGV0L2Nvbm5lY3QgNzJvMCBsNHluIGt1
        NWMKb3V0bGV0L2Nvbm5lY3QgbmEyNiBoamZxIGt2b3MKb3V0bGV0L2Nvbm5lY3Qgbjg4OSB3aDI2IG02cTQKb3V0bGV0L2Nvbm5lY3QgMzR1dCBtdG10IDc4ZGIKb3V0bGV0L2Nvbm5lY3Qgbzg3eCBqenpyIGRvNGgKb3V0bGV0L2Nvbm5lY3QgcjczciBkZWtnIDhq
        MmIKb3V0bGV0L2Nvbm5lY3QgNHFjcCAzMG11IHNpdTcKbm9kZS91cGRhdGUtaW5sZXQga2JtOCBsNHluIGZyZXF1ZW5jeV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGtibTggaGpmcSB3YXZldGFibGVfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBpNngzIHdo
        MjYgZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgaTZ4MyBtdG10IHdhdmV0YWJsZV9pbnB1dCAw
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
//        ModuleMixer2 *moduleMixer2_1 = new ModuleMixer2();


//        moduleWavetableOsc_1->frequency_input= &param[0];
//        moduleWavetableOsc_1->wavetable_input= &param[1];
//        moduleWavetableOsc_2->frequency_input= &param[2];
//        moduleWavetableOsc_2->wavetable_input= &param[3];
//        moduleMixer2_1->ch1=moduleWavetableOsc_1;
//        moduleMixer2_1->ch2=moduleWavetableOsc_2;


//        this->last_module = moduleMixer2_1;


        // end of espnode86 generated code //


        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCAzMWJtIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIDMxYm0KcGF0Y2gvYWRkLW5vZGUgc2FkNCBrYm04
        IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiBrYm04Cm5vZGUvYWRkLWlubGV0IGtibTggbDR5biBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IGtibTggaGpmcSBlc3Bu
        b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCBrYm04IG84N3ggZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGp3bXIgZXNwbm9kZS9tdWx0aXBsZXhlciBNdWx0aXBsZXhlcgpu
        b2RlL3R1cm4tb24gandtcgpub2RlL2FkZC1vdXRsZXQgandtciA3Mm8wIGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgandtciBuYTI2IGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQgandtciBuODg5IGVzcG5v
        ZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgandtciAzNHV0IGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgandtciA5ZHpqIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRsZXQgandtciBvd290IGVz
        cG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgandtciA4MGYwIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgandtciBjM2FoIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQtbm9kZSBzYWQ0IDc0YXEg
        ZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJuLW9uIDc0YXEKbm9kZS9hZGQtaW5sZXQgNzRhcSAzMG11IGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgaTZ4MyBlc3Bub2RlL29zY2lsbGF0b3Ig
        T3NjaWxsYXRvcgpub2RlL3R1cm4tb24gaTZ4Mwpub2RlL2FkZC1pbmxldCBpNngzIHdoMjYgZXNwbm9kZS9zdHJpbmcgZnJlcXVlbmN5X2lucHV0IGZyZXF1ZW5jeV9pbnB1dApub2RlL2FkZC1pbmxldCBpNngzIG10bXQgZXNwbm9kZS9zdHJpbmcgd2F2ZXRhYmxl
        X2lucHV0IHdhdmV0YWJsZV9pbnB1dApub2RlL2FkZC1vdXRsZXQgaTZ4MyByNzNyIGVzcG5vZGUvc3RyaW5nIE91dCBPdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCByMWJxIGVzcG5vZGUvbWl4ZXIyIDIlMjBDaCUyME1peGVyCm5vZGUvdHVybi1vbiByMWJxCm5vZGUv
        YWRkLWlubGV0IHIxYnEganp6ciBlc3Bub2RlL3N0cmluZyBjaDEgY2gxCm5vZGUvYWRkLWlubGV0IHIxYnEgZGVrZyBlc3Bub2RlL3N0cmluZyBjaDIgY2gyCm5vZGUvYWRkLW91dGxldCByMWJxIDRxY3AgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQt
        bm9kZSBzYWQ0IDF0ZnEgZXNwbm9kZS9kZWxheSBBdWRpbyUyMERlbGF5Cm5vZGUvdHVybi1vbiAxdGZxCm5vZGUvYWRkLWlubGV0IDF0ZnEgcnZ6ZSBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApub2RlL2FkZC1pbmxldCAxdGZxIGpwMWQg
        ZXNwbm9kZS9zdHJpbmcgbWl4X2lucHV0IG1peF9pbnB1dApub2RlL2FkZC1pbmxldCAxdGZxIGxicXAgZXNwbm9kZS9zdHJpbmcgZmVlZGJhY2tfaW5wdXQgZmVlZGJhY2tfaW5wdXQKbm9kZS9hZGQtaW5sZXQgMXRmcSBxM2lzIGVzcG5vZGUvc3RyaW5nIGxlbmd0
        aF9pbnB1dCBsZW5ndGhfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IDF0ZnEgYjdiMSBlc3Bub2RlL3N0cmluZyBvdXQgb3V0Cm5vZGUvbW92ZSAzMWJtIDMwIDIwCm5vZGUvbW92ZSBrYm04IDU3NiAyNApub2RlL21vdmUgandtciAzODggMTE1Cm5vZGUvbW92ZSA3NGFx
        IDEyMDQgMjA3Cm5vZGUvbW92ZSBpNngzIDU4MCAxMjEKbm9kZS9tb3ZlIHIxYnEgODE5IDY1Cm5vZGUvbW92ZSAxdGZxIDk1NSAxODAKb3V0bGV0L2Nvbm5lY3QgNzJvMCBsNHluIGt1NWMKb3V0bGV0L2Nvbm5lY3QgbmEyNiBoamZxIGt2b3MKb3V0bGV0L2Nvbm5l
        Y3Qgbjg4OSB3aDI2IG02cTQKb3V0bGV0L2Nvbm5lY3QgMzR1dCBtdG10IDc4ZGIKb3V0bGV0L2Nvbm5lY3Qgbzg3eCBqenpyIGRvNGgKb3V0bGV0L2Nvbm5lY3QgcjczciBkZWtnIDhqMmIKb3V0bGV0L2Nvbm5lY3QgNHFjcCBydnplIGx4dnEKb3V0bGV0L2Nvbm5l
        Y3QgOWR6aiBqcDFkIHEyeWMKb3V0bGV0L2Nvbm5lY3Qgb3dvdCBsYnFwIGtxYnMKb3V0bGV0L2Nvbm5lY3QgODBmMCBxM2lzIGd4MjEKb3V0bGV0L2Nvbm5lY3QgYjdiMSAzMG11IG8xYjUKbm9kZS91cGRhdGUtaW5sZXQga2JtOCBsNHluIGZyZXF1ZW5jeV9pbnB1
        dCAwCm5vZGUvdXBkYXRlLWlubGV0IGtibTggaGpmcSB3YXZldGFibGVfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBpNngzIHdoMjYgZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgaTZ4MyBtdG10IHdhdmV0YWJsZV9pbnB1dCAw
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
//        ModuleMixer2 *moduleMixer2_1 = new ModuleMixer2();
//        ModuleDelay *moduleDelay_2 = new ModuleDelay();


//        moduleWavetableOsc_1->frequency_input= &param[0];
//        moduleWavetableOsc_1->wavetable_input= &param[1];
//        moduleWavetableOsc_2->frequency_input= &param[2];
//        moduleWavetableOsc_2->wavetable_input= &param[3];
//        moduleMixer2_1->ch1=moduleWavetableOsc_1;
//        moduleMixer2_1->ch2=moduleWavetableOsc_2;
//        moduleDelay_2->audio_input=moduleMixer2_1;
//        moduleDelay_2->mix_input= &param[4];
//        moduleDelay_2->feedback_input= &param[5];
//        moduleDelay_2->length_input= &param[6];


//        this->last_module = moduleDelay_2;


        // end of espnode86 generated code //

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCByY3JzIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIHJjcnMKcGF0Y2gvYWRkLW5vZGUgc2FkNCBnaDFn
        IGVzcG5vZGUvdmNhIFZDQQpub2RlL3R1cm4tb24gZ2gxZwpub2RlL2FkZC1pbmxldCBnaDFnIDlyc24gZXNwbm9kZS9zdHJpbmcgYXVkaW8gYXVkaW8Kbm9kZS9hZGQtaW5sZXQgZ2gxZyBtcGY1IGVzcG5vZGUvc3RyaW5nIGN2IGN2Cm5vZGUvYWRkLW91dGxldCBn
        aDFnIGF6cnogZXNwbm9kZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDQwMm0gZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIDQwMm0Kbm9kZS9hZGQtaW5sZXQgNDAybSAzZTY0IGVzcG5vZGUvc3RyaW5nIGZyZXF1
        ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgNDAybSBjeGVvIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IDQwMm0ganp6ZiBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBh
        dGNoL2FkZC1ub2RlIHNhZDQgb2U0aCBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5vZGUvdHVybi1vbiBvZTRoCm5vZGUvYWRkLW91dGxldCBvZTRoIG4zMHAgZXNwbm9kZS9zdHJpbmcgUG90MSBQb3QxCm5vZGUvYWRkLW91dGxldCBvZTRoIGF5cWog
        ZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCBvZTRoIGhvMzUgZXNwbm9kZS9zdHJpbmcgUG90MyBQb3QzCm5vZGUvYWRkLW91dGxldCBvZTRoIHVrbnkgZXNwbm9kZS9zdHJpbmcgUG90NCBQb3Q0Cm5vZGUvYWRkLW91dGxldCBvZTRoIGs4
        c3YgZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCBvZTRoIDJ6bmwgZXNwbm9kZS9zdHJpbmcgUG90NiBQb3Q2Cm5vZGUvYWRkLW91dGxldCBvZTRoIDJmb2YgZXNwbm9kZS9zdHJpbmcgUG90NyBQb3Q3Cm5vZGUvYWRkLW91dGxldCBvZTRo
        IGRrcXggZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4CnBhdGNoL2FkZC1ub2RlIHNhZDQgYnUzYSBlc3Bub2RlL2RhYyBBdWRpbyUyMERBQwpub2RlL3R1cm4tb24gYnUzYQpub2RlL2FkZC1pbmxldCBidTNhIHI5aDggZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQg
        YXVkaW9faW5wdXQKbm9kZS9tb3ZlIHJjcnMgMzAgMjAKbm9kZS9tb3ZlIGdoMWcgNzU2IDE2Nwpub2RlL21vdmUgNDAybSA0ODcgMTM2Cm5vZGUvbW92ZSBvZTRoIDMyMiAxNTgKbm9kZS9tb3ZlIGJ1M2EgOTYxIDE3MgpvdXRsZXQvY29ubmVjdCBqenpmIDlyc24g
        MWRvZQpvdXRsZXQvY29ubmVjdCBuMzBwIDNlNjQgcjN6dApvdXRsZXQvY29ubmVjdCBheXFqIGN4ZW8gMjE3NQpvdXRsZXQvY29ubmVjdCBobzM1IG1wZjUgOWg0dgpvdXRsZXQvY29ubmVjdCBhenJ6IHI5aDggMWx5Nwpub2RlL3VwZGF0ZS1pbmxldCBnaDFnIDly
        c24gYXVkaW8gMApub2RlL3VwZGF0ZS1pbmxldCBnaDFnIG1wZjUgY3YgMApub2RlL3VwZGF0ZS1pbmxldCA0MDJtIDNlNjQgZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgNDAybSBjeGVvIHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlu
        bGV0IGJ1M2EgcjloOCBhdWRpb19pbnB1dCAw
        --ENDESPNODEPATCH--

        */



//        ModuleVCA *moduleVCA_1 = new ModuleVCA();
//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();


//        moduleVCA_1->audio_input=moduleWavetableOsc_1;
//        moduleWavetableOsc_1->frequency_input= &param[0];
//        moduleWavetableOsc_1->wavetable_input= &param[1];
//        moduleVCA_1->cv_input= &param[2];


//        this->last_module = moduleVCA_1;

        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCB2bXZuIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIHZtdm4KcGF0Y2gvYWRkLW5vZGUgc2FkNCAwdzgx
        IGVzcG5vZGUvdmNhIFZDQQpub2RlL3R1cm4tb24gMHc4MQpub2RlL2FkZC1pbmxldCAwdzgxIGZ4ajIgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgMHc4MSA3aHphIGVzcG5vZGUvc3RyaW5nIGN2X2lucHV0IGN2
        X2lucHV0Cm5vZGUvYWRkLW91dGxldCAwdzgxIG1lbXUgZXNwbm9kZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IHRlZTUgZXNwbm9kZS9vc2NpbGxhdG9yIE9zY2lsbGF0b3IKbm9kZS90dXJuLW9uIHRlZTUKbm9kZS9hZGQtaW5sZXQgdGVlNSB6
        MGphIGVzcG5vZGUvc3RyaW5nIGZyZXF1ZW5jeV9pbnB1dCBmcmVxdWVuY3lfaW5wdXQKbm9kZS9hZGQtaW5sZXQgdGVlNSB2eWZyIGVzcG5vZGUvc3RyaW5nIHdhdmV0YWJsZV9pbnB1dCB3YXZldGFibGVfaW5wdXQKbm9kZS9hZGQtb3V0bGV0IHRlZTUgdW9qdiBl
        c3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQga3NlaSBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5vZGUvdHVybi1vbiBrc2VpCm5vZGUvYWRkLW91dGxldCBrc2VpIGd4dHEgZXNwbm9kZS9zdHJpbmcgUG90MSBQb3QxCm5v
        ZGUvYWRkLW91dGxldCBrc2VpIDZ6amIgZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCBrc2VpIGZtNW8gZXNwbm9kZS9zdHJpbmcgUG90MyBQb3QzCm5vZGUvYWRkLW91dGxldCBrc2VpIGhrc3QgZXNwbm9kZS9zdHJpbmcgUG90NCBQb3Q0
        Cm5vZGUvYWRkLW91dGxldCBrc2VpIDloNGggZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCBrc2VpIDh5eXUgZXNwbm9kZS9zdHJpbmcgUG90NiBQb3Q2Cm5vZGUvYWRkLW91dGxldCBrc2VpIGdrZjkgZXNwbm9kZS9zdHJpbmcgUG90NyBQ
        b3Q3Cm5vZGUvYWRkLW91dGxldCBrc2VpIDJjMXggZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4CnBhdGNoL2FkZC1ub2RlIHNhZDQgN2FkeCBlc3Bub2RlL2RhYyBBdWRpbyUyMERBQwpub2RlL3R1cm4tb24gN2FkeApub2RlL2FkZC1pbmxldCA3YWR4IHRidGQgZXNw
        bm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKbm9kZS9tb3ZlIHZtdm4gMzAgMjAKbm9kZS9tb3ZlIDB3ODEgNjY2IDE2MQpub2RlL21vdmUgdGVlNSA0MjUgMTMyCm5vZGUvbW92ZSBrc2VpIDI3MCAxMTcKbm9kZS9tb3ZlIDdhZHggODk5IDE1OQpv
        dXRsZXQvY29ubmVjdCB1b2p2IGZ4ajIgY2pvaApvdXRsZXQvY29ubmVjdCA2empiIHowamEgaWZ3ZQpvdXRsZXQvY29ubmVjdCBmbTVvIHZ5ZnIgMmwyYQpvdXRsZXQvY29ubmVjdCBoa3N0IDdoemEgM3oycgpvdXRsZXQvY29ubmVjdCBtZW11IHRidGQgYnFobgpu
        b2RlL3VwZGF0ZS1pbmxldCAwdzgxIGZ4ajIgYXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCAwdzgxIDdoemEgY3ZfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCB0ZWU1IHowamEgZnJlcXVlbmN5X2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgdGVlNSB2
        eWZyIHdhdmV0YWJsZV9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IDdhZHggdGJ0ZCBhdWRpb19pbnB1dCAw
        --ENDESPNODEPATCH--

        */



//        ModuleVCA *moduleVCA_1 = new ModuleVCA();
//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();


//        moduleVCA_1->audio_input=moduleWavetableOsc_1;
//        moduleWavetableOsc_1->frequency_input= &param[1];
//        moduleWavetableOsc_1->wavetable_input= &param[2];
//        moduleVCA_1->cv_input= &param[3];


//        this->last_module = moduleVCA_1;


        // end of espnode86 generated code //


        // end of espnode86 generated code //
        /*

         This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCB2NXNrIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIHY1c2sKcGF0Y2gvYWRkLW5vZGUgc2FkNCAycGhi
        IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiAycGhiCm5vZGUvYWRkLWlubGV0IDJwaGIgZmpwNSBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IDJwaGIgcjcybyBlc3Bu
        b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCAycGhiIHp4MHYgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDNya3cgZXNwbm9kZS9tdWx0aXBsZXhlciBNdWx0aXBsZXhlcgpu
        b2RlL3R1cm4tb24gM3Jrdwpub2RlL2FkZC1vdXRsZXQgM3JrdyBnN3J0IGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgM3JrdyBsbWxpIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQgM3JrdyBpdWJoIGVzcG5v
        ZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgM3JrdyBhNng1IGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgM3JrdyAwNWlwIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRsZXQgM3JrdyBtbTl6IGVz
        cG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgM3JrdyBsbHRoIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgM3JrdyB5Nml1IGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQtbm9kZSBzYWQ0IDZneHUg
        ZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJuLW9uIDZneHUKbm9kZS9hZGQtaW5sZXQgNmd4dSAxb216IGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0CnBhdGNoL2FkZC1ub2RlIHNhZDQgZWEzbyBlc3Bub2RlL3JldmVyYiBSZXZl
        cmIKbm9kZS90dXJuLW9uIGVhM28Kbm9kZS9hZGQtaW5sZXQgZWEzbyBlZmswIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0Cm5vZGUvYWRkLWlubGV0IGVhM28gdTNpYiBlc3Bub2RlL3N0cmluZyBtaXhfaW5wdXQgbWl4X2lucHV0Cm5vZGUv
        YWRkLWlubGV0IGVhM28gNWVpZyBlc3Bub2RlL3N0cmluZyBmZWVkYmFja19pbnB1dCBmZWVkYmFja19pbnB1dApub2RlL2FkZC1vdXRsZXQgZWEzbyB4ZG5jIGVzcG5vZGUvc3RyaW5nIG91dCBvdXQKbm9kZS9tb3ZlIHY1c2sgMzAgMjAKbm9kZS9tb3ZlIDJwaGIg
        NDcwIDk2Cm5vZGUvbW92ZSAzcmt3IDI5OSAxMzIKbm9kZS9tb3ZlIDZneHUgOTYyIDE1NApub2RlL21vdmUgZWEzbyA3MDkgMTQ4Cm91dGxldC9jb25uZWN0IGxtbGkgZmpwNSAzZXoyCm91dGxldC9jb25uZWN0IGl1YmggcjcybyBoNWt4Cm91dGxldC9jb25uZWN0
        IHp4MHYgZWZrMCBydTcxCm91dGxldC9jb25uZWN0IGE2eDUgdTNpYiBtODdzCm91dGxldC9jb25uZWN0IDA1aXAgNWVpZyBrNDdkCm91dGxldC9jb25uZWN0IHhkbmMgMW9teiBvdXhxCm5vZGUvdXBkYXRlLWlubGV0IDJwaGIgZmpwNSBmcmVxdWVuY3lfaW5wdXQg
        MApub2RlL3VwZGF0ZS1pbmxldCAycGhiIHI3Mm8gd2F2ZXRhYmxlX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgZWEzbyBlZmswIGF1ZGlvX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgZWEzbyB1M2liIG1peF9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGVh
        M28gNWVpZyBmZWVkYmFja19pbnB1dCAw
        --ENDESPNODEPATCH--

        */



//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
//        ModuleReverb *moduleReverb_1 = new ModuleReverb();


//        moduleWavetableOsc_1->frequency_input= &param[1];
//        moduleWavetableOsc_1->wavetable_input= &param[2];
//        moduleReverb_1->audio_input=moduleWavetableOsc_1;
//        moduleReverb_1->mix_input= &param[3];
//        moduleReverb_1->feedback_input= &param[4];


//        this->last_module = moduleReverb_1;


        // end of espnode86 generated code //



//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClock *moduleClock_1 = new ModuleClock(200,100);


//        moduleSamplePlayer_1->trigger_input=moduleClock_1;


//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClock *moduleClock_1 = new ModuleClock(200,1);


//        moduleSamplePlayer_1->trigger_input=moduleClock_1;


//        this->last_module = moduleSamplePlayer_1;


//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
//        ModuleMixer2 *moduleMixer2_1 = new ModuleMixer2();


////        moduleSamplePlayer_1->trigger_input= &param[1];
//        moduleWavetableOsc_1->frequency_input= &param[1];
//        moduleMixer2_1->ch1=moduleSamplePlayer_1;
//        moduleMixer2_1->ch2=moduleWavetableOsc_1;


//        this->last_module = moduleMixer2_1;


//        ModuleSamplePlayer *moduleSamplePlayer_2 = new ModuleSamplePlayer();
//        ModuleClock *moduleClock_2 = new ModuleClock(1,20);


//        moduleSamplePlayer_2->trigger_input=moduleClock_2;


//        this->last_module = moduleSamplePlayer_2;


//        this->last_module = osc1;



//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,20);


//        moduleSamplePlayer_1->trigger_input=moduleClock_1;
//        moduleSamplePlayer_1->sample_select= &param[1];


//        this->last_module = moduleSamplePlayer_1;




//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleSamplePlayer *moduleSamplePlayer_2 = new ModuleSamplePlayer();
//        ModuleMixer2 *moduleMixer2_1 = new ModuleMixer2();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,20);
//        ModuleClock *moduleClock_2 = new ModuleClock(1,10);


//        moduleSamplePlayer_1->trigger_input=moduleClock_1;
//        moduleSamplePlayer_1->sample_select= &param[1];
//        moduleMixer2_1->ch1=moduleSamplePlayer_1;
//        moduleMixer2_1->ch2=moduleSamplePlayer_2;
//        moduleSamplePlayer_2->trigger_input=moduleClock_2;
//        moduleSamplePlayer_2->sample_select= &param[2];


//        this->last_module = moduleMixer2_1;



//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleSamplePlayer *moduleSamplePlayer_2 = new ModuleSamplePlayer();
//        ModuleMixer2 *moduleMixer2_1 = new ModuleMixer2();
//        ModuleDelay *moduleDelay_1 = new ModuleDelay();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,20);
//        ModuleClock *moduleClock_2 = new ModuleClock(1,10);


//        moduleSamplePlayer_1->trigger_input=moduleClock_1;
//        moduleSamplePlayer_1->sample_select= &param[1];
//        moduleMixer2_1->ch1=moduleSamplePlayer_1;
//        moduleMixer2_1->ch2=moduleSamplePlayer_2;
//        moduleSamplePlayer_2->trigger_input=moduleClock_2;
//        moduleSamplePlayer_2->sample_select= &param[2];
//        moduleDelay_1->audio_input=moduleMixer2_1;
//        moduleDelay_1->mix_input= &param[3];
//        moduleDelay_1->feedback_input= &param[4];
//        moduleDelay_1->length_input= &param[5];


//        this->last_module = moduleDelay_1;

        /*

        This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBzem4xIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIHN6bjEKcGF0Y2gvYWRkLW5vZGUgc2FkNCBreWpx
        IGVzcG5vZGUvc2FtcGxlcGxheWVyIFNhbXBsZSUyMFBsYXllcgpub2RlL3R1cm4tb24ga3lqcQpub2RlL2FkZC1pbmxldCBreWpxIGE4NnYgZXNwbm9kZS9zdHJpbmcgdHJpZ2dlcl9pbnB1dCB0cmlnZ2VyX2lucHV0Cm5vZGUvYWRkLWlubGV0IGt5anEgdGZlbCBl
        c3Bub2RlL3N0cmluZyBzYW1wbGVfc2VsZWN0IHNhbXBsZV9zZWxlY3QKbm9kZS9hZGQtb3V0bGV0IGt5anEgbG11YSBlc3Bub2RlL3N0cmluZyBvdXQgb3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgeHV4ciBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5v
        ZGUvdHVybi1vbiB4dXhyCm5vZGUvYWRkLW91dGxldCB4dXhyIGc1aTggZXNwbm9kZS9zdHJpbmcgUG90MSBQb3QxCm5vZGUvYWRkLW91dGxldCB4dXhyIHQ2MzEgZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCB4dXhyIGZ1eG4gZXNwbm9k
        ZS9zdHJpbmcgUG90MyBQb3QzCm5vZGUvYWRkLW91dGxldCB4dXhyIGQ0ZDAgZXNwbm9kZS9zdHJpbmcgUG90NCBQb3Q0Cm5vZGUvYWRkLW91dGxldCB4dXhyIGIyZ2sgZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCB4dXhyIGE4cm8gZXNw
        bm9kZS9zdHJpbmcgUG90NiBQb3Q2Cm5vZGUvYWRkLW91dGxldCB4dXhyIDQyZzggZXNwbm9kZS9zdHJpbmcgUG90NyBQb3Q3Cm5vZGUvYWRkLW91dGxldCB4dXhyIHhudG8gZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4CnBhdGNoL2FkZC1ub2RlIHNhZDQgazRtNCBl
        c3Bub2RlL2Nsb2NrIENsb2NrJTIwR2VuCm5vZGUvdHVybi1vbiBrNG00Cm5vZGUvYWRkLWlubGV0IGs0bTQgaDM2NCBlc3Bub2RlL3N0cmluZyBicG0gYnBtCm5vZGUvYWRkLWlubGV0IGs0bTQgZWV2eiBlc3Bub2RlL3N0cmluZyBkaXZpc2lvbiBkaXZpc2lvbgpu
        b2RlL2FkZC1vdXRsZXQgazRtNCBzeWthIGVzcG5vZGUvc3RyaW5nIG91dCBvdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCAwYzU3IGVzcG5vZGUvZGFjIEF1ZGlvJTIwREFDCm5vZGUvdHVybi1vbiAwYzU3Cm5vZGUvYWRkLWlubGV0IDBjNTcgMmZ6cCBlc3Bub2RlL3N0
        cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGQzazQgZXNwbm9kZS9jb21tZW50IENvbW1lbnQKbm9kZS90dXJuLW9uIGQzazQKbm9kZS9hZGQtaW5sZXQgZDNrNCB6MzUzIGVzcG5vZGUvc3RyaW5nIGNvbW1lbnQgY29tbWVu
        dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDdwZzggZXNwbm9kZS9jbG9ja2RpdmlkZXIgQ2xvY2slMjBEaXZpZGVyCm5vZGUvdHVybi1vbiA3cGc4Cm5vZGUvYWRkLWlubGV0IDdwZzggenMwNCBlc3Bub2RlL3N0cmluZyBjbG9ja19pbnB1dCBjbG9ja19pbnB1dApub2Rl
        L2FkZC1pbmxldCA3cGc4IHhzOWMgZXNwbm9kZS9zdHJpbmcgZGl2aXNpb25faW5wdXQgZGl2aXNpb25faW5wdXQKbm9kZS9hZGQtb3V0bGV0IDdwZzggbGkxayBlc3Bub2RlL3N0cmluZyBvdXQgb3V0Cm5vZGUvbW92ZSBzem4xIDMwIDIwCm5vZGUvbW92ZSBreWpx
        IDk0OSAzODEKbm9kZS9tb3ZlIHh1eHIgNDI1IDQwNwpub2RlL21vdmUgazRtNCAzMjkgMjM1Cm5vZGUvbW92ZSAwYzU3IDEyOTcgNDgyCm5vZGUvbW92ZSBkM2s0IDEwMzYgNjkwCm5vZGUvbW92ZSA3cGc4IDcxNSAzNzYKb3V0bGV0L2Nvbm5lY3QgdDYzMSB4czlj
        IGVqZ3MKb3V0bGV0L2Nvbm5lY3Qgc3lrYSB6czA0IHR1dGoKb3V0bGV0L2Nvbm5lY3QgbGkxayBhODZ2IHRkaDEKb3V0bGV0L2Nvbm5lY3QgbG11YSAyZnpwIG9jZTMKbm9kZS91cGRhdGUtaW5sZXQgazRtNCBoMzY0IGJwbSAxCm5vZGUvdXBkYXRlLWlubGV0IGs0
        bTQgZWV2eiBkaXZpc2lvbiAyMApub2RlL3VwZGF0ZS1pbmxldCBkM2s0IHozNTMgY29tbWVudCBCRUFUJTIwR0VORVJBVE9SJTBBKEMpJTIwMTk5OCUyMEJVREklMjBQUkFLT1NBCm5vZGUvdXBkYXRlLWlubGV0IDdwZzggenMwNCBjbG9ja19pbnB1dCAwCm5vZGUv
        dXBkYXRlLWlubGV0IDdwZzggeHM5YyBkaXZpc2lvbl9pbnB1dCAw
        --ENDESPNODEPATCH--

        */



//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClockDivider *moduleClockDivider_2 = new ModuleClockDivider();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,20);


//        moduleClockDivider_2->division_input= &param[1];
//        moduleClockDivider_2->clock_input=moduleClock_1;
//        moduleSamplePlayer_1->trigger_input=moduleClockDivider_2;


//        this->last_module = moduleSamplePlayer_1;



//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClockDivider *moduleClockDivider_2 = new ModuleClockDivider();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,10);


//        moduleClockDivider_2->division_input= &param[1];
//        moduleClockDivider_2->clock_input=moduleClock_1;
//        moduleSamplePlayer_1->trigger_input=moduleClockDivider_2;


//        this->last_module = moduleSamplePlayer_1;

        // end of espnode86 generated code //



//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,10);


//        moduleSamplePlayer_1->trigger_input=moduleClock_1;
//        moduleSamplePlayer_1->sample_select= &param[1];


//        this->last_module = moduleSamplePlayer_1;


//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClockDivider *moduleClockDivider_4 = new ModuleClockDivider();
//        ModuleMixer2 *moduleMixer2_2 = new ModuleMixer2();
//        ModuleSamplePlayer *moduleSamplePlayer_3 = new ModuleSamplePlayer();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,10);


//        moduleSamplePlayer_1->trigger_input=moduleClock_1;
//        moduleSamplePlayer_1->sample_select= &param[1];
//        moduleClockDivider_4->clock_input=moduleClock_1;
//        moduleClockDivider_4->division_input= &param[2];
//        moduleSamplePlayer_3->trigger_input=moduleClockDivider_4;
//        moduleMixer2_2->ch2=moduleSamplePlayer_3;
//        moduleMixer2_2->ch1=moduleSamplePlayer_1;
//        moduleSamplePlayer_3->sample_select= &param[3];


//        this->last_module = moduleMixer2_2;




//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClockDivider *moduleClockDivider_4 = new ModuleClockDivider();
//        ModuleSamplePlayer *moduleSamplePlayer_3 = new ModuleSamplePlayer();
//        ModuleClockDivider *moduleClockDivider_5 = new ModuleClockDivider();
//        ModuleMixer3 *moduleMixer3_1 = new ModuleMixer3();
//        ModuleSamplePlayer *moduleSamplePlayer_4 = new ModuleSamplePlayer();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,10);


//        moduleSamplePlayer_1->trigger_input=moduleClock_1;
//        moduleSamplePlayer_1->sample_select= &param[1];
//        moduleClockDivider_4->clock_input=moduleClock_1;
//        moduleClockDivider_4->division_input= &param[2];
//        moduleSamplePlayer_3->trigger_input=moduleClockDivider_4;
//        moduleSamplePlayer_3->sample_select= &param[3];
//        moduleClockDivider_5->clock_input=moduleClock_1;
//        moduleClockDivider_5->division_input= &param[4];
//        moduleSamplePlayer_4->trigger_input=moduleClockDivider_5;
//        moduleSamplePlayer_4->sample_select= &param[5];
//        moduleMixer3_1->ch3=moduleSamplePlayer_4;
//        moduleMixer3_1->ch2=moduleSamplePlayer_3;
//        moduleMixer3_1->ch1=moduleSamplePlayer_1;


//        this->last_module = moduleMixer3_1;



//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClockDivider *moduleClockDivider_4 = new ModuleClockDivider();
//        ModuleSamplePlayer *moduleSamplePlayer_3 = new ModuleSamplePlayer();
//        ModuleClockDivider *moduleClockDivider_5 = new ModuleClockDivider();
//        ModuleMixer3 *moduleMixer3_1 = new ModuleMixer3();
//        ModuleSamplePlayer *moduleSamplePlayer_4 = new ModuleSamplePlayer();
//        ModuleBitReducer *moduleBitReducer_1 = new ModuleBitReducer();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,1);
//        ModuleTinySynth *ModuleTinySynth_1 = new ModuleTinySynth();

//        moduleSamplePlayer_1->trigger_input=moduleClock_1;
//        moduleSamplePlayer_1->sample_select= &param[1];
//        moduleClockDivider_4->clock_input=moduleClock_1;
//        moduleClockDivider_4->division_input= &param[2];
//        moduleSamplePlayer_3->trigger_input=moduleClockDivider_4;
//        moduleSamplePlayer_3->sample_select= &param[3];
//        moduleClockDivider_5->clock_input=moduleClock_1;
//        moduleClockDivider_5->division_input= &param[4];
//        moduleSamplePlayer_4->trigger_input=moduleClockDivider_5;
//        moduleSamplePlayer_4->sample_select= &param[5];
//        moduleMixer3_1->ch3=moduleSamplePlayer_4;
//        moduleMixer3_1->ch2=moduleSamplePlayer_3;
//        moduleMixer3_1->ch1=moduleSamplePlayer_1;
//        moduleBitReducer_1->audio_input=moduleMixer3_1;
//        moduleBitReducer_1->bit_input= &param[6];


//        this->last_module = moduleBitReducer_1;

        /*

        This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCB1NnllIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIHU2eWUKcGF0Y2gvYWRkLW5vZGUgc2FkNCA0dGFh
        IGVzcG5vZGUvdGlueXN5bnRoIFRpbnklMjBTeW50aCUyMFBsYXllcgpub2RlL3R1cm4tb24gNHRhYQpub2RlL2FkZC1pbmxldCA0dGFhIGJpdHQgZXNwbm9kZS9zdHJpbmcgdHJpZ2dlcl9pbnB1dCB0cmlnZ2VyX2lucHV0Cm5vZGUvYWRkLW91dGxldCA0dGFhIGhl
        c2YgZXNwbm9kZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IHIwc2cgZXNwbm9kZS9jbG9jayBDbG9jayUyMEdlbgpub2RlL3R1cm4tb24gcjBzZwpub2RlL2FkZC1pbmxldCByMHNnIGduazcgZXNwbm9kZS9zdHJpbmcgYnBtIGJwbQpub2RlL2Fk
        ZC1pbmxldCByMHNnIHl3ZWwgZXNwbm9kZS9zdHJpbmcgZGl2aXNpb24gZGl2aXNpb24Kbm9kZS9hZGQtb3V0bGV0IHIwc2cgYW56cyBlc3Bub2RlL3N0cmluZyBvdXQgb3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgem83NyBlc3Bub2RlL2RhYyBBdWRpbyUyMERBQwpu
        b2RlL3R1cm4tb24gem83Nwpub2RlL2FkZC1pbmxldCB6bzc3IDMyNjQgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCB2Nm50IGVzcG5vZGUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiB2
        Nm50Cm5vZGUvYWRkLWlubGV0IHY2bnQgcHZyZSBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IHY2bnQgeGYzNSBlc3Bub2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5v
        ZGUvYWRkLW91dGxldCB2Nm50IGtzZ24gZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDFieHEgZXNwbm9kZS9tdWx0aXBsZXhlciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gMWJ4cQpub2RlL2FkZC1vdXRsZXQgMWJ4cSBmaTIzIGVz
        cG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgMWJ4cSB5aDJoIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQgMWJ4cSA3cW14IGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgMWJ4cSBndWZr
        IGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgMWJ4cSBzN2ZvIGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRsZXQgMWJ4cSA1MHRmIGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgMWJ4cSB4
        NXVvIGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgMWJ4cSB6ZDA3IGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApub2RlL21vdmUgdTZ5ZSAzMCAyMApub2RlL21vdmUgNHRhYSA3MDUgOTUKbm9kZS9tb3ZlIHIwc2cgMzk0IDE2MApub2Rl
        L21vdmUgem83NyAxMjM1IDIwOApub2RlL21vdmUgdjZudCA5MTMgMjQ0Cm5vZGUvbW92ZSAxYnhxIDQwNiAyODgKb3V0bGV0L2Nvbm5lY3QgYW56cyBiaXR0IHA4bjYKb3V0bGV0L2Nvbm5lY3QgaGVzZiBwdnJlIDA0ZXQKb3V0bGV0L2Nvbm5lY3QgeWgyaCB4ZjM1
        IG5kYXAKb3V0bGV0L2Nvbm5lY3Qga3NnbiAzMjY0IDdqcmkKbm9kZS91cGRhdGUtaW5sZXQgNHRhYSBiaXR0IHRyaWdnZXJfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCByMHNnIGduazcgYnBtIDEKbm9kZS91cGRhdGUtaW5sZXQgcjBzZyB5d2VsIGRpdmlzaW9u
        IDIwCm5vZGUvdXBkYXRlLWlubGV0IHY2bnQgcHZyZSBmcmVxdWVuY3lfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCB2Nm50IHhmMzUgd2F2ZXRhYmxlX2lucHV0IDA=
        --ENDESPNODEPATCH--

        */



//        ModuleTinySynth *moduleTinySynth_1 = new ModuleTinySynth();
//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,20);


//        moduleTinySynth_1->trigger_input=moduleClock_1;
//        moduleWavetableOsc_1->frequency_input=moduleTinySynth_1;
//        moduleWavetableOsc_1->wavetable_input= &param[1];


//        this->last_module = moduleWavetableOsc_1;


        // end of espnode86 generated code //


//        ModuleTinySynth *moduleTinySynth_1 = new ModuleTinySynth();
//        ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *moduleWavetableOsc_2 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *moduleWavetableOsc_3 = new ModuleWavetableOsc();
//        ModuleWavetableOsc *moduleWavetableOsc_4 = new ModuleWavetableOsc();
//        ModuleMixer2 *moduleMixer2_1 = new ModuleMixer2();
//        ModuleMixer2 *moduleMixer2_2 = new ModuleMixer2();
//        ModuleMixer2 *moduleMixer2_3 = new ModuleMixer2();
//        ModuleClock *moduleClock_1 = new ModuleClock(3,1);


//        moduleTinySynth_1->trigger_input=moduleClock_1;
//        moduleWavetableOsc_1->frequency_input=moduleTinySynth_1->ch1;
//        moduleWavetableOsc_2->frequency_input=moduleTinySynth_1->ch2;
//        moduleWavetableOsc_3->frequency_input=moduleTinySynth_1->ch3;
//        moduleWavetableOsc_4->frequency_input=moduleTinySynth_1->ch4;
//        moduleMixer2_1->ch1=moduleWavetableOsc_1;
//        moduleMixer2_1->ch2=moduleWavetableOsc_2;
//        moduleMixer2_2->ch1=moduleWavetableOsc_3;
//        moduleMixer2_2->ch2=moduleWavetableOsc_4;
//        moduleMixer2_3->ch1=moduleMixer2_1;
//        moduleMixer2_3->ch2=moduleMixer2_2;


//        this->last_module = moduleMixer2_3;




//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,100);
//        ModuleTinySynth *moduleTinySynth_1 = new ModuleTinySynth("C(-1:C)Fe 2,dE | 4,F(-1:D) 2,eF 4,A(-1:G)g | 2,f(-1:F)eF(-1:E)G 4,f(-1:D)e(-1:C) | 2,d(-2:G)Edc 4,b(-2:G)G | c(-1:C)Fe 2,dE | 4,F(-1:D) 2,eF 4,A(-1:G)g | 2,A(-1:F)gA(-1:E)Cb(-1:G)gB(-1:B)D | 4,c(-1:C)g 8,C ^(^^)");


//        moduleTinySynth_1->trigger_input=moduleClock_1;
//        moduleLowpassFilter_1->cutoff_input= &param[1];
//        moduleLowpassFilter_1->resonance_input= &param[2];
//        moduleLowpassFilter_1->audio_input=moduleTinySynth_1;


//        this->last_module = moduleLowpassFilter_1;



        /*

        This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBhazkzIGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIGFrOTMKcGF0Y2gvYWRkLW5vZGUgc2FkNCA3a2dl
        IGVzcG5vZGUvY2xvY2tkaXZpZGVyIENsb2NrJTIwRGl2aWRlcgpub2RlL3R1cm4tb24gN2tnZQpub2RlL2FkZC1pbmxldCA3a2dlIGJtb2MgZXNwbm9kZS9zdHJpbmcgY2xvY2tfaW5wdXQgY2xvY2tfaW5wdXQKbm9kZS9hZGQtaW5sZXQgN2tnZSA5cDZsIGVzcG5v
        ZGUvc3RyaW5nIGRpdmlzaW9uX2lucHV0IGRpdmlzaW9uX2lucHV0Cm5vZGUvYWRkLW91dGxldCA3a2dlIHh2NjQgZXNwbm9kZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IDZ3c2EgZXNwbm9kZS9jbG9jayBDbG9jayUyMEdlbgpub2RlL3R1cm4t
        b24gNndzYQpub2RlL2FkZC1pbmxldCA2d3NhIDZ6b3ogZXNwbm9kZS9zdHJpbmcgYnBtIGJwbQpub2RlL2FkZC1pbmxldCA2d3NhIGRmeGogZXNwbm9kZS9zdHJpbmcgZGl2aXNpb24gZGl2aXNpb24Kbm9kZS9hZGQtb3V0bGV0IDZ3c2EgczhuZyBlc3Bub2RlL3N0
        cmluZyBvdXQgb3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgMXlnYSBlc3Bub2RlL2RhYyBBdWRpbyUyMERBQwpub2RlL3R1cm4tb24gMXlnYQpub2RlL2FkZC1pbmxldCAxeWdhIDNpa2sgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKcGF0Y2gv
        YWRkLW5vZGUgc2FkNCBiNDIxIGVzcG5vZGUvbXVsdGlwbGV4ZXIgTXVsdGlwbGV4ZXIKbm9kZS90dXJuLW9uIGI0MjEKbm9kZS9hZGQtb3V0bGV0IGI0MjEgcHNzdCBlc3Bub2RlL3N0cmluZyBQb3QxIFBvdDEKbm9kZS9hZGQtb3V0bGV0IGI0MjEgdWZ4biBlc3Bu
        b2RlL3N0cmluZyBQb3QyIFBvdDIKbm9kZS9hZGQtb3V0bGV0IGI0MjEgcnZoOSBlc3Bub2RlL3N0cmluZyBQb3QzIFBvdDMKbm9kZS9hZGQtb3V0bGV0IGI0MjEgOGQzNCBlc3Bub2RlL3N0cmluZyBQb3Q0IFBvdDQKbm9kZS9hZGQtb3V0bGV0IGI0MjEgbmc0dyBl
        c3Bub2RlL3N0cmluZyBQb3Q1IFBvdDUKbm9kZS9hZGQtb3V0bGV0IGI0MjEgMjYwbiBlc3Bub2RlL3N0cmluZyBQb3Q2IFBvdDYKbm9kZS9hZGQtb3V0bGV0IGI0MjEgdWtwdiBlc3Bub2RlL3N0cmluZyBQb3Q3IFBvdDcKbm9kZS9hZGQtb3V0bGV0IGI0MjEgaThw
        NCBlc3Bub2RlL3N0cmluZyBQb3Q4IFBvdDgKcGF0Y2gvYWRkLW5vZGUgc2FkNCAweTAzIGVzcG5vZGUvZGVsYXkgQXVkaW8lMjBEZWxheQpub2RlL3R1cm4tb24gMHkwMwpub2RlL2FkZC1pbmxldCAweTAzIHJjYWogZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQg
        YXVkaW9faW5wdXQKbm9kZS9hZGQtaW5sZXQgMHkwMyBscndoIGVzcG5vZGUvc3RyaW5nIG1peF9pbnB1dCBtaXhfaW5wdXQKbm9kZS9hZGQtaW5sZXQgMHkwMyByd2hnIGVzcG5vZGUvc3RyaW5nIGZlZWRiYWNrX2lucHV0IGZlZWRiYWNrX2lucHV0Cm5vZGUvYWRk
        LWlubGV0IDB5MDMgcTJibSBlc3Bub2RlL3N0cmluZyBsZW5ndGhfaW5wdXQgbGVuZ3RoX2lucHV0Cm5vZGUvYWRkLW91dGxldCAweTAzIDQzcnQgZXNwbm9kZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IHdjNDcgZXNwbm9kZS90aW55c3ludGgg
        VGlueSUyMFN5bnRoJTIwUGxheWVyCm5vZGUvdHVybi1vbiB3YzQ3Cm5vZGUvYWRkLWlubGV0IHdjNDcgZWJwZCBlc3Bub2RlL3N0cmluZyB0cmlnZ2VyX2lucHV0IHRyaWdnZXJfaW5wdXQKbm9kZS9hZGQtaW5sZXQgd2M0NyBzemtkIGVzcG5vZGUvc3RyaW5nIGFt
        cGxlIGFtcGxlCm5vZGUvYWRkLW91dGxldCB3YzQ3IHdtNjcgZXNwbm9kZS9zdHJpbmcgb3V0IG91dApub2RlL21vdmUgYWs5MyAzMCAyMApub2RlL21vdmUgN2tnZSA1OTggMTUyCm5vZGUvbW92ZSA2d3NhIDMxNyA1NApub2RlL21vdmUgMXlnYSAxNjc3IDI3Nwpu
        b2RlL21vdmUgYjQyMSAzNzAgMjUwCm5vZGUvbW92ZSAweTAzIDE0NDEgMjY2Cm5vZGUvbW92ZSB3YzQ3IDgzNCA1MgpvdXRsZXQvY29ubmVjdCBzOG5nIGJtb2Mgbno1OQpvdXRsZXQvY29ubmVjdCB1ZnhuIDlwNmwgNWo2MgpvdXRsZXQvY29ubmVjdCA0M3J0IDNp
        a2sgMHdxNApvdXRsZXQvY29ubmVjdCBydmg5IGxyd2ggYTltcgpvdXRsZXQvY29ubmVjdCA4ZDM0IHJ3aGcgN2hlMApvdXRsZXQvY29ubmVjdCBuZzR3IHEyYm0gbWJ4dApvdXRsZXQvY29ubmVjdCB4djY0IGVicGQgZ3NxegpvdXRsZXQvY29ubmVjdCB3bTY3IHJj
        YWogY2QycApub2RlL3VwZGF0ZS1pbmxldCA3a2dlIGJtb2MgY2xvY2tfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCA3a2dlIDlwNmwgZGl2aXNpb25faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCA2d3NhIDZ6b3ogYnBtIDEwMApub2RlL3VwZGF0ZS1pbmxldCA2
        d3NhIGRmeGogZGl2aXNpb24gMTAKbm9kZS91cGRhdGUtaW5sZXQgMHkwMyBscndoIG1peF9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IDB5MDMgcndoZyBmZWVkYmFja19pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IDB5MDMgcTJibSBsZW5ndGhfaW5wdXQgMApu
        b2RlL3VwZGF0ZS1pbmxldCB3YzQ3IGVicGQgdHJpZ2dlcl9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IHdjNDcgc3prZCBhbXBsZSBDKC0xOkMpRmUgMixkRSB8IDQsRigtMTpEKSAyLGVGIDQsQSgtMTpHKWcgfCAyLGYoLTE6RillRigtMTpFKUcgNCxmKC0xOkQp
        ZSgtMTpDKSB8IDIsZCgtMjpHKUVkYyA0LGIoLTI6RylHIHwgYygtMTpDKUZlIDIsZEUgfCA0LEYoLTE6RCkgMixlRiA0LEEoLTE6RylnIHwgMixBKC0xOkYpZ0EoLTE6RSlDYigtMTpHKWdCKC0xOkIpRCB8IDQsYygtMTpDKWcgOCxDIF4oXl4p
        --ENDESPNODEPATCH--

        */





//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,10);


//        moduleSamplePlayer_1->trigger_input=moduleClock_1;


//        this->last_module = moduleSamplePlayer_1;


        // end of espnode86 generated code //

        /*

        This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBzbjl0IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIHNuOXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA5cjM4
        IGVzcG5vZGUvc2FtcGxlcGFja3BsYXkgU2FtcGxlJTIwUGFjayUyMFBsYXllcgpub2RlL3R1cm4tb24gOXIzOApub2RlL2FkZC1pbmxldCA5cjM4IDQ2aHYgZXNwbm9kZS9zdHJpbmcgc2FtcGxlIHNhbXBsZQpub2RlL2FkZC1pbmxldCA5cjM4IHB1M2UgZXNwbm9k
        ZS9zdHJpbmcgdHJpZ2dlcl9pbnB1dCB0cmlnZ2VyX2lucHV0Cm5vZGUvYWRkLWlubGV0IDlyMzggbm1xaCBlc3Bub2RlL3N0cmluZyBzYW1wbGVfc2VsZWN0IHNhbXBsZV9zZWxlY3QKbm9kZS9hZGQtb3V0bGV0IDlyMzggNmhuMyBlc3Bub2RlL3N0cmluZyBvdXQg
        b3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgeG93NiBlc3Bub2RlL2Nsb2NrIENsb2NrJTIwR2VuCm5vZGUvdHVybi1vbiB4b3c2Cm5vZGUvYWRkLWlubGV0IHhvdzYgd3h3ZyBlc3Bub2RlL3N0cmluZyBicG0gYnBtCm5vZGUvYWRkLWlubGV0IHhvdzYgcmU0OCBlc3Bu
        b2RlL3N0cmluZyBkaXZpc2lvbiBkaXZpc2lvbgpub2RlL2FkZC1vdXRsZXQgeG93NiB2NGx6IGVzcG5vZGUvc3RyaW5nIG91dCBvdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA2OHAxIGVzcG5vZGUvY2xvY2tkaXZpZGVyIENsb2NrJTIwRGl2aWRlcgpub2RlL3R1cm4t
        b24gNjhwMQpub2RlL2FkZC1pbmxldCA2OHAxIG55bG0gZXNwbm9kZS9zdHJpbmcgY2xvY2tfaW5wdXQgY2xvY2tfaW5wdXQKbm9kZS9hZGQtaW5sZXQgNjhwMSA4MXM3IGVzcG5vZGUvc3RyaW5nIGRpdmlzaW9uX2lucHV0IGRpdmlzaW9uX2lucHV0Cm5vZGUvYWRk
        LW91dGxldCA2OHAxIDdicGogZXNwbm9kZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGh1emsgZXNwbm9kZS9tdWx0aXBsZXhlciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gaHV6awpub2RlL2FkZC1vdXRsZXQgaHV6ayB5ZWFwIGVzcG5vZGUv
        c3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgaHV6ayBiODdpIGVzcG5vZGUvc3RyaW5nIFBvdDIgUG90Mgpub2RlL2FkZC1vdXRsZXQgaHV6ayA2OWFsIGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgaHV6ayBtcXMwIGVzcG5v
        ZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgaHV6ayBjcjJ1IGVzcG5vZGUvc3RyaW5nIFBvdDUgUG90NQpub2RlL2FkZC1vdXRsZXQgaHV6ayBkenczIGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgaHV6ayB0c3MyIGVz
        cG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgaHV6ayAydm1iIGVzcG5vZGUvc3RyaW5nIFBvdDggUG90OApwYXRjaC9hZGQtbm9kZSBzYWQ0IGVtcDkgZXNwbm9kZS9kYWMgQXVkaW8lMjBEQUMKbm9kZS90dXJuLW9uIGVtcDkKbm9kZS9hZGQt
        aW5sZXQgZW1wOSBhYXZzIGVzcG5vZGUvc3RyaW5nIGF1ZGlvX2lucHV0IGF1ZGlvX2lucHV0Cm5vZGUvbW92ZSBzbjl0IDMwIDIwCm5vZGUvbW92ZSA5cjM4IDk3NyAyOTEKbm9kZS9tb3ZlIHhvdzYgMzg5IDIxMQpub2RlL21vdmUgNjhwMSA3MTcgMjYyCm5vZGUv
        bW92ZSBodXprIDQwNCAzMjkKbm9kZS9tb3ZlIGVtcDkgMTMwMCAyOTEKb3V0bGV0L2Nvbm5lY3QgdjRseiBueWxtIHJ4cXMKb3V0bGV0L2Nvbm5lY3QgN2JwaiBwdTNlIDEzMngKb3V0bGV0L2Nvbm5lY3QgeWVhcCA4MXM3IHVtZDkKb3V0bGV0L2Nvbm5lY3QgYjg3
        aSBubXFoIHZocjkKb3V0bGV0L2Nvbm5lY3QgNmhuMyBhYXZzIGdzNXUKbm9kZS91cGRhdGUtaW5sZXQgOXIzOCA0Nmh2IHNhbXBsZSBLZW5kYW5nCm5vZGUvdXBkYXRlLWlubGV0IDlyMzggcHUzZSB0cmlnZ2VyX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgOXIz
        OCBubXFoIHNhbXBsZV9zZWxlY3QgMApub2RlL3VwZGF0ZS1pbmxldCB4b3c2IHd4d2cgYnBtIDEKbm9kZS91cGRhdGUtaW5sZXQgeG93NiByZTQ4IGRpdmlzaW9uIDEwMApub2RlL3VwZGF0ZS1pbmxldCA2OHAxIG55bG0gY2xvY2tfaW5wdXQgMApub2RlL3VwZGF0
        ZS1pbmxldCA2OHAxIDgxczcgZGl2aXNpb25faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBlbXA5IGFhdnMgYXVkaW9faW5wdXQgMA==
        --ENDESPNODEPATCH--

        */



//        ModuleClockDivider *moduleClockDivider_1 = new ModuleClockDivider();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,100);
//        ModuleSamplePackKendang *moduleSamplePack_Kendang = new ModuleSamplePackKendang();
//        moduleSamplePack_Kendang->trigger_input=moduleClockDivider_1;
//        moduleSamplePack_Kendang->sample_select = &param[2];


//        moduleClockDivider_1->clock_input=moduleClock_1;
//        moduleClockDivider_1->division_input= &param[1];


//        this->last_module = moduleSamplePack_Kendang;

        /*

        This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBxZ2x3IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIHFnbHcKcGF0Y2gvYWRkLW5vZGUgc2FkNCBmd2Rx
        IGVzcG5vZGUvZGFjIEF1ZGlvJTIwREFDCm5vZGUvdHVybi1vbiBmd2RxCm5vZGUvYWRkLWlubGV0IGZ3ZHEgdzB6ZSBlc3Bub2RlL3N0cmluZyBhdWRpb19pbnB1dCBhdWRpb19pbnB1dApwYXRjaC9hZGQtbm9kZSBzYWQ0IHZpaW8gZXNwbm9kZS9zYW1wbGVwYWNr
        IFNhbXBsZSUyMFBhY2slMjBFZGl0b3IKbm9kZS90dXJuLW9uIHZpaW8Kbm9kZS9hZGQtaW5sZXQgdmlpbyBwbjllIGVzcG5vZGUvc3RyaW5nIGNvbW1lbnQgY29tbWVudApub2RlL2FkZC1pbmxldCB2aWlvIG10ODggZXNwbm9kZS9zdHJpbmcgc2FtcGxlX25hbWUg
        c2FtcGxlX25hbWUKcGF0Y2gvYWRkLW5vZGUgc2FkNCA4ZXVlIGVzcG5vZGUvY2xvY2sgQ2xvY2slMjBHZW4Kbm9kZS90dXJuLW9uIDhldWUKbm9kZS9hZGQtaW5sZXQgOGV1ZSBlYTlvIGVzcG5vZGUvc3RyaW5nIGJwbSBicG0Kbm9kZS9hZGQtaW5sZXQgOGV1ZSA1
        MWR2IGVzcG5vZGUvc3RyaW5nIGRpdmlzaW9uIGRpdmlzaW9uCm5vZGUvYWRkLW91dGxldCA4ZXVlIG9lcjQgZXNwbm9kZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IHNpdjkgZXNwbm9kZS9jbG9ja2RpdmlkZXIgQ2xvY2slMjBEaXZpZGVyCm5v
        ZGUvdHVybi1vbiBzaXY5Cm5vZGUvYWRkLWlubGV0IHNpdjkgcm1vaCBlc3Bub2RlL3N0cmluZyBjbG9ja19pbnB1dCBjbG9ja19pbnB1dApub2RlL2FkZC1pbmxldCBzaXY5IDRpbDAgZXNwbm9kZS9zdHJpbmcgZGl2aXNpb25faW5wdXQgZGl2aXNpb25faW5wdXQK
        bm9kZS9hZGQtb3V0bGV0IHNpdjkgYmx0dSBlc3Bub2RlL3N0cmluZyBvdXQgb3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgbGM0cCBlc3Bub2RlL211bHRpcGxleGVyIE11bHRpcGxleGVyCm5vZGUvdHVybi1vbiBsYzRwCm5vZGUvYWRkLW91dGxldCBsYzRwIGwyMGIg
        ZXNwbm9kZS9zdHJpbmcgUG90MSBQb3QxCm5vZGUvYWRkLW91dGxldCBsYzRwIDdreTMgZXNwbm9kZS9zdHJpbmcgUG90MiBQb3QyCm5vZGUvYWRkLW91dGxldCBsYzRwIGh2YWggZXNwbm9kZS9zdHJpbmcgUG90MyBQb3QzCm5vZGUvYWRkLW91dGxldCBsYzRwIGxp
        eW4gZXNwbm9kZS9zdHJpbmcgUG90NCBQb3Q0Cm5vZGUvYWRkLW91dGxldCBsYzRwIHhjdTggZXNwbm9kZS9zdHJpbmcgUG90NSBQb3Q1Cm5vZGUvYWRkLW91dGxldCBsYzRwIGk1bTkgZXNwbm9kZS9zdHJpbmcgUG90NiBQb3Q2Cm5vZGUvYWRkLW91dGxldCBsYzRw
        IHE0bDkgZXNwbm9kZS9zdHJpbmcgUG90NyBQb3Q3Cm5vZGUvYWRkLW91dGxldCBsYzRwIGI5NHIgZXNwbm9kZS9zdHJpbmcgUG90OCBQb3Q4Cm5vZGUvbW92ZSBxZ2x3IDMwIDIwCm5vZGUvbW92ZSBmd2RxIDExNTcgMTk0Cm5vZGUvbW92ZSB2aWlvIDUxMiA0NzYK
        bm9kZS9tb3ZlIDhldWUgMjcxIDY0Cm5vZGUvbW92ZSBzaXY5IDU2OSAxNTAKbm9kZS9tb3ZlIGxjNHAgMzMzIDI0NwpvdXRsZXQvY29ubmVjdCBvZXI0IHJtb2ggNDhodwpvdXRsZXQvY29ubmVjdCBsMjBiIDRpbDAgaHloeQpvdXRsZXQvY29ubmVjdCBibHR1IHcw
        emUga2JvdApub2RlL3VwZGF0ZS1pbmxldCBmd2RxIHcwemUgYXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCB2aWlvIG10ODggc2FtcGxlX25hbWUgU2FtcGxlMQpub2RlL3VwZGF0ZS1pbmxldCA4ZXVlIGVhOW8gYnBtIDEKbm9kZS91cGRhdGUtaW5sZXQg
        OGV1ZSA1MWR2IGRpdmlzaW9uIDEwMApub2RlL3VwZGF0ZS1pbmxldCBzaXY5IHJtb2ggY2xvY2tfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBzaXY5IDRpbDAgZGl2aXNpb25faW5wdXQgMA==
        --ENDESPNODEPATCH--

        */





//        ModuleClockDivider *moduleClockDivider_1 = new ModuleClockDivider();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,100);
//        ModuleSamplePackSample1 *moduleSamplePack_Sample1 = new ModuleSamplePackSample1();
//        moduleSamplePack_Sample1->trigger_input=moduleClockDivider_1;
//        moduleSamplePack_Sample1->sample_select = &param[1];


//        moduleClockDivider_1->clock_input=moduleClock_1;
//        moduleClockDivider_1->division_input= &param[0];


//        this->last_module = moduleSamplePack_Sample1;



//        ModuleClockDivider *moduleClockDivider_3 = new ModuleClockDivider();
//        ModuleDelay *moduleDelay_1 = new ModuleDelay();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,100);
//        ModuleTinySynth *moduleTinySynth_1 = new ModuleTinySynth("C(-1:C)Fe 2,dE | 4,F(-1:D) 2,eF 4,A(-1:G)g | 2,f(-1:F)eF(-1:E)G 4,f(-1:D)e(-1:C) | 2,d(-2:G)Edc 4,b(-2:G)G | c(-1:C)Fe 2,dE | 4,F(-1:D) 2,eF 4,A(-1:G)g | 2,A(-1:F)gA(-1:E)Cb(-1:G)gB(-1:B)D | 4,c(-1:C)g 8,C ^(^^)");


//        moduleClockDivider_3->clock_input=moduleClock_1;
//        moduleClockDivider_3->division_input= &param[0];
//        moduleTinySynth_1->trigger_input=moduleClockDivider_3;
//        moduleDelay_1->audio_input=moduleTinySynth_1;
//        moduleDelay_1->mix_input= &param[1];
//        moduleDelay_1->feedback_input= &param[2];
//        moduleDelay_1->length_input= &param[2];


//        this->last_module = moduleDelay_1;


        /*

        This is espnode86 stuff do not edit

        --BEGINESPNODEPATCH--
        djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA0YWk4IGVzcG5vZGUvbm9kZWxpc3QgTm9kZSUyMFBhbGxldGUKbm9kZS90dXJuLW9uIDRhaTgKcGF0Y2gvYWRkLW5vZGUgc2FkNCB2Y214
        IGVzcG5vZGUvc2FtcGxlcGxheWVyIFNhbXBsZSUyMFBsYXllcgpub2RlL3R1cm4tb24gdmNteApub2RlL2FkZC1pbmxldCB2Y214IGVjbG0gZXNwbm9kZS9zdHJpbmcgdHJpZ2dlcl9pbnB1dCB0cmlnZ2VyX2lucHV0Cm5vZGUvYWRkLWlubGV0IHZjbXggaG1pMiBl
        c3Bub2RlL3N0cmluZyBzYW1wbGVfc2VsZWN0IHNhbXBsZV9zZWxlY3QKbm9kZS9hZGQtb3V0bGV0IHZjbXggend3diBlc3Bub2RlL3N0cmluZyBvdXQgb3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgbmM4ciBlc3Bub2RlL2Nsb2NrIENsb2NrJTIwR2VuCm5vZGUvdHVy
        bi1vbiBuYzhyCm5vZGUvYWRkLWlubGV0IG5jOHIgdjRmaCBlc3Bub2RlL3N0cmluZyBicG0gYnBtCm5vZGUvYWRkLWlubGV0IG5jOHIgd2tqMiBlc3Bub2RlL3N0cmluZyBkaXZpc2lvbiBkaXZpc2lvbgpub2RlL2FkZC1vdXRsZXQgbmM4ciA2YjB2IGVzcG5vZGUv
        c3RyaW5nIG91dCBvdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBzNnh0IGVzcG5vZGUvY2xvY2tkaXZpZGVyIENsb2NrJTIwRGl2aWRlcgpub2RlL3R1cm4tb24gczZ4dApub2RlL2FkZC1pbmxldCBzNnh0IDlyemogZXNwbm9kZS9zdHJpbmcgY2xvY2tfaW5wdXQgY2xv
        Y2tfaW5wdXQKbm9kZS9hZGQtaW5sZXQgczZ4dCAyYnVxIGVzcG5vZGUvc3RyaW5nIGRpdmlzaW9uX2lucHV0IGRpdmlzaW9uX2lucHV0Cm5vZGUvYWRkLW91dGxldCBzNnh0IDhtZjcgZXNwbm9kZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGlz
        ZmEgZXNwbm9kZS9tdWx0aXBsZXhlciBNdWx0aXBsZXhlcgpub2RlL3R1cm4tb24gaXNmYQpub2RlL2FkZC1vdXRsZXQgaXNmYSBlZWJmIGVzcG5vZGUvc3RyaW5nIFBvdDEgUG90MQpub2RlL2FkZC1vdXRsZXQgaXNmYSB1dDdyIGVzcG5vZGUvc3RyaW5nIFBvdDIg
        UG90Mgpub2RlL2FkZC1vdXRsZXQgaXNmYSBybnlrIGVzcG5vZGUvc3RyaW5nIFBvdDMgUG90Mwpub2RlL2FkZC1vdXRsZXQgaXNmYSBlcWxhIGVzcG5vZGUvc3RyaW5nIFBvdDQgUG90NApub2RlL2FkZC1vdXRsZXQgaXNmYSA0N2E0IGVzcG5vZGUvc3RyaW5nIFBv
        dDUgUG90NQpub2RlL2FkZC1vdXRsZXQgaXNmYSBhdXh6IGVzcG5vZGUvc3RyaW5nIFBvdDYgUG90Ngpub2RlL2FkZC1vdXRsZXQgaXNmYSB2Nzl4IGVzcG5vZGUvc3RyaW5nIFBvdDcgUG90Nwpub2RlL2FkZC1vdXRsZXQgaXNmYSB5dnFzIGVzcG5vZGUvc3RyaW5n
        IFBvdDggUG90OApwYXRjaC9hZGQtbm9kZSBzYWQ0IHkzZGIgZXNwbm9kZS9jbG9ja2RpdmlkZXIgQ2xvY2slMjBEaXZpZGVyCm5vZGUvdHVybi1vbiB5M2RiCm5vZGUvYWRkLWlubGV0IHkzZGIgdTU0dyBlc3Bub2RlL3N0cmluZyBjbG9ja19pbnB1dCBjbG9ja19p
        bnB1dApub2RlL2FkZC1pbmxldCB5M2RiIDIyYWogZXNwbm9kZS9zdHJpbmcgZGl2aXNpb25faW5wdXQgZGl2aXNpb25faW5wdXQKbm9kZS9hZGQtb3V0bGV0IHkzZGIgZ3liNyBlc3Bub2RlL3N0cmluZyBvdXQgb3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgcmwyaCBl
        c3Bub2RlL2Nsb2NrZGl2aWRlciBDbG9jayUyMERpdmlkZXIKbm9kZS90dXJuLW9uIHJsMmgKbm9kZS9hZGQtaW5sZXQgcmwyaCBjem8yIGVzcG5vZGUvc3RyaW5nIGNsb2NrX2lucHV0IGNsb2NrX2lucHV0Cm5vZGUvYWRkLWlubGV0IHJsMmggYThqdCBlc3Bub2Rl
        L3N0cmluZyBkaXZpc2lvbl9pbnB1dCBkaXZpc2lvbl9pbnB1dApub2RlL2FkZC1vdXRsZXQgcmwyaCA1eXc3IGVzcG5vZGUvc3RyaW5nIG91dCBvdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBjZ2ptIGVzcG5vZGUvc2FtcGxlcGxheWVyIFNhbXBsZSUyMFBsYXllcgpu
        b2RlL3R1cm4tb24gY2dqbQpub2RlL2FkZC1pbmxldCBjZ2ptIGFyYWIgZXNwbm9kZS9zdHJpbmcgdHJpZ2dlcl9pbnB1dCB0cmlnZ2VyX2lucHV0Cm5vZGUvYWRkLWlubGV0IGNnam0gajQ0MSBlc3Bub2RlL3N0cmluZyBzYW1wbGVfc2VsZWN0IHNhbXBsZV9zZWxl
        Y3QKbm9kZS9hZGQtb3V0bGV0IGNnam0gcmRoNyBlc3Bub2RlL3N0cmluZyBvdXQgb3V0CnBhdGNoL2FkZC1ub2RlIHNhZDQgcnBpayBlc3Bub2RlL3NhbXBsZXBsYXllciBTYW1wbGUlMjBQbGF5ZXIKbm9kZS90dXJuLW9uIHJwaWsKbm9kZS9hZGQtaW5sZXQgcnBp
        ayA3bnd5IGVzcG5vZGUvc3RyaW5nIHRyaWdnZXJfaW5wdXQgdHJpZ2dlcl9pbnB1dApub2RlL2FkZC1pbmxldCBycGlrIDBtNGUgZXNwbm9kZS9zdHJpbmcgc2FtcGxlX3NlbGVjdCBzYW1wbGVfc2VsZWN0Cm5vZGUvYWRkLW91dGxldCBycGlrIHh1MTEgZXNwbm9k
        ZS9zdHJpbmcgb3V0IG91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IGE0dHAgZXNwbm9kZS9taXhlcjMgMyUyMENoJTIwTWl4ZXIKbm9kZS90dXJuLW9uIGE0dHAKbm9kZS9hZGQtaW5sZXQgYTR0cCAzeHByIGVzcG5vZGUvc3RyaW5nIGNoMSBjaDEKbm9kZS9hZGQtaW5s
        ZXQgYTR0cCBwYmdoIGVzcG5vZGUvc3RyaW5nIGNoMiBjaDIKbm9kZS9hZGQtaW5sZXQgYTR0cCBqY2E5IGVzcG5vZGUvc3RyaW5nIGNoMyBjaDMKbm9kZS9hZGQtb3V0bGV0IGE0dHAgZ2prdCBlc3Bub2RlL3N0cmluZyBPdXQgT3V0CnBhdGNoL2FkZC1ub2RlIHNh
        ZDQgYTBjbCBlc3Bub2RlL2RhYyBBdWRpbyUyMERBQwpub2RlL3R1cm4tb24gYTBjbApub2RlL2FkZC1pbmxldCBhMGNsIGVhamYgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCA4Y2IwIGVzcG5vZGUvY29u
        c3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIDhjYjAKbm9kZS9hZGQtaW5sZXQgOGNiMCAxNm43IGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUgdXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgOGNiMCA3cHFxIGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIK
        cGF0Y2gvYWRkLW5vZGUgc2FkNCB4N2x6IGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIHg3bHoKbm9kZS9hZGQtaW5sZXQgeDdseiAyb3U2IGVzcG5vZGUvc3RyaW5nIHVzZXItdmFsdWUgdXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgeDds
        eiBpbTBkIGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKcGF0Y2gvYWRkLW5vZGUgc2FkNCA3MmdsIGVzcG5vZGUvY29uc3RhbnQgQ29uc3RhbnQKbm9kZS90dXJuLW9uIDcyZ2wKbm9kZS9hZGQtaW5sZXQgNzJnbCBxYnRnIGVzcG5vZGUvc3RyaW5nIHVzZXIt
        dmFsdWUgdXNlci12YWx1ZQpub2RlL2FkZC1vdXRsZXQgNzJnbCA0OG0yIGVzcG5vZGUvc3RyaW5nIG51bWJlciBudW1iZXIKbm9kZS9tb3ZlIDRhaTggMzAgMjAKbm9kZS9tb3ZlIHZjbXggODg5IDE2NApub2RlL21vdmUgbmM4ciAzMTMgMTAzCm5vZGUvbW92ZSBz
        Nnh0IDYyNCAxNTMKbm9kZS9tb3ZlIGlzZmEgNDA2IDIxOApub2RlL21vdmUgeTNkYiA2MzcgMjYyCm5vZGUvbW92ZSBybDJoIDYzMCAzNjEKbm9kZS9tb3ZlIGNnam0gODk5IDI4MApub2RlL21vdmUgcnBpayA4OTYgMzgzCm5vZGUvbW92ZSBhNHRwIDExMjkgMjIy
        Cm5vZGUvbW92ZSBhMGNsIDEzMDAgMjM5Cm5vZGUvbW92ZSA4Y2IwIDc0MiA1MDkKbm9kZS9tb3ZlIHg3bHogNzQ4IDYxMwpub2RlL21vdmUgNzJnbCA1NzUgNDk5Cm91dGxldC9jb25uZWN0IDZiMHYgOXJ6aiBtMDYxCm91dGxldC9jb25uZWN0IDhtZjcgZWNsbSBz
        ZmlsCm91dGxldC9jb25uZWN0IGVlYmYgMmJ1cSBvYnRvCm91dGxldC9jb25uZWN0IDZiMHYgdTU0dyB5eDZzCm91dGxldC9jb25uZWN0IHV0N3IgMjJhaiBzZWIxCm91dGxldC9jb25uZWN0IHJueWsgYThqdCA3eHFzCm91dGxldC9jb25uZWN0IDZiMHYgY3pvMiB0
        emhkCm91dGxldC9jb25uZWN0IGd5YjcgYXJhYiA1Nmc3Cm91dGxldC9jb25uZWN0IDV5dzcgN253eSBmbTUzCm91dGxldC9jb25uZWN0IHp3d3YgM3hwciBweHR5Cm91dGxldC9jb25uZWN0IHJkaDcgcGJnaCA2MzlrCm91dGxldC9jb25uZWN0IHh1MTEgamNhOSB2
        cDk4Cm91dGxldC9jb25uZWN0IGdqa3QgZWFqZiBob3NoCm91dGxldC9jb25uZWN0IDQ4bTIgaG1pMiB4aGkxCm91dGxldC9jb25uZWN0IDdwcXEgajQ0MSAxdWdsCm91dGxldC9jb25uZWN0IGltMGQgMG00ZSBrZjc4Cm5vZGUvdXBkYXRlLWlubGV0IHZjbXggZWNs
        bSB0cmlnZ2VyX2lucHV0IDAKbm9kZS91cGRhdGUtaW5sZXQgdmNteCBobWkyIHNhbXBsZV9zZWxlY3QgMQpub2RlL3VwZGF0ZS1pbmxldCBuYzhyIHY0ZmggYnBtIDEKbm9kZS91cGRhdGUtaW5sZXQgbmM4ciB3a2oyIGRpdmlzaW9uIDEwMApub2RlL3VwZGF0ZS1p
        bmxldCBzNnh0IDlyemogY2xvY2tfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBzNnh0IDJidXEgZGl2aXNpb25faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCB5M2RiIHU1NHcgY2xvY2tfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCB5M2RiIDIyYWogZGl2aXNp
        b25faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBybDJoIGE4anQgZGl2aXNpb25faW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBjZ2ptIGFyYWIgdHJpZ2dlcl9pbnB1dCAwCm5vZGUvdXBkYXRlLWlubGV0IGNnam0gajQ0MSBzYW1wbGVfc2VsZWN0IDIKbm9kZS91
        cGRhdGUtaW5sZXQgcnBpayA3bnd5IHRyaWdnZXJfaW5wdXQgMApub2RlL3VwZGF0ZS1pbmxldCBycGlrIDBtNGUgc2FtcGxlX3NlbGVjdCAzCm5vZGUvdXBkYXRlLWlubGV0IGEwY2wgZWFqZiBhdWRpb19pbnB1dCAwCm5vZGUvdXBkYXRlLW91dGxldCA4Y2IwIDdw
        cXEgbnVtYmVyIDIKbm9kZS91cGRhdGUtaW5sZXQgOGNiMCAxNm43IHVzZXItdmFsdWUgMgpub2RlL3VwZGF0ZS1vdXRsZXQgeDdseiBpbTBkIG51bWJlciAzCm5vZGUvdXBkYXRlLWlubGV0IHg3bHogMm91NiB1c2VyLXZhbHVlIDMKbm9kZS91cGRhdGUtb3V0bGV0
        IDcyZ2wgNDhtMiBudW1iZXIgMQpub2RlL3VwZGF0ZS1pbmxldCA3MmdsIHFidGcgdXNlci12YWx1ZSAx
        --ENDESPNODEPATCH--

        */



//        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
//        ModuleClockDivider *moduleClockDivider_1 = new ModuleClockDivider();
//        ModuleClockDivider *moduleClockDivider_2 = new ModuleClockDivider();
//        ModuleClockDivider *moduleClockDivider_3 = new ModuleClockDivider();
//        ModuleSamplePlayer *moduleSamplePlayer_2 = new ModuleSamplePlayer();
//        ModuleSamplePlayer *moduleSamplePlayer_3 = new ModuleSamplePlayer();
//        ModuleMixer3 *moduleMixer3_1 = new ModuleMixer3();
//        ModuleBitReducer *moduleBitReducer_1 = new ModuleBitReducer();
//        ModuleClock *moduleClock_1 = new ModuleClock(1,50);


//        moduleSamplePlayer_1->sample_select = new ModuleConstant(64);
//        moduleSamplePlayer_2->sample_select = new ModuleConstant(128);
//        moduleSamplePlayer_3->sample_select = new ModuleConstant(256);
//        moduleClockDivider_1->clock_input=moduleClock_1;
//        moduleSamplePlayer_1->trigger_input=moduleClockDivider_1;
//        moduleClockDivider_1->division_input= &param[0];
//        moduleClockDivider_2->clock_input=moduleClock_1;
//        moduleClockDivider_2->division_input= &param[1];
//        moduleClockDivider_3->division_input= &param[2];
//        moduleClockDivider_3->clock_input=moduleClock_1;
//        moduleSamplePlayer_2->trigger_input=moduleClockDivider_2;
//        moduleSamplePlayer_3->trigger_input=moduleClockDivider_3;
//        moduleMixer3_1->ch1=moduleSamplePlayer_1;
//        moduleMixer3_1->ch2=moduleSamplePlayer_2;
//        moduleMixer3_1->ch3=moduleSamplePlayer_3;
//        moduleBitReducer_1->audio_input=moduleMixer3_1;
//        moduleBitReducer_1->bit_input= &param[3];


//        this->last_module = moduleBitReducer_1;



//        ModuleClockDivider *moduleClockDivider_1 = new ModuleClockDivider();
//        ModuleBitReducer *moduleBitReducer_1 = new ModuleBitReducer();
//        ModuleTinySynth *moduleTinySynth_1 = new ModuleTinySynth("C(-1:C)Fe 2,dE | 4,F(-1:D) 2,eF 4,A(-1:G)g | 2,f(-1:F)eF(-1:E)G 4,f(-1:D)e(-1:C) | 2,d(-2:G)Edc 4,b(-2:G)G | c(-1:C)Fe 2,dE | 4,F(-1:D) 2,eF 4,A(-1:G)g | 2,A(-1:F)gA(-1:E)Cb(-1:G)gB(-1:B)D | 4,c(-1:C)g 8,C ^(^^)");
//        ModuleClock *moduleClock_1 = new ModuleClock(1,50);


//        moduleTinySynth_1->trigger_input=moduleClockDivider_1;
//        moduleClockDivider_1->clock_input=moduleClock_1;
//        moduleClockDivider_1->division_input= &param[0];
//        moduleBitReducer_1->audio_input=moduleTinySynth_1;
//        moduleBitReducer_1->bit_input= &param[1];


//        this->last_module = moduleBitReducer_1;




//        ModuleClockDivider *moduleClockDivider_1 = new ModuleClockDivider();
//        ModuleDelay *moduleDelay_1 = new ModuleDelay();
//        ModuleBitReducer *moduleBitReducer_1 = new ModuleBitReducer();
//        ModuleLowpassFilter *moduleLowpassFilter_1 = new ModuleLowpassFilter();
//        ModuleLFO *moduleLFO_1 = new ModuleLFO();
//        ModuleTinySynth *moduleTinySynth_1 = new ModuleTinySynth("C(-1:C)Fe 2,dE | 4,F(-1:D) 2,eF 4,A(-1:G)g | 2,f(-1:F)eF(-1:E)G 4,f(-1:D)e(-1:C) | 2,d(-2:G)Edc 4,b(-2:G)G | c(-1:C)Fe 2,dE | 4,F(-1:D) 2,eF 4,A(-1:G)g | 2,A(-1:F)gA(-1:E)Cb(-1:G)gB(-1:B)D | 4,c(-1:C)g 8,C ^(^^)");
//        ModuleClock *moduleClock_1 = new ModuleClock(1,50);


//        moduleDelay_1->length_input = new ModuleConstant(1023);
//        moduleClockDivider_1->clock_input=moduleClock_1;
//        moduleTinySynth_1->trigger_input=moduleClockDivider_1;
//        moduleClockDivider_1->division_input= &param[0];
//        moduleDelay_1->mix_input= &param[1];
//        moduleDelay_1->feedback_input= &param[2];
//        moduleBitReducer_1->bit_input= &param[3];
//        moduleDelay_1->audio_input=moduleBitReducer_1;
//        moduleLowpassFilter_1->audio_input=moduleTinySynth_1;
//        moduleLowpassFilter_1->resonance_input= &param[5];
//        moduleBitReducer_1->audio_input=moduleLowpassFilter_1;
//        moduleLFO_1->frequency_input= &param[4];
//        moduleLowpassFilter_1->cutoff_input=moduleLFO_1;


//        this->last_module = moduleDelay_1;

        // end of espnode86 generated code //



        ModuleSamplePlayer *moduleSamplePlayer_1 = new ModuleSamplePlayer();
        ModuleClockDivider *moduleClockDivider_1 = new ModuleClockDivider();
        ModuleClockDivider *moduleClockDivider_2 = new ModuleClockDivider();
        ModuleClockDivider *moduleClockDivider_3 = new ModuleClockDivider();
        ModuleSamplePlayer *moduleSamplePlayer_2 = new ModuleSamplePlayer();
        ModuleSamplePlayer *moduleSamplePlayer_3 = new ModuleSamplePlayer();
        ModuleMixer3 *moduleMixer3_1 = new ModuleMixer3();
        ModuleReverb *moduleReverb_1 = new ModuleReverb();
        ModuleClock *moduleClock_1 = new ModuleClock(1,50);


        moduleSamplePlayer_1->sample_select = new ModuleConstant(64);
        moduleSamplePlayer_2->sample_select = new ModuleConstant(128);
        moduleSamplePlayer_3->sample_select = new ModuleConstant(256);
        moduleReverb_1->mix_input = new ModuleConstant(400);
        moduleReverb_1->feedback_input = new ModuleConstant(400);
        moduleClockDivider_1->clock_input=moduleClock_1;
        moduleSamplePlayer_1->trigger_input=moduleClockDivider_1;
        moduleClockDivider_1->division_input= &param[0];
        moduleClockDivider_2->clock_input=moduleClock_1;
        moduleClockDivider_2->division_input= &param[1];
        moduleClockDivider_3->division_input= &param[2];
        moduleClockDivider_3->clock_input=moduleClock_1;
        moduleSamplePlayer_2->trigger_input=moduleClockDivider_2;
        moduleSamplePlayer_3->trigger_input=moduleClockDivider_3;
        moduleMixer3_1->ch1=moduleSamplePlayer_1;
        moduleMixer3_1->ch2=moduleSamplePlayer_2;
        moduleMixer3_1->ch3=moduleSamplePlayer_3;
        moduleReverb_1->audio_input=moduleMixer3_1;


        this->last_module = moduleReverb_1;


        // end of espnode86 generated code //




    }
};
#endif // SYNTHTEST_H
