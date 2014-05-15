#include "SynthEqWave.h"

SynthEqWave::SynthEqWave(Inputs *inputs, Equations *equations)
{
  ModuleEqWaveOsc *equation_wave_osc = new ModuleEqWaveOsc(equations);

  equation_wave_osc->equation_input  = inputs->mod;
  equation_wave_osc->frequency_input = inputs->sr;
  equation_wave_osc->offset_input    = inputs->param1;
  equation_wave_osc->x_input         = inputs->param2;
  equation_wave_osc->y_input         = inputs->param3;
  
  this->last_module = equation_wave_osc;
}
