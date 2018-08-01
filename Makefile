# Parameters for compiling

#some things that you could use
#  SKETCH               Main source file
#                         If not specified the first sketch in current
#                         directory will be used. If none is found there,
#                         a demo example will be used instead.
#  LIBS                   Includes in the sketch file of libraries from within
#                         the ESP Arduino directories are automatically
#                         detected. If this is not enough, define this
#                         variable with all libraries or directories needed.
#  CHIP                 Set to esp8266 or esp32.
#  BOARD                Name of the target board.
#  FLASH_DEF            Flash partitioning info.
#  BUILD_DIR            Directory for intermediate build files.
#  BUILD_EXTRA_FLAGS    Additional parameters for the compilation commands
#  FS_DIR               File system root directory
#  UPLOAD_PORT          Serial flashing port name.
#  UPLOAD_SPEED         Serial flashing baud rate.
#  FLASH_FILE           File name for dump and restore flash operations
#  VERBOSE              Set to 1 to get full printout of the build
#  SINGLE_THREAD        Use only one build thread

#this is all I need at the moment
CHIP = esp8266
BOARD = d1_mini
#UPLOAD_SPEED = 921600
UPLOAD_PORT = /dev/cu.wchusbserial1a1240
VERBOSE = 1
ESP_ADDR =  192.168.1.102
FLASH_FILE=test.bin
#ESP_PORT = 8266
#ESP_PWD = 123

# makeEspArduino makefile
include makeEspArduino.mk
