/*
 *  +------------------------+
 *  | ModuleRotatingRouter3  |
 *  |------------------------|
 *  > rotate_input           |
 *  |                        |
 *  > input_1       output_1 >
 *  > input_2       output_2 >
 *  > input_3       output_3 >
 *  |                        |
 *  +------------------------+
 *
 */
// =============================================================================
// 
// ModuleRotatingRouter3 takes 3 inputs and routes them to 3 outputs.  For 
// example:
//
//   input_1 => output_1
//   input_2 => output_2
//   input_3 => output_3
//
// When the rotation input is triggered, the output "rotates".
//
// The first rotation is:
//
//   input_1 => output_2
//   input_2 => output_3
//   input_3 => output_1
//
// The second rotation is:
//
//   input_1 => output_3
//   input_2 => output_1
//   input_3 => output_2
//

#ifndef ModuleRotatingRouter3_h
#define ModuleRotatingRouter3_h

#include "Module.h"
#include "ModuleOutput.h"

class ModuleRotatingRouter3 : public Module
{
  public:
    ModuleRotatingRouter3();  	
    uint16_t compute();

    uint8_t rotation;
    uint16_t trigger; 
    boolean triggered;
    
    // Inputs
    Module *rotate_input;
    Module *input_1;
    Module *input_2;
    Module *input_3;

    // Outputs
    ModuleOutput *output_1;
    ModuleOutput *output_2;
    ModuleOutput *output_3; 
};

#endif