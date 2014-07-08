/*
* +----------------------+
* | ModuleArpeggio       |
* |----------------------|
* > root_note            |
* > pattern              |
* > clock                |
* |                      |
* |               output >
* +----------------------+
*
*/
// =============================================================================
// 
// ModuleArpeggio is a clocked arpeggiation generator with variable pattern
// and root note.  Arpeggiations are defined in ModuleArpeggio.cpp.
//
//
// Example usage:
//
//   ModuleArpeggio *arp = new ModuleArpeggio();
//   ModuleWavetable *wavetable_osc = new ModuleWavetable(equations);
//
//   arp->clock_input      = inputs->gate;
//   arp->root_note_input  = inputs->sr;
//   arp->pattern_input    = inputs->param1;
//  
//   wavetable_osc->frequency_input = arp;
//   wavetable_osc->equation_input = inputs->param2;
//
//   this->last_module = wavetable_osc;
//
 
#ifndef ModuleArpeggio_h
#define ModuleArpeggio_h

#include "Arduino.h"
#include "Module.h"

class ModuleArpeggio : public Module
{
  
  public:
  
    ModuleArpeggio();
    uint16_t compute();
    
    // Inputs
    Module *root_note_input;
    Module *pattern_input;
    Module *clock_input;

  private:
  
    int step;
    int8_t arpeggiations[8][8]; // 8 scales, 8 notes per scale
    boolean clocked;
    uint32_t my_output;
};

#endif
