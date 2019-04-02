
#ifndef SYNTHTEST_H
#define SYNTHTEST_H

#include <Modules.h>

class SynthTest : public SynthExtended
{
  public:

    void defineSynth(Input_Manager * inputManager)
    {

     //Define Node Objects
  ModuleWavetableOsc *moduleWavetableOsc_1 = new ModuleWavetableOsc();
  ModuleExternalInput *osc1 = new ModuleExternalInput("/osc/ch/1",inputManager);
  ModuleExternalInput *pot0 = new ModuleExternalInput(0,inputManager);

  moduleWavetableOsc_1->frequency_input = osc1;
  moduleWavetableOsc_1->wavetable_input = pot0;

  
      ModuleOutputDAC *dac = new ModuleOutputDAC();

      dac->left = moduleWavetableOsc_1;
      dac->right = moduleWavetableOsc_1;

      this->last_module = dac;
    }
};
#endif // SYNTHTEST_H    


/*

  This is espnode86 stuff do not edit

  --BEGINESPNODEPATCH--
  djIuMS4xCm5ldHdvcmsvYWRkLXBhdGNoIHNhZDQgcm9vdApwYXRjaC9vcGVuIHNhZDQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBmdm1mIGVzcG5vZGUvbm9kZWxpc3QgRXNwbm9kZSUyMFBhbGV0dGUKbm9kZS90dXJuLW9uIGZ2bWYKcGF0Y2gvYWRkLW5vZGUgc2FkNCB2
  cjF3IHdhdmUvb3NjaWxsYXRvciBPc2NpbGxhdG9yCm5vZGUvdHVybi1vbiB2cjF3Cm5vZGUvYWRkLWlubGV0IHZyMXcgczlxbiBlc3Bub2RlL3N0cmluZyBmcmVxdWVuY3lfaW5wdXQgZnJlcXVlbmN5X2lucHV0Cm5vZGUvYWRkLWlubGV0IHZyMXcgbHNqbiBlc3Bu
  b2RlL3N0cmluZyB3YXZldGFibGVfaW5wdXQgd2F2ZXRhYmxlX2lucHV0Cm5vZGUvYWRkLW91dGxldCB2cjF3IGZ2MnkgZXNwbm9kZS9zdHJpbmcgT3V0IE91dApwYXRjaC9hZGQtbm9kZSBzYWQ0IHViN2sgb3V0cHV0L2RhYyBBdWRpbyUyMERBQwpub2RlL3R1cm4t
  b24gdWI3awpub2RlL2FkZC1pbmxldCB1YjdrIDNnejkgZXNwbm9kZS9zdHJpbmcgYXVkaW9faW5wdXQgYXVkaW9faW5wdXQKcGF0Y2gvYWRkLW5vZGUgc2FkNCBkYWV5IGlucHV0L2NvbnN0YW50IENvbnN0YW50JTdDMC0xMDIzCm5vZGUvdHVybi1vbiBkYWV5Cm5v
  ZGUvYWRkLWlubGV0IGRhZXkgemVrOSBlc3Bub2RlL3N0cmluZyB1c2VyLXZhbHVlIHVzZXItdmFsdWUKbm9kZS9hZGQtb3V0bGV0IGRhZXkgZTVlOSBlc3Bub2RlL3N0cmluZyBudW1iZXIgbnVtYmVyCnBhdGNoL2FkZC1ub2RlIHNhZDQgM2ZveSBpbnB1dC9jb25z
  dGFudCBDb25zdGFudCU3QzAtMTAyMwpub2RlL3R1cm4tb24gM2ZveQpub2RlL2FkZC1pbmxldCAzZm95IG1mbGIgZXNwbm9kZS9zdHJpbmcgdXNlci12YWx1ZSB1c2VyLXZhbHVlCm5vZGUvYWRkLW91dGxldCAzZm95IHBpc3MgZXNwbm9kZS9zdHJpbmcgbnVtYmVy
  IG51bWJlcgpub2RlL21vdmUgZnZtZiAzMCAyMApub2RlL21vdmUgdnIxdyA2MjEgMTc1Cm5vZGUvbW92ZSB1YjdrIDk2OSAxNTAKbm9kZS9tb3ZlIGRhZXkgMjk2IDE0NApub2RlL21vdmUgM2ZveSAyOTAgMjU3Cm91dGxldC9jb25uZWN0IGZ2MnkgM2d6OSBtZmR4
  Cm91dGxldC9jb25uZWN0IHBpc3MgbHNqbiAzcHczCm91dGxldC9jb25uZWN0IGU1ZTkgczlxbiBsc3ByCm5vZGUvdXBkYXRlLWlubGV0IHZyMXcgczlxbiBmcmVxdWVuY3lfaW5wdXQgNTAwCm5vZGUvdXBkYXRlLWlubGV0IHZyMXcgbHNqbiB3YXZldGFibGVfaW5w
  dXQgMApub2RlL3VwZGF0ZS1pbmxldCB1YjdrIDNnejkgYXVkaW9faW5wdXQgMApub2RlL3VwZGF0ZS1vdXRsZXQgZGFleSBlNWU5IG51bWJlciA1MDAKbm9kZS91cGRhdGUtaW5sZXQgZGFleSB6ZWs5IHVzZXItdmFsdWUgNTAwCm5vZGUvdXBkYXRlLW91dGxldCAz
  Zm95IHBpc3MgbnVtYmVyIDAKbm9kZS91cGRhdGUtaW5sZXQgM2ZveSBtZmxiIHVzZXItdmFsdWUgMA==
  --ENDESPNODEPATCH--

*/
