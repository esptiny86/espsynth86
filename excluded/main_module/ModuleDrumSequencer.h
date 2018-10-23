/*
 *  +----------------------+
 *  | ModuleDrumSequencer  |
 *  |----------------------|
 *  > clock_input          |
 *  |                      |
 *  > kick_pattern_input   |
 *  > snare_pattern_input  |
 *  > hat_pattern_input    |
 *  |                      |
 *  |          kick_output >
 *  |         snare_output >
 *  |           hat_output >
 *  +----------------------+
 *
 */
// =============================================================================
// 
// ModuleDrumSequencer is a simple gate sequencer for drums.  It contains three 
// different pattern generators, one for kick, snare, and hihat.
//
// Example usage:
//
//   ModuleDrumSequencer *drum_sequencer = new ModuleDrumSequencer();
//   ModuleSamplePlayer *kick = new ModuleSamplePlayer();
//   ModuleSamplePlayer *snare = new ModuleSamplePlayer();
//   ModuleSamplePlayer *hihat = new ModuleSamplePlayer();
//   ModuleKitSelect *kit_select = new ModuleKitSelect();
//   ModuleMixer3 *mixer = new ModuleMixer3();
//   ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
//
//   // Use the external clock when available, otherwise
//   // default to the internal 120BPM clock
//   ext_clock->clock_input = inputs->gate;
//
//   drum_sequencer->clock_input = ext_clock;
//
//   // Use the 3 parameters to select the patterns 
//   // used for the drums.
//   drum_sequencer->kick_pattern_input = inputs->param1->smooth;
//   drum_sequencer->snare_pattern_input = inputs->param2->smooth;
//   drum_sequencer->hihat_pattern_input = inputs->param3->smooth;
//
//   // Use the mode input to select the drum kit
//   kit_select->kit_selection_input = inputs->mod;
//
//   // Set the kick, snare, and hihat inputs
//   kick->trigger_input = drum_sequencer->kick_output;
//   kick->sample_rate_input = inputs->sr;
//   kick->sample_selection_input = kit_select->kick_output;
//
//   snare->trigger_input = drum_sequencer->snare_output;
//   snare->sample_rate_input = inputs->sr;
//   snare->sample_selection_input = kit_select->snare_output;
//
//   hihat->trigger_input = drum_sequencer->hihat_output;;
//   hihat->sample_rate_input = inputs->sr;
//   hihat->sample_selection_input = kit_select->hihat_output;
//
//   // Mix everything together
//   mixer->input_1 = kick;
//   mixer->input_2 = snare;
//   mixer->input_3 = hihat;
//
//   this->last_module = mixer;
//

#ifndef ModuleDrumSequencer_h
#define ModuleDrumSequencer_h

#include "Arduino.h"
#include "Module.h"
#include "ModuleOutput.h"


class ModuleDrumSequencer : public Module
{
  
  public:
    ModuleDrumSequencer();
    uint16_t compute();
    
    // Inputs
    Module *clock_input;
    Module *kick_pattern_input;
    Module *snare_pattern_input;
    Module *hihat_pattern_input;
    
    // Outputs
    ModuleOutput *kick_output;
    ModuleOutput *snare_output;
    ModuleOutput *hihat_output;    

  private:
    uint8_t step;

    // 3 banks, 8 patterns per bank
    uint16_t patterns[3][8] =
    {
        { 
            // Bank #0 = kick patterns         
            32896,    // 1000000010000000
            32932,    // 1000000010100100
            41506,    // 1010001000100010
            45714,    // 1011001010010010
            41120,    // 1010000010100000
            41504,    // 1010001000100000
            33058,    // 1000000100100010
            41508     // 1001000010010000
        },
        {
            // Bank #1 = snare patterns
            2056,     // 0000100000001000
            2393,     // 0000100101011001
            2190,     // 0000100010001110
            2057,     // 0000100000001001
            128,      // 0000000010000000
            6144,     // 0001100000000000
            6152,     // 0001100000001000
            2230      // 0000100010110110
        },
        {
            // Bank #2 = hihat patterns
            65535,    // 1111111111111111
            43690,    // 1010101010101010
            47031,    // 1011011110110111
            47086,    // 1011011111101110
            41535,    // 1010001000111111
            33808,    // 1000010000010000
            33510,    // 1000001011100110
            21847     // 0101010101010111
        }
    };

    boolean clocked;
};

#endif
