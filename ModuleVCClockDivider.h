/*
 *  +----------------------+
 *  | ModuleClockDivider   |
 *  |----------------------|
 *  > Clock                |
 *  > Clock Divivision     |
 *  |               output >
 *  +----------------------+
 *
 *
 *  The clock module divides a clock signal.  This is similar to the ModuleClockDivider,
 *  except it allows CV control over the clock division.
 *
 *  For example, with a clock_division of 2...
 *
 *  Input:
 *
 *
 *           _____       _____       _____       _____       _____       _____
 *          |     |     |     |     |     |     |     |     |     |     |     |
 *     _____|     |_____|     |_____|     |_____|     |_____|     |_____|     |_____
 *
 * 
 *  Output:
 *
 *                       _______________________                          __________
 *                      |                       |                        |
 *     _________________|                       |________________________|  
 *    
 *
 *  Example usage:
 *
 *  (TODO)
 */
 
#ifndef ModuleVCClockDivider_h
#define ModuleVCClockDivider_h

#include "Module.h"

class ModuleVCClockDivider : public Module
{
  public:
    ModuleVCClockDivider();
    uint32_t compute();
    
    // inputs
    Module *clock_input;
    Module *clock_division_input;
    
  private:
    uint32_t counter;
    uint32_t my_output;
    boolean clocked;
    int clock_divisions[7];
};

#endif
