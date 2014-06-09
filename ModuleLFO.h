/*
 *  +----------------------+
 *  | ModuleLFO            |
 *  |----------------------|
 *  > frequency_input      |
 *  > wavetable_input      |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// ModuleLFO is a low frequency oscillator based on wavetables with control 
// over frequency and wavetable selection.
//
// Example usage:
//
//    // Create an lfo, quantizer, and oscillator
//    // They're going to be patched together like:
//    //
//    // lfo ---> quantizer ---> oscillator
//    // 
//    ModuleLFO *lfo = new ModuleLFO();
//    ModuleQuantizer *quantizer = new ModuleQuantizer();
//    ModuleWavetableOsc *osc = new ModuleWavetableOsc();
//
//    // Control the LFO rate and waveform via inputs
//    lfo->frequency_input = inputs->sr;
//    lfo->wavetable_input = inputs->param2;
//
//    // Wire the output of the lfo to the input of the quantizer
//    quantizer->scale_input = inputs->param1;
//    quantizer->cv_input = lfo;
//
//    // Wire the output of the quantizer to the frequency
//    // input of the oscillator.
//    osc->wavetable_input  = inputs->mod;
//    osc->frequency_input  = quantizer;
//
//    this->last_module = osc;

#ifndef ModuleLFO_h
#define ModuleLFO_h

#include "Arduino.h"
#include "Module.h"

class ModuleLFO : public Module
{
  
  public:
    ModuleLFO();

    // Inputs
    Module *frequency_input;
    Module *wavetable_input;
    
  private:
  
    // Functions
    uint32_t compute();  

    // Variables
    uint32_t wavetable_index;
    uint32_t frequency;
    uint16_t wavetable;                    // The currenly selected wavetable
    uint32_t increments[4096];
    
    // 10.22 fixed point number (using the upper 10 bits for addressing the indexes 
    // up to 1024 (we only need 600), and an additional 22 bits (0-4194304) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_10_22_index;
    uint32_t increment_by;
};

#endif
