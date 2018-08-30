/*
 *  +----------------------+
 *  | ModuleClockDivider   |
 *  |----------------------|
 *  > clock_input          |
 *  > division_input       |
 *  |               output >
 *  +----------------------+
 *
 *
 *  The clock module divides a clock signal.
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
 *    ModuleClock *clock = new ModuleClock(120);
 *    ModuleClockDivider *clock_divider = new ModuleClockDivider();
 *    clock_divider->clock_input = clock;
 *    clock_divider->division_input = new ModuleConstant(96);
 *
 *  For Whole Notes, divide by 96
 *  For Half Notes, divide by 48
 *  For Quarter Notes, divide by 24
 *  For 8th notes, divide by 12
 *  For 16th Notes, divide by 6
 *  For 32nd Notes, divide by 3
 *  For 64th Notes, divide by 1 (although this is the default output of the clock module)
 */
 
#ifndef ModuleClockDivider_h
#define ModuleClockDivider_h

#include "Module.h"

class ModuleClockDivider : public Module
{
  public:
    ModuleClockDivider();
    uint16_t compute();
    
    // inputs
    Module *clock_input;
    Module *division_input;
    
  private:
    uint32_t counter;
    uint32_t my_output;
    int clock_division;
    boolean clocked;
};

#endif
