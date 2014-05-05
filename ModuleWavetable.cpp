#include "Arduino.h"
#include "ModuleWavetable.h"
#include "Defines.h"

#define WAVETABLE_LENGTH 512

ModuleWavetable::ModuleWavetable(EquationsWavetable *equations)
{
  fixed_point_10_22_index = 0;
  
  // Create frequency increments table
  for(uint32_t i=0; i < 128; i++)
  {
    float frequency = ((pow(2.0,(i-69.0)/12.0)) * 440.0);
    increments[i] = frequency * (float)((float)(WAVETABLE_LENGTH<<20)/(float)44100.0);
  }

  this->equations = equations; 

  // Initialize all inputs
  this->frequency_input = NULL;
  this->equation_input = NULL;
}

uint32_t ModuleWavetable::compute()
{
  // Read the frequency
  uint32_t frequency = this->readInput(frequency_input, CONVERT_TO_10_BIT);  
  
  // Select equation
  int equation = this->readInput(equation_input);

  // Calculate the index into the wavetable
  fixed_point_10_22_index += increments[((frequency*60)>>10) + 24];
  
  // If at the end of the wavetable
  if(fixed_point_10_22_index > (WAVETABLE_LENGTH << 22)) 
  {
    // Set the index back to the start
    fixed_point_10_22_index -= (WAVETABLE_LENGTH << 22);
  }
  
  uint32_t t = (fixed_point_10_22_index >> 22);
  
  // Play the selected equation
  return(this->equations->compute(equation, t));

}
