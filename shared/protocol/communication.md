# communication

this document contains a quick overview of how the different parts of avera communicate with each other.

there are a few different connections involved, depending on which hardware version is being used.

## v2 hardware

the xiao esp32-c3 is the main controller for v2.

the sensors communicate with the controller through i2c. this allows multiple sensors to share the same two communication lines.

the current i2c addresses are:

| component | address |
|---|---|
| max30102 | 0x57 |
| adxl345 | 0x53 |
| tmp117 | 0x48 |
| max17048 | 0x36 |

the xiao handles communication with these sensors and will process their readings through the firmware.

## arduino uno development setup

the separate arduino uno setup uses usb serial communication.

the uno reads the dht11 sensor and sends its readings to the computer. avera-console receives this data through the serial connection.

this is mainly being used to test the web interface.

## avera-console

avera-console is maintained in a separate repository.

it is the software side of the project and will eventually be used to view and work with the data collected by the band.

## notes

the exact communication methods and data formats may change as development continues.

currently, the uno serial setup and the v2 sensor connections are documented separately because they serve different purposes.