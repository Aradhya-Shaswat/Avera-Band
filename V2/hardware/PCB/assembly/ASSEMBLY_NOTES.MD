# avera v2 - assembly notes

hi! this folder contains the assembly files for the v2 pcb.

the board is designed in easyeda and is intended to be manufactured and assembled through jlcpcb.

## files

**1. top side**

![avera v2 top](AVERA_V2_TOP.PNG)

this shows the component placement on the top side of the pcb.

**2. bottom side**

![avera v2 bottom](AVERA_V2_BOTTOM.PNG)

this shows the component placement on the bottom side.

**3. pick and place file**

`AVERA_V2_PL.csv`

this file contains the component placement information, including their positions and rotations. it is used by the assembly service to place the components on the pcb.

## assembly

the plan is to get as many smt components assembled by jlcpcb as possible. components that cannot be assembled through their service will be soldered manually.

please refer to the v2 jlcpcb bom and the pick and place file together when preparing the assembly.

make sure to check component orientation, especially for the ICs, rgb led and other polarity-sensitive components.

## notes

this is currently a design-stage assembly package. the board hasn't been manufactured or physically tested yet.

some components may need to be assembled manually depending on availability and jlcpcb's assembly support.