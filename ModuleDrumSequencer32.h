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

#ifndef ModuleDrumSequencer32_h
#define ModuleDrumSequencer32_h

#include "Arduino.h"
#include "Module.h"
#include "ModuleOutput.h"


class ModuleDrumSequencer32 : public Module
{
  
  public:
    ModuleDrumSequencer32();
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
    boolean clocked;

    uint32_t patterns[3][8] = {
        { 
          // Bank #0 = kick patterns         
          2147516416,    // 10000000 00000000 10000000 00000000
          2147518496,    // 10000000 00000000 10001000 00100000
          2282227720,    // 10001000 00001000 00001000 00001000
          2315813384,    // 10001010 00001000 10000010 00001000
          2281736192,    // 10001000 00000000 10001000 00000000
          2282227712,    // 10001000 00001000 00001000 00000000
          2147616776,    // 10000000 00000010 00001000 00001000
          2181071360     // 10000010 00000000 10000010 00000000
        },
        {
          // Bank #1 = snare patterns
             8388736,    // 00000000 10000000 00000000 10000000
             8528514,    // 00000000 10000010 00100010 10000010
             8421544,    // 00000000 10000000 10000000 10101000
             8388738,    // 00000000 10000000 00000000 10000010
               32768,    // 00000000 00000000 10000000 00000000
            41943040,    // 00000010 10000000 00000000 00000000
            41943168,    // 00000010 10000000 00000000 10000000
             8423976     // 00000000 10000000 10001010 00101000
        },
        {
          // Bank #2 = hihat patterns
          2863311530,    // 10101010 10101010 10101010 10101010
          2290649224,    // 10001000 10001000 10001000 10001000
          2318043690,    // 10001010 00101010 10001010 00101010
          2318051496,    // 10001010 00101010 10101000 10101000
          2282228394,    // 10001000 00001000 00001010 10101010
          2149581312,    // 10000000 00100000 00000010 00000000
          2148050984,    // 10000000 00001000 10101000 00101000
           572662314     // 00100010 00100010 00100010 00101010
        }    
    };

};

#endif
