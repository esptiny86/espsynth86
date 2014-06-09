/*
 *  +----------------------+
 *  | ModuleMap            |
 *  |----------------------|
 *  > input                |
 *  |               output >
 *  +----------------------+
 *
 *
 */
// =============================================================================
// 
// Maps an incoming signal to a range.  The range is passed into this module's
// constructor.  For example, to map a value between 0 and 4 (inclusive), 
// you would instantiate a ModuleMap like:
//
//   ModuleMap *map_0_4 = new ModuleMap(0,4);
//
// You use a ModuleMap module if you need to adjust the output of one module to
// be compatible with the input of another module.  Module's are constructed such
// that this conversion is normally unnecessary.  But, for example, if you want
// the output of an LFO to select from the first 5 wavetables in the 
// ModuleWavetableOsc, then you'll need to use a ModuleMap (see example below).
//
// Example usage:
//
//   ModuleMap *map_0_5 = new ModuleMap(0,5);
//   ModuleLFO *lfo = new LFO();
//   ModuleWavetableOsc *wavetable_osc = new WavetableOsc();
//
//   lfo->frequency_input = 500;
//   map_0_5->input = lfo;
//   wavetable_osc->wavetable_input = map_0_5;
//

 
#ifndef ModuleMap_h
#define ModuleMap_h

#include "Module.h"

class ModuleMap : public Module
{
  public:
    ModuleMap(uint32_t low, uint32_t high);
    uint32_t compute();
    
    // Inputs
    Module *input;

    uint32_t low;
    uint32_t high;
};

#endif