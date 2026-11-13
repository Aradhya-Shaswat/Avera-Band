# data format

this document describes how sensor readings are named and stored across avera.

i want to keep the names and units consistent so that the hardware and avera-console can work with the same kind of data.

## sensor readings

these are the main values used by the project:

| name | description | unit |
|---|---|---|
| heart_rate | heart rate | bpm |
| spo2 | blood oxygen level | % |
| temperature | temperature reading | °c |
| battery | remaining battery level | % |
| acceleration_x | movement along x axis | g |
| acceleration_y | movement along y axis | g |
| acceleration_z | movement along z axis | g |
| humidity | relative humidity from dht11 | % |

not every value is available from every hardware version. for example, humidity is currently part of the arduino uno development setup, not the v2 sensor list.

## example

a sensor reading could be represented like this:

```json
{
  "heart_rate": 75,
  "spo2": 98,
  "temperature": 33.2,
  "battery": 85
}
```

this is an example of the data structure i'm working towards. it is not a guarantee that every firmware version currently sends this exact format.

## notes

- temperature values should be represented in degrees celsius.
- heart rate should be represented in beats per minute.
- spo2 should be represented as a percentage.
- battery should be represented as a percentage.
- acceleration values should use g as the unit.

the format may change as i work on the firmware and software. any changes should also be reflected in the serial protocol and the console.