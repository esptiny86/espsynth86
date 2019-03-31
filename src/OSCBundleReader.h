#ifndef OSCBUNDLEREADER_H
#define OSCBUNDLEREADER_H

#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <ModuleExternalInput.h>

enum OSC_TYPE {
    OSC_MESSAGE,
    OSC_BUNDLE,
    OSC_VCV_LEMUR,
    OSC_TOUCHOSC
};

class OSCBundleReader
{
public:
    OSCBundleReader(WiFiUDP* UdpOsc, OSC_TYPE osc_type);
    void readToInputManager(Input_Manager * inputManager);
    void readOSCBundle(Input_Manager * inputManager);
    void readOSCMessage(Input_Manager * inputManager);

private:
    WiFiUDP* Udp;
    OSC_TYPE oscType;
};

#endif // OSCBUNDLEREADER_H
