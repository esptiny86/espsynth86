#ifndef OSCBUNDLEREADER_H
#define OSCBUNDLEREADER_H

#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <OSCBundle.h>
#include <OSCData.h>
#include <ModuleExternalInput.h>

class OSCBundleReader
{
public:
    OSCBundleReader(WiFiUDP* UdpOsc);
    void readToInputManager(Input_Manager * inputManager);
private:
    WiFiUDP* Udp;
};

#endif // OSCBUNDLEREADER_H
