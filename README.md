# Fortuna Connector

This is a connector that plugs a Raspberry Pi to a board, and can be used to:
 - Have a Raspberry Pi programming multiple microcontroller types in the board (AVR, ARM, etc.)
 - Debug protocols in the board using the Raspberry Pi (UART, SPI, I²C, SWD)

The connector contains:
 - A female header to connect to the Raspberry Pi GPIOs
 - A male header to connect the Raspberry Pi to the board using a flat cable.
 - A male and female header to help debug any problems in communication (for example, using a digital analyzer)
 - A button to turn on/off power from the Pi to the board.
 - LEDs indicating power and activity in the protocols.

## Photos

![Photo 2](photos/connector2.jpg)

![Photo 1](photos/connector1.jpg)
With the Raspberry Pi attached

## Main connector pinout

Left side

| Pin | Type  | Classification | Pin in RPI | # pin in RPI |
|-----|-------|----------------|------------|--------------|
|  1  | 5V    | Power          | 5V         | 2, 4  |
|  3  | SDA   | I²C            | SDA        | 3     |
|  5  | SCL   | I²C            | SCL        | 5     |
|  7  | GPIO  | GPIO           | GPIO4      | 7     |
|  9  | MOSI  | SPI            | MOSI       | 19    |
| 11  | MISO  | SPI            | MISO       | 21    |
| 13  | SCK   | SPI            | SCK        | 23    |
| 15  | CS0   | SPI            | CE0        | 24    |

Right side (notch)

| Pin | Type  | Classification | Pin in RPI | # pin in RPI |
|-----|-------|----------------|------------|--------------|
|  2  | 3.3V  | Power          | 3.3V       | 1, 17 |
|  4  | RX    | Serial         | TXD        | 10    |
|  6  | TX    | Serial         | RDX        | 8     |
|  8  | SWIO  | SWD            | GPIO24     | 18    |
| 10  | SWCLK | SWD            | GPIO25     | 22    |
| 12  | CS1   | SPI            | CE1        | 26    |
| 14  | RST   | SPI            | GPIO12     | 32    |
| 16  | GND   | Power          | GND        | 6, 9, 14, 25, 30, 34, 39 |

`GPIO` can be used as a generic pin to get information from the board to the PI or vice-versa. `CS0`, `CS1` and `RST` can be used to activate SPI on either side, or as generic pins.

## Schematic

![Schematic](schematic.png)

## Software

The following additional software is available in the repository folders. Everything is meant to run from the Pi.

- **test-leds**: will blink all LEDs on the connector. Needs to be run with `sudo`.
- **avr-skeleton**: `avrdude` configuration and sample project to program an AVR. Change the AVR type on the `Makefile`. (TBD)
- **arm-skeleton**: an example project to program an ARM Cortex-M microcontroller. (TBD)

The Makefile needs to be configured to choose the correct MCU, speed, etc... along with the reset line that is being used (for AVR). The following `make` commands are available:

- `make`: compile source code
- `make size`: print size of executable generated for the MCU
- `make test-connection`: test if communication with the MCU is working
- `make fuse`: program fuses (AVR only)
- `make upload`: upload executable to the MCU
- `make talk`: opens a serial connection from the computer to the MCU
- `make clean`: delete the intermediate files generated

A program called `reset` is also made available that simply resets the MCU. The source might need to be editted to set the correct reset line.
