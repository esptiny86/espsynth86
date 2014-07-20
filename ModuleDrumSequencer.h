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
// TODO: create example
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
