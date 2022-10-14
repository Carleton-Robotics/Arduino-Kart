# Arduino-Kart

## How do I write code for this project?
* Install `arduino-cli` and add to path (https://github.com/arduino/arduino-cli)
* Run `arduino-cli core install arduino:avr`
* Install the following libraries with `arduino-cli lib install <libname>`
  * MCP45HVX1
  * "SparkFun u-blox GNSS Arduino Library"
  * "Adafruit BluefruitLE nRF51"
  * SD
  * LinkedList
  * "Adafruit Unified Sensor"
* Plug in Arduino, run `arduino-cli board list` to find port name of connected board
* Write whatever code you want
* Go to `KartControl` dir and run: `arduino-cli compile && arduino-cli upload --fqbn arduino:avr:mega -p <port name> && arduino-cli monitor --config baudrate=115200 -p <port name>`, replacing `<port name>` with the name of the port that it is connected to. This will compile and upload the code to the Arduino, then watch the serial connection to get terminal output.
