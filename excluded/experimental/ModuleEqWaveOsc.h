/*
 *  +----------------------+
 *  | ModuleEqWaveOsc      |
 *  |----------------------|
 *  > frequency_input      |
 *  > wavetable_input      |
 *  > offset_input         |
 *  > x_input              |
 *  > y_input              |
 *  |               output >
 *  +----------------------+
 */
// =============================================================================
// 
// ModuleEqWaveOsc is very similar to ModuleWavetable.  It uses equations to 
// generate short wavetable-like audio.  Unlike ModuleWavetable, this module uses
// more complex equations and the outcome is sometimes unusual.  The offset_input
// controls (to an extent) the starting position of "t" in the bytebeat equation.
// x_input and y_input control parameters in the equations, which modify the 
// sound of the equation output.  wavetable_input selects the equation which
// generates the bytebeat.  frequency_input controls the pitch of the output.
//
// Example usage:
//
//   ModuleEqWaveOsc *equation_wave_osc = new ModuleEqWaveOsc(equations);
//
//   equation_wave_osc->equation_input  = inputs->mod;
//   equation_wave_osc->frequency_input = inputs->sr;
//   equation_wave_osc->offset_input    = inputs->param1;
//   equation_wave_osc->x_input         = inputs->param2;
//   equation_wave_osc->y_input         = inputs->param3;
//  
//   this->last_module = equation_wave_osc;

#ifndef ModuleEqWaveOsc_h
#define ModuleEqWaveOsc_h

#include "Arduino.h"
#include "Module.h"
#include "Equations.h"
 
class ModuleEqWaveOsc : public Module
{
  
  public:
    ModuleEqWaveOsc(Equations *equations);
    uint32_t compute();
    
    // Inputs
    Module *frequency_input;
    Module *offset_input;
    Module *equation_input;
    Module *x_input;
    Module *y_input;
    
  private:
    uint32_t increments[128];
    Equations *equations;

    // 10.22 fixed point number (using the upper 10 bits for addressing the indexes 
    // up to 1024 (we only need 600), and an additional 22 bits (0-4194304) for simulating fractional values for
    // use when incrementing the variable fractional values
    uint32_t fixed_point_10_22_index;
    
    uint32_t wavetable_offset;
    uint32_t wavetable_offset_multiplier;
};

#endif
