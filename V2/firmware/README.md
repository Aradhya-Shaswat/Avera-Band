# firmware

hi! this folder contains the firmware for the avera band.

there are currently two separate projects here. one is for the actual v2 band, which uses the xiao esp32-c3, and the other is a small development setup using an arduino uno and a dht11 temperature and humidity sensor.

## xiao esp32-c3

this is the main firmware for avera v2.

the xiao handles communication with the sensors and will eventually take care of collecting, processing and sending the data.

the sensors connected to it are:

- max30102 for heart rate and spo2
- adxl345 for movement and acceleration
- tmp117 for temperature
- max17048 for battery monitoring

since i don't have access to it's hardware, the firmware for now is incomplete.

## arduino uno

this is a separate development setup that i made while working on avera-console.

it uses an arduino uno with a dht11 sensor to read temperature and humidity. the readings are sent to the computer over usb serial, where avera-console can receive them.

this is mainly for testing the software interface without having to wait for the actual wearable hardware.

## how to upload

for the xiao esp32-c3:

1. install vs code and the platformio extension.
2. open the `xiao_esp32c3` folder.
3. make sure the platformio configuration file is named `platformio.ini`.
4. connect the xiao using usb-c.
5. build and upload the firmware through platformio.

for the arduino uno:

1. open `uno_env_dev.ino` in arduino ide.
2. install the dht sensor (adafruit!) library.
3. connect the arduino uno using usb.
4. select the correct board and port.
5. compile and upload the sketch.

## current status

the firmware is still a work in progress. the arduino uno setup is being used for development and testing, while the xiao firmware is being prepared for the v2 hardware.

the actual sensor readings and communication will need to be tested once the pcb has been manufactured and assembled.

i'll keep adding things here as i work on the firmware.