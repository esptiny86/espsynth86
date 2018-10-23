# espsynth86

![](https://i.imgur.com/vtGG80q.png)

Synth engine for esptiny86. this module is largely based on MicrobeModular's Equation Composer ported to esp8266 with full featured Audio Design tool https://esptiny86.github.io/espnode86

![](https://i.imgur.com/olUcqB0.png)

# How To install (For user)

* Make sure your Arduino Ide at version 1.8.6 or more
* Add https://esptiny86.github.io/espboard8266/package_espsynth_index.json to board url on Arduino preferences
* Install Espsynth86 from board manager
* Download Espsynth library latest version from https://github.com/esptiny86/espboard8266/tree/master/library then install to Arduino > Sketch > Include Library > Add Zip file
* Choose ESPSYNTH Modules from Tools > Board > ESPSYNTH Module > Wemos D1 etc..
* Open example sketch

# Boards

### esptiny86 Stompbox design by @Dusjagr

![](https://i.imgur.com/BZcPQyX.png)

# Hardware

There are two methods for generating sound with ESP8266

* PDM - Pulse Density Modulation

  ![](https://janostman.files.wordpress.com/2017/07/pdm-lpf.jpg?w=525)

* DAC - Digital Analog Converter (tested with PT8211)

  ![](https://i.imgur.com/83EcOqN.png)

To choose between mode uncomment in synthmodule86.ino file

```
define USE_PDM
```

# Audio design Tools

* Inspired by Teensy, design tool is also available https://esptiny86.github.io/espnode86

# Tips

### NeoPixelBus (works well with esp8266)

https://github.com/Makuna/NeoPixelBus

```

//declare
NeoPixelBus<NeoRgbFeature, NeoEsp8266BitBang400KbpsMethod> neoPixel(NEO_NUM_LEDS, NEO_DATA_PIN);
RgbColor green(0, 128, 0);

//setup
neoPixel.Begin();
neoPixel.Show();

//update
neoPixel.SetPixelColor(i, green);

```

### Fix clicking sound

```

#include "ESP8266WiFi.h" // wifi header only needed to turn it off

void setup() {
    WiFi.forceSleepBegin(); // turn of wifi to reduce power consumption
}

```

# Compiling (for developer)

* Install Arduino IDE then install esp8266 from board library
* Open and configure "Makefile" file, then on command prompt/terminal type Make (the Makefile will auto discover your Arduino IDE and Libs))
    - Nodemcu Lolin use BOARD = nodemcu
    - Wemos D1 use BOARD = d1_mini
* Qt Creator is optional but it is recommended for developing further with espsynth86
* Edit project.include to your pathto get Intelisense in QT Creator

# Compiling (for developer) (library version)

* Install Arduino IDE then install esp8266 from board library
* Open and configure "Makefile" file, then on command prompt/terminal type Make (the Makefile will auto discover your Arduino IDE and Libs))
    - Nodemcu Lolin use BOARD = nodemcu
    - Wemos D1 use BOARD = d1_mini
* Qt Creator is optional but it is recommended for developing further with espsynth86
* Edit project.include to your pathto get Intelisense in QT Creator
* sh build_lib.sh

# Support

* This project is developed independently and without any connection to funding or big organization, Donation is highly appreciated https://www.patreon.com/badgeek

# Credits

* MicrobeModular Equation Composer - https://github.com/clone45/EquationComposer
* MakeEspArduino - https://github.com/plerup/makeEspArduino
* RPD (Reactive Patch Development) - http://shamansir.github.io/rpd/
* Bitluni Wavetable Editor - http://bitluni.net
* TinySynth - http://www.technoblogy.com/show?Q7H
* Esp8266 Summer Audio hacking by Jan Ostman - http://blog.dspsynth.eu/audio-hacking-on-the-esp8266-2/
* Esp8266 Audio - https://github.com/earlephilhower/ESP8266Audio
