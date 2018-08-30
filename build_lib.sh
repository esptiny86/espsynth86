COMPILE_PATH=build
AR_PATH=/Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar

mkdir -p ./src/esp8266

rm -fr ./src/esp8266/libespsynth86.a

rm -fr ./src/*.h

cp ./lib/*.h src

make

cd lib

LIB_FILES=`ls *.cpp | while read f; do echo ${COMPILE_PATH}/${f}.o; done;`

cd ..

${AR_PATH} rvs ./src/esp8266/libespsynth86.a ${LIB_FILES}


# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Global*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Defines*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Analog*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Audio*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Euclid*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Expr*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Neo*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Vector*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Equation*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Fixed*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Input*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Module*.o
# /Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin/xtensa-lx106-elf-ar rvs espsynth86.a /tmp/mkESP/synthmodule86_d1_mini/Synth*.o

