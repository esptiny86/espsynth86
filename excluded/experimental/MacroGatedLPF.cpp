#include "Arduino.h"
#include "MacroGatedLPF.h"
#include "Defines.h"

// Include the modules
#include "ModuleLowpassFilter.h"
#include "ModuleENV.h"

MacroGatedLPF::MacroGatedLPF()
{
	// Initialize all inputs
    // this->audio_input = NULL;
    // this->trigger_input = NULL;

    // Instantiate all modules
    lowpass_filter = new ModuleLowpassFilter();
    envelope_generator = new ModuleENV();

    //
    // Wire together the macro
    //

    envelope_generator->trigger_input = NULL;
    envelope_generator->frequency_input = new ModuleConstant(1000);
    envelope_generator->slope_input = new ModuleConstant(0);

    lowpass_filter->audio_input = NULL;
    // lowpass_filter->cutoff_input = envelope_generator;
    lowpass_filter->cutoff_input = new ModuleConstant(2000);
    lowpass_filter->resonance_input = new ModuleConstant(0);
}

uint16_t MacroGatedLPF::compute()
{
  return(this->lowpass_filter->compute());
}