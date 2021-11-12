# fortuna-connector
Connector used to program the firmware in the Fortuna Computers from a Raspberry Pi.

Pins:

| Pin | Type  | Classification | Pin in RPI | # pin in RPI |
|-----|-------|----------------|------------|--------------|
|  1  | 5V    | Power          | 5V         | 2, 4  |
|  2  | 3.3V  | Power          | 3.3V       | 1, 17 |
| 16  | GND   | Power          | GND        | 6, 9, 14, 25, 30, 34, 39 |
|  3  | SDA   | I²C            | SDA        | 3     |
|  5  | SCL   | I²C            | SCL        | 5     |
|  7  | GPIO  | GPIO           | GPIO4      | 7     |
|  8  | SWIO  | SWD            | GPIO24     | 18    |
| 10  | SWCLK | SWD            | GPIO25     | 22    |
|  9  | MOSI  | SPI            | MOSI       | 19    |
| 11  | MISO  | SPI            | MISO       | 21    |
| 13  | SCK   | SPI            | SCK        | 23    |
| 15  | CS0   | SPI            | CE0        | 24    |
| 12  | CS1   | SPI            | CE1        | 26    |
| 14  | CS2   | SPI            | GPIO28     | 28    |
| 14  | RX    | Serial         | TXD        | 10    |
| 16  | TX    | Serial         | RDX        | 8     |

Schematic:

[Schematic](Schematic_fortuna-connector_2021-11-12.png)
