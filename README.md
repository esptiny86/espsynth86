# espsynth86

![](https://i.imgur.com/vtGG80q.png)

Synth engine for esptiny86. this module is largely based on MicrobeModular's Equation Composer ported to esp8266 with full featured Audio Design tool https://esptiny86.github.io/espnode86

![](https://i.imgur.com/olUcqB0.png)

# Compiling

* Open and configure "Makefile" file, then on command prompt/terminal type Make
    - Nodemcu Lolin use BOARD = nodemcu
    - Wemos D1 use BOARD = d1_mini
* Qt Creator is optional but it is recommended for developing further with espsynth86

# Components

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


# Support

* Donation is highly appreciated https://www.patreon.com/badgeek

# Credits

* Esp8266 Summer Audio hacking by Jan Ostman - http://blog.dspsynth.eu/audio-hacking-on-the-esp8266-2/
* MicrobeModular Equation Composer - https://github.com/clone45/EquationComposer
* Esp8266 Audio - https://github.com/earlephilhower/ESP8266Audio
* Bitluni Wavetable Editor - http://bitluni.net
* TinySynth - http://www.technoblogy.com/show?Q7H
