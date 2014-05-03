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
*/
 
#ifndef ModuleArpeggio_h
#define ModuleArpeggio_h

#include "Arduino.h"
#include "Module.h"

class ModuleArpeggio : public Module
{
  
  public:
  
    ModuleArpeggio();
    uint32_t compute();
    
    // Inputs
    Module *root_note_input;
    Module *pattern_input;
    Module *clock_input;

  private:
  
    int step;
    int arpeggiations[8][8]; // 8 scales, 8 notes per scale
    boolean clocked;
    uint32_t my_output; // not to be confused with the variable 'output' defined in Module.h
};

#endif
