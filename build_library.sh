#!/bin/bash

#
# 	Folder Structure
#
# 	COMPILE_PATH = make build result
#	LIBRARY_PATH = lib build result
# 	SOURCE_PATH = Actual Library Source Code
#

COMPILE_PATH=build
SOURCE_PATH=src
LIBRARY_VERSION_TAG=`git describe --tag`
LIBRARY_PATH=./library/espsynth86-${LIBRARY_VERSION_TAG}
LIBRARY_SRC_PATH=${LIBRARY_PATH}/src
PRECOMPILED_PATH=${LIBRARY_SRC_PATH}/esp8266

ESPTOOL_PATH=/Users/xcorex/Library/Arduino15/packages/esp8266/tools/xtensa-lx106-elf-gcc/1.20.0-26-gb404fb9-2/bin
AR_PATH=$ESPTOOL_PATH/xtensa-lx106-elf-ar

rm -fr ${LIBRARY_PATH}

mkdir -p ${LIBRARY_PATH}
mkdir -p ${LIBRARY_SRC_PATH}
mkdir -p ${PRECOMPILED_PATH}

#Copy header file to library
cp ./$SOURCE_PATH/*.h $LIBRARY_SRC_PATH
cp ./library.json $LIBRARY_PATH
cp ./library.properties $LIBRARY_PATH

#Build Sketch
make

cd $SOURCE_PATH
LIB_FILES=`ls *.cpp | while read f; do echo ${COMPILE_PATH}/${f}.o; done;`
cd ..

${AR_PATH} rvs $PRECOMPILED_PATH/libespsynth86.a ${LIB_FILES}

tar -czvf ${LIBRARY_PATH}.tar.gz ${LIBRARY_PATH}

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

