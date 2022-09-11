#include "EspSynth.h"
#include "synthx.h"

#include "ESP8266WiFi.h" // wifi header only needed to turn it off


// multipexer select pins
//#define MULTIPLEXED_ANALOG_INPUT A0
//#define MUX_A D0
//#define MUX_B D1
//#define MUX_C D2
//#define DEBUG_SERIAL


WiFiUDP Udp;

 AnalogMultiplexerPin multiplexer;
 SynthManager syntManager;
 OSCBundleReader oscBundleReader = OSCBundleReader(&Udp, OSC_VCV_LEMUR);;


void setup() {

  system_update_cpu_freq(160);
#ifdef DEBUG_SERIAL
  Serial.begin(115200);
#endif

  WiFi.begin("RUMAH", "rumah4321");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  pinMode(2, INPUT); //restore GPIOs taken by i2s
  pinMode(15, INPUT);

//   multiplexer.setup(MUX_A, MUX_B, MUX_C, MULTIPLEXED_ANALOG_INPUT);

  syntManager.attachOscReader(&oscBundleReader);
  syntManager.attachMultiplexer(&multiplexer);
  syntManager.addSynth(new SynthTest());

#ifdef DEBUG_SERIAL
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
#endif

  Udp.begin(8888);
}

void loop() {
  syntManager.run();
}
