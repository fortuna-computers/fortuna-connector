Pins:

| Pin | Type  | Classification | Pin in RPI | # pin in RPI |
|-----|-------|----------------|------------|--------------|
|  1  | 5V    | Power          | 5V         | 2, 4  |
|  2  | 3.3V  | Power          | 3.3V       | 1, 17 |
|  3  | SDA   | I²C            | SDA        | 3     |
|  4  | SCL   | I²C            | SCL        | 5     |
|  5  | SWIO  | SWD            | GPIO24     | 18    |
|  6  | SWCLK | SWD            | GPIO25     | 22    |
|  7  | MOSI  | SPI            | MOSI       | 19    |
|  8  | MISO  | SPI            | MISO       | 21    |
|  9  | SCK   | SPI            | SCK        | 23    |
| 10  | CS0   | SPI            | CE0        | 24    |
| 11  | CS1   | SPI            | CE1        | 26    |
| 12  | CS2   | SPI            | GPIO28     | 28    |
| 13  | RX    | Serial         | TXD        | 10    |
| 14  | TX    | Serial         | RDX        | 8     |
| 15  | GPIO  | GPIO           | GPIO4      | 7     |
| 16  | GND   | Power          | GND        | 6, 9, 14, 25, 30, 34, 39 |

Additional:

- On/off switch (on GND)
- Lights:
  - Power
  - RX
  - TX
  - MOSI
  - MISO
  - SWIO
  - SDA
  - GPIO

- Export pins:
  - All data pins
  - GND

- Glue instructions in adapter
