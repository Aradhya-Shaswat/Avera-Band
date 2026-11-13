# design decisions

this document contains some of the decisions i made while working on avera v2 and why i went with them.

## why a custom pcb?

initially, i was working with individual breakout boards.

they are much easier to get started with, but once i started thinking about the actual size of the armband, i realised that putting all those modules together would make the enclosure unnecessarily large.

so i decided to try designing a custom pcb with the individual ICs instead.

## why the xiao esp32-c3?

i went with the seeed xiao esp32-c3 as the main controller.

it is compact, has usb-c, supports wireless connectivity and gives me the pins and interfaces needed for the sensors.

using the xiao also means i don't have to design the entire microcontroller circuit from scratch.

## why these sensors?

i chose the components based on what i wanted the band to measure.

- **max30102:** for heart rate and blood oxygen.
- **adxl345:** for movement and acceleration.
- **tmp117:** for temperature measurements.
- **max17048:** to keep track of the battery level.

i also added a tps7a2018 regulator to provide the 1.8v supply required by the max30102.

## why a screenless design?

i didn't really see the need for a display on the band itself (istg i'm not copying whoop!!).

the idea is to keep the device small and let the companion software handle the data and visualisation.

## why two hardware approaches?

i'm keeping v1.5 and v2 separate because they solve the same problem in different ways.

v1.5 uses ready-made breakout boards and is intended for diy assembly.

v2 uses a custom pcb and is intended for jlcpcb fabrication and smt assembly.

this gives me two ways to approach the project depending on the manufacturing cost and availability of components.

## enclosure

the enclosure is being designed in blender.

i had to consider the size of the pcb, battery, sensor openings and how everything would fit against the wrist. the placement of the optical sensor is especially important because it needs to sit properly against the skin.

## what's next?

most of these decisions are based on the digital design. i'll know much more once the actual pcb is manufactured and assembled.

there may be changes after testing, especially with the enclosure, battery life and sensor performance.