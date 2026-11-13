# v2 hardware overview

hi! this document explains the electronics used in avera v2 and how everything is connected.

v2 uses a single custom pcb instead of connecting individual sensor breakout boards together.

the main controller is the seeed xiao esp32-c3.

## components

| component | what it does |
|---|---|
| xiao esp32-c3 | controls the device |
| max30102 | reads heart rate and blood oxygen |
| adxl345 | detects movement and acceleration |
| tmp117 | measures temperature |
| max17048 | monitors the battery |
| tps7a2018 | provides a 1.8v supply for the max30102 |
| rgb led | basic status indication |

there are also resistors, capacitors, connectors and other supporting components on the board.

## sensor connections

the max30102, adxl345, tmp117 and max17048 share the i2c communication lines.

the xiao communicates with these components and reads their respective sensor data.

the current i2c addresses are:

- max30102: `0x57`
- adxl345: `0x53`
- tmp117: `0x48`
- max17048: `0x36`

## power

the device is designed to use a single-cell 3.7v lipo battery.

the battery connects through a 2-pin connector. charging is intended to happen through the usb-c port on the xiao esp32-c3, using its onboard charging circuit.

the tps7a2018 provides the 1.8v supply needed by the max30102.

## rgb led

there is a 4-pin rgb led on the board.

it has separate red, green and blue connections, which the controller can use to indicate different device states.

## pcb

the v2 pcb brings all these components together on one board.

the design was made in easyeda pro. the pcb source, schematic, gerbers, 3d model and assembly files are available in the hardware folder.

## notes

this is the current digital design. the board has not yet been manufactured and tested, so the actual electrical behaviour and sensor performance still need to be verified.

some connections or component choices may change during testing.