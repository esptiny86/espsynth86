#include "Arduino.h"
#include "ModuleEqWaveOsc.h"
#include "Defines.h"

// #define WAVETABLE_LENGTH 512

#define WAVETABLE_LENGTH 512

ModuleEqWaveOsc::ModuleEqWaveOsc(Equations *equations)
{
  fixed_point_10_22_index = 0;
  wavetable_offset = 0;
  wavetable_offset_multiplier = 10;
  
  // Create frequency increments table
  for(uint32_t i=0; i < 128; i++)
  {
    float frequency = ((pow(2.0,(i-69.0)/12.0)) * 440.0);
    increments[i] = frequency * (float)((float)(WAVETABLE_LENGTH<<20)/(float)44100.0);
  }

  this->equations = equations; 

  // Initialize all inputs
  this->frequency_input = NULL;
  this->offset_input = NULL;
  this->equation_input = NULL;
  this->x_input = NULL;
  this->y_input = NULL;
}

uint32_t ModuleEqWaveOsc::compute()
{
  // Read the frequency
  uint32_t frequency = this->readInput(frequency_input, CONVERT_TO_10_BIT);  
  
  // Read the wavetable input and convert to 0 to 512
  uint32_t new_wavetable_offset = this->readInput(offset_input, CONVERT_TO_9_BIT) * wavetable_offset_multiplier;
  
  // Read x and y, which are variables that shape the equation output
  uint32_t x = this->readInput(x_input, CONVERT_TO_7_BIT);
  uint32_t y = this->readInput(y_input, CONVERT_TO_7_BIT);
  
  // Select equation
  int equation = this->readInput(equation_input);

  // Calculate the index into the wavetable
  fixed_point_10_22_index += increments[(frequency*60)>>10];
  
  // If at the end of the wavetable
  if(fixed_point_10_22_index > (WAVETABLE_LENGTH << 22)) 
  {
    // The wavetable_offset is only updated once the current wavetable has
    // completed playing.  This is to avoid pitch changes when the wavetable
    // offset is being modified.
    wavetable_offset = new_wavetable_offset;
    
    // Set the index back to the start
    fixed_point_10_22_index -= (WAVETABLE_LENGTH << 22);
  }
  
  
  uint32_t t = (fixed_point_10_22_index >> 22) + wavetable_offset;
  
  // Play the selected equation
  return(this->equations->compute(equation, t, x, y, 1));

}
