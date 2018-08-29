/*
 *  +----------------------------+
 *  | ModuleWaveFolder           |
 *  |----------------------------|
 *  > audio_input                |
 *  > lower_clipping_level_input |
 *  > upper_clipping_level_input |
 *  |                            |
 *  |                     output >
 *  +----------------------------+
 */
// =============================================================================
// 
// ModuleWaveFolder is simple audio wave folder with automatic gain compensation.
// See http://www.analoguehaven.com/doepfer/a137/A137_2principle.gif
//
// lower_clipping_level_input and upper_clipping_level_input both clip MORE when
// increased in value.  This allows adjustment of both lower and upper clipping
// levels with a single input.  For example, here both clipping levels are 
// controlled by param1:
//
//   ModuleWaveFolder *wave_folder = new ModuleWaveFolder();
//   wave_folder->lower_clipping_level_input = inputs->param1; 
//   wave_folder->upper_clipping_level_input = inputs->param1; 
//
// Example usage:
//
//   // SynthTutorial15
//
//   ModuleWavetableOsc *wavetable_osc = new ModuleWavetableOsc();
//   ModuleWaveFolder *wave_folder = new ModuleWaveFolder();
//
//   wavetable_osc->wavetable_input  = inputs->mod;
//   wavetable_osc->frequency_input  = inputs->sr;
//  
//   wave_folder->audio_input = wavetable_osc;
//   wave_folder->lower_clipping_level_input = inputs->param1;
//   wave_folder->upper_clipping_level_input = inputs->param2;
//
//   this->last_module = wave_folder;
//
// Also see: SynthWavetableFolder.cpp

#ifndef ModuleWaveFolder_h
#define ModuleWaveFolder_h

#include "Module.h"

class ModuleWaveFolder : public Module
{
    public:    
  	ModuleWaveFolder();
    uint16_t compute();  

    // Inputs
    Module *audio_input;
    Module *lower_clipping_level_input;
    Module *upper_clipping_level_input;    
};

#endif
