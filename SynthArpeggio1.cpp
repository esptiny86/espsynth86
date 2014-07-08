#include "Arduino.h"
#include "defines.h"
#include "SynthArpeggio1.h"

SynthArpeggio1::SynthArpeggio1(Inputs* inputs)
{
  ModuleWavetableOsc *osc = new ModuleWavetableOsc();
  ModuleVCA *vca = new ModuleVCA();
  ModuleArpeggio *arpeggio = new ModuleArpeggio();
  ModuleExtClock *ext_clock = new ModuleExtClock(120, EIGHTH_NOTE_CLOCK_DIVISION);
  ModuleENV *env = new ModuleENV();
  ModuleDelay *delay = new ModuleDelay();
  
  // The ext_clock input will use the gate input if there is
  // one, otherwise default to an internal 120 BPM clock.
  ext_clock->clock_input = inputs->gate;

  arpeggio->clock_input = ext_clock;
  arpeggio->root_note_input = inputs->sr;
  arpeggio->pattern_input = inputs->param1;

  // Patch up ocillator
  osc->frequency_input = arpeggio;
  osc->wavetable_input = inputs->mod; 
  
  // Envelope for VCA
  env->trigger_input = ext_clock;
  env->frequency_input = inputs->param2;
  env->slope_input = new ModuleConstant(2);

  // Patch up VCA
  vca->cv_input = env->output;
  vca->audio_input = osc;
  
  // Patch delay
  delay->audio_input = vca;
  delay->mix_input = inputs->param3;
  delay->feedback_input = new ModuleConstant(2048);
  delay->length_input = inputs->param1;

  this->last_module = delay;
}
