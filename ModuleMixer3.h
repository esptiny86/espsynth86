/*
 *  +----------------------+
 *  | ModuleMixer3         |
 *  |----------------------|
 *  > input1               |
 *  > input2               |
 *  > input3               |
 *  |                      |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// 3 input mixer.
//
// Example usage:
//
//  ModuleDrumSequencer *drum_sequencer = new ModuleDrumSequencer();
//
//  ModuleEqDrum *kick = new ModuleEqDrum();
//  ModuleEqDrum *snare = new ModuleEqDrum();
//  ModuleEqDrum *hihat = new ModuleEqDrum();
//  ModuleMixer3 *mixer = new ModuleMixer3();
//
//  drum_sequencer->clock_input = inputs->gate;
//
//  drum_sequencer->kick_pattern_input = inputs->param1;
//  drum_sequencer->snare_pattern_input = inputs->param2;
//  drum_sequencer->hihat_pattern_input = inputs->param3;
//
//  kick->trigger_input = drum_sequencer->kick_output;
//  kick->sample_rate_input = inputs->sr;
//  kick->drum_selection_input = new ModuleConstant(0);
//
//  snare->trigger_input = drum_sequencer->snare_output;
//  snare->sample_rate_input = inputs->sr;
//  snare->drum_selection_input = new ModuleConstant(3);
//
//  hihat->trigger_input = drum_sequencer->hihat_output;;
//  hihat->sample_rate_input = inputs->sr;
//  hihat->drum_selection_input = new ModuleConstant(7);
//
//  mixer->input_1 = kick;
//  mixer->input_2 = snare;
//  mixer->input_3 = hihat;
//
//
//  this->last_module = mixer;


#ifndef ModuleMixer3_h
#define ModuleMixer3_h

#include "Module.h"

class ModuleMixer3 : public Module
{
    public:    
  	ModuleMixer3();
    uint16_t compute();  

    // Inputs
    Module *input_1;
    Module *input_2;
    Module *input_3;
};

#endif
