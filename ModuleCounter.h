/*
 *  +----------------------+
 *  | ModuleCounter        |
 *  |----------------------|
 *  > clock                |
 *  |               output >
 *  +----------------------+
 *
 *
 *  The counter module counts.  I'll try to 
 *  explain more later.
 */
 
#ifndef ModuleCounter_h
#define ModuleCounter_h

// #include "Arduino.h"
#include "Module.h"

class ModuleCounter : public Module
{
  public:
    ModuleCounter(int target);
    uint32_t compute();
    
    // Inputs
    Module *clock_input;      
    
  private:
    int value;
    int target;
    uint32_t my_output;
    boolean clocked;
    
};

#endif
