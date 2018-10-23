/*
 *  +------------------------+
 *  | ModuleADSR             |
 *  |------------------------|
 *  > trigger input          |
 *  |                 output >
 *  +------------------------+
 *
 *
 *  For attack, decay, and release stages, time in seconds = parameter / 410
 *
 *  For example:
 *
 *    parameter     time
 *    =================================== 
 *    1           2.5ms   (1/410 = .0024)
 *    2           4.9ms   (2/410 = .0049)
 *    3           7.3ms   (3/410 = .0073)
 *    20           50ms or .05 seconds
 *    41          100ms or .1 seconds
 *    102         250ms or .25 seconds
 *    200         488ms or .48 seconds
 *    201         490ms or .49 seconds
 *    202         493ms or .49 seconds
 *    410         1 second
 *
 *    If you know the time in milliseconds, you can calculate the parameter using:
 *    parameter = floor((milliseconds * 410) / 1000)
 *
 *    For example, if you want an attack speed of .5 seconds (500ms), it would be:
 *    attack = floor((500 * 410) / 1000) = 205
 */
 
#ifndef ModuleADSR_h
#define ModuleADSR_h

#include "Module.h"

// Constants for internal ADSR states
#define ADSR_ATTACK 0
#define ADSR_DECAY 1
#define ADSR_SUSTAIN 2
#define ADSR_RELEASE 3
#define ADSR_INACTIVE 4

class ModuleADSR : public Module
{
  public:
    ModuleADSR();
    ModuleADSR(uint32_t attack_time, uint32_t decay_time, uint32_t sustain, uint32_t release_time);
    uint32_t compute();
	
    void set(uint32_t attack_time, uint32_t decay_time, uint32_t sustain, uint32_t release_time);
    void setAttackTime(uint32_t value);
    void setDecayTime(uint32_t value);
    void setSustain(uint32_t value);
    void setReleaseTime(uint32_t value);
    
    // Inputs
    Module *trigger_input;     
    
  private:
    uint16_t state;         // ADSR_ATTACK, ADSR_DECAY, etc..
    uint32_t counter;
    uint32_t output;
    boolean triggered;
    
    uint32_t attack_time;   // measured in milliseconds
    uint32_t decay_time;    // measured in milliseconds
    uint32_t sustain;  // measured in milliseconds
    uint32_t release_time;  // measured in milliseconds

};

#endif

