#include "OSCBundleReader.h"


OSCBundleReader::OSCBundleReader(WiFiUDP *UdpOsc, OSC_TYPE osc_type)
{
//    this->Udp = UdpOsc;
//    this->oscType = osc_type;
}


void OSCBundleReader::readToInputManager(Input_Manager *inputManager)
{
//    if (this->oscType == OSC_MESSAGE){
//        this->readOSCMessage(inputManager);
//    }else{
//        this->readOSCBundle(inputManager);
//    }
}

void OSCBundleReader::readOSCBundle(Input_Manager *inputManager)
{
//    OSCMessage osc_msg_rcv;
//    OSCBundle osc_msg_rcv_bnd;
//
//    int size = Udp->parsePacket();
//    if (size > 0) {
//      while (size--) {
//        osc_msg_rcv_bnd.fill(Udp->read());
//      }
//      if (!osc_msg_rcv_bnd.hasError()) {
//        for(int i=0; i<inputManager->osc.size(); ++i) {
//
//            OSCMessage msg = osc_msg_rcv_bnd.getOSCMessage(0);
//
//            if(msg.fullMatch(inputManager->osc[i]->address, 0))
//            {
//              if (this->oscType == OSC_VCV_LEMUR)
//              {
//                  inputManager->osc[i]->setValue(msg.getInt(0));
//              }else{
//                  inputManager->osc[i]->setValue(msg.getFloat(0)*1023);
//              }
//
//            }
//        }
//      }
//}
}

void OSCBundleReader::readOSCMessage(Input_Manager *inputManager)
{
//    OSCMessage osc_msg_rcv;
//    int size = Udp->parsePacket();
//    if (size > 0) {
//      while (size--) {
//        osc_msg_rcv.fill(Udp->read());
//      }
//      if (!osc_msg_rcv.hasError()) {
//        for(int i=0; i<inputManager->osc.size(); ++i) {
//            if(osc_msg_rcv.fullMatch(inputManager->osc[i]->address, 0))
//            {
//              inputManager->osc[i]->setValue(osc_msg_rcv.getInt(0));
//            }
//        }
//      }
//    }
}

