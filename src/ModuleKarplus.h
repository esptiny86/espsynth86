//#ifndef MODULKARPLUS_H
//#define MODULKARPLUS_H
///*
// *  +----------------------+
// *  | ModuleLFO            |
// *  |----------------------|
// *  > frequency_input      |
// *  > wavetable_input      |
// *  |                      |
// *  |               output >
// *  +----------------------+
// */
//// =============================================================================
////
//// ModuleLFO is a low frequency oscillator based on wavetables with control
//// over frequency and wavetable selection.
////
//// Example usage:
////
////    // Create an lfo, quantizer, and oscillator
////    // They're going to be patched together like:
////    //
////    // lfo ---> quantizer ---> oscillator
////    //
////    ModuleLFO *lfo = new ModuleLFO();
////    ModuleQuantizer *quantizer = new ModuleQuantizer();
////    ModuleWavetableOsc *osc = new ModuleWavetableOsc();
////
////    // Control the LFO rate and waveform via inputs
////    lfo->frequency_input = inputs->sr;
////    lfo->wavetable_input = inputs->param2;
////
////    // Wire the output of the lfo to the input of the quantizer
////    quantizer->scale_input = inputs->param1;
////    quantizer->cv_input = lfo;
////
////    // Wire the output of the quantizer to the frequency
////    // input of the oscillator.
////    osc->wavetable_input  = inputs->mod;
////    osc->frequency_input  = quantizer;
////
////    this->last_module = osc;

//#include "Arduino.h"
//#include "Module.h"

//class ModuleKarplus : public Module
//{

//  public:
//    ModuleKarplus(){
//        frequency_input = NULL;
//        wavetable_index = NULL;
//    };

////    int sendKarplusStrongSound(const uint16_t f /*Hz*/, const uint8_t T /*sec*/) {
////    }

//    // Inputs
//    Module *frequency_input;
//    Module *wavetable_input;

//  private:
//    const uint32_t sr = 11025;
//    uint32_t iter = 0;
//    // Functions
//    uint16_t compute(){


//        const uint8_t N = sr / 44; // f == 44Hz..65535Hz
//        int16_t buf[N];
//        uint8_t bh = 0;
//        const int8_t v;

//        if (iter == 0) iter = sr*1;

//        for (uint8_t i=0; i!=N; i++)
//           buf[i] = (int16_t) random(-32768,32767);


//        if(iter > 0) {
//            iter--;

//            v = (int8_t) (buf[bh] >> 8);
//   //         sendTo8bitDAC(v);
//            const uint8_t nbh = bh!=N-1 ? bh+1 : 0;
//            register int32_t avg = buf[bh] + (int32_t)buf[nbh];
//            avg = (avg << 10) - avg; // subtract avg more than once to get faster volume decrease
//            buf[bh] = avg >> 11; // no division, just shift
//            bh = nbh;

//        }



//        return 0;
//    };

//};

//#endif // MODULKARPLUS_H
