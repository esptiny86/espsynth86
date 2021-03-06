#!/bin/bash

CWD=`pwd`

ARDUINO_JAVA=/Applications/Arduino.app/Contents/Java
ARDUINO_15=/Users/xcorex/Library/Arduino15
ARDUINO_HARDWARE_FOLDER=/Users/xcorex/Documents/Arduino/hardware
BUILD_CACHE=$CWD/build-cache
BUILD_DIR=$CWD/build-dir
BUILD_SRC=$CWD/synthmodule86/synthmodule86.ino

ARDUINO_FQBN=esp8266:esp8266:d1_mini:xtal=80,vt=flash,exception=disabled,eesz=4M,ip=lm2f,dbg=Disabled,lvl=None____,wipe=none,baud=921600
ESPTOOL_PATH=$ARDUINO_15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-3-20ed2b9/bin
AR_PATH=$ESPTOOL_PATH/xtensa-lx106-elf-ar

COMPILED_PATH=$CWD/build-dir/libraries/src

LIBRARY_VERSION_TAG=`git describe --tag`

LIBRARY_PATH=./library/espsynth86-${LIBRARY_VERSION_TAG}
LIBRARY_BUILD_NAME=espsynth86-${LIBRARY_VERSION_TAG}
LIBRARY_SRC_PATH=${LIBRARY_PATH}/src
PRECOMPILED_PATH=${LIBRARY_SRC_PATH}/esp8266
SOURCE_PATH=src

ARDUINO_LIBRARY_PATH=$CWD:$CWD/external

rm -fr ${LIBRARY_PATH}

mkdir -p ${LIBRARY_PATH}
mkdir -p ${LIBRARY_SRC_PATH}
mkdir -p ${PRECOMPILED_PATH}

mkdir -p $BUILD_DIR
mkdir -p $BUILD_CACHE

cp ./$SOURCE_PATH/*.h $LIBRARY_SRC_PATH
cp -r ./examples $LIBRARY_PATH
cp ./library.json $LIBRARY_PATH
cp ./library.properties $LIBRARY_PATH

git submodule update --init

$ARDUINO_JAVA/arduino-builder -compile -logger=machine -hardware $ARDUINO_JAVA/hardware -hardware $ARDUINO_15/packages -hardware $ARDUINO_HARDWARE_FOLDER -tools $ARDUINO_JAVA/tools-builder -tools $ARDUINO_JAVA/hardware/tools/avr -tools $ARDUINO_15/packages -built-in-libraries $ARDUINO_JAVA/libraries -libraries $ARDUINO_LIBRARY_PATH -fqbn=$ARDUINO_FQBN -ide-version=10808 -build-path $BUILD_DIR -warnings=none -build-cache $BUILD_CACHE -prefs=build.warn_data_percentage=75 -prefs=runtime.tools.esptool.path=$ARDUINO_15/packages/esp8266/tools/esptool/2.5.0-3-20ed2b9 -prefs=runtime.tools.esptool-2.5.0-3-20ed2b9.path=$ARDUINO_15/packages/esp8266/tools/esptool/2.5.0-3-20ed2b9 -prefs=runtime.tools.xtensa-lx106-elf-gcc.path=$ARDUINO_15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-3-20ed2b9 -prefs=runtime.tools.xtensa-lx106-elf-gcc-2.5.0-3-20ed2b9.path=$ARDUINO_15/packages/esp8266/tools/xtensa-lx106-elf-gcc/2.5.0-3-20ed2b9 -prefs=runtime.tools.mkspiffs.path=$ARDUINO_15/packages/esp8266/tools/mkspiffs/2.5.0-3-20ed2b9 -prefs=runtime.tools.mkspiffs-2.5.0-3-20ed2b9.path=$ARDUINO_15/packages/esp8266/tools/mkspiffs/2.5.0-3-20ed2b9 -verbose $BUILD_SRC



cd $COMPILED_PATH
# LIB_FILES=`ls *.cpp.o | while read f; do echo ${COMPILE_PATH}/${f}; done;`
${AR_PATH} rvs libespsynth86.a *.o
mv libespsynth86.a $CWD/$PRECOMPILED_PATH
cd $CWD

echo $COMPILED_PATH
echo $LIB_FILES


cp ./external/*/src/* $LIBRARY_SRC_PATH 

rm -fr ${LIBRARY_PATH}.zip

cd library

zip -r ${LIBRARY_BUILD_NAME}.zip ${LIBRARY_BUILD_NAME}