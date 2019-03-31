#include "OSCBundleReader.h"


OSCBundleReader::OSCBundleReader(WiFiUDP *UdpOsc)
{
    this->Udp = UdpOsc;
}


void OSCBundleReader::readToInputManager(Input_Manager *inputManager)
{
    OSCMessage osc_msg_rcv;
    int size = Udp->parsePacket();
    if (size > 0) {
      while (size--) {
        osc_msg_rcv.fill(Udp->read());
      }
      if (!osc_msg_rcv.hasError()) {
        for(int i=0; i<inputManager->osc.size(); ++i) {
            if(osc_msg_rcv.fullMatch(inputManager->osc[i]->address, 0))
            {
//              #ifdef DEBUG_SERIAL
              Serial.print(inputManager->osc[i]->address);
              Serial.print(" VAL: ");
              Serial.println(osc_msg_rcv.getInt(0));
//              #endif
              inputManager->osc[i]->setValue(osc_msg_rcv.getInt(0));
            }
        }
      }
    }
}
