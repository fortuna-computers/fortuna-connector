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

# ISCP programmer

## Photos

![image](https://github.com/fortuna-computers/fortuna-connector/assets/84652/fd7043c8-1064-4048-8482-0788b9015783)

## Main connector pinout

Top side

| Pin | Type  | Classification | Pin in RPI    | # pin in RPI |
|-----|-------|----------------|---------------|--------------|
|  1  | MOSI  | SPI            | MOSI (GPIO10) | 19    |
|  2  | RX    | Serial         | RDX           | 10    |
|  3  | RST   | SPI            | GPIO1         | 28    |
|  4  | SCK   | SPI            | SCK (GPIO11)  | 23    |
|  5  | MISO  | SPI            | MISO (GPIO9)  | 21    |

Bottom side (notch)

| Pin     | Type  | Classification | Pin in RPI | # pin in RPI |
|---------|-------|----------------|------------|--------------|
| 6, 7, 8 | GND   | Power          | GND        | 6, 9, 14, 25, 30, 34, 39 |
| 9       | TX    | Serial         | TDX        | 8     |
| 10      | VCC   | Power          | 5V or 3V3  | 2, 4  |


## Schematic

![image](https://github.com/fortuna-computers/fortuna-connector/assets/84652/d8dc8fab-c7f2-4f68-a59c-c260047b7f6e)

## Software

A few sample project skeletons are provided in the package.

The Makefile needs to be configured to choose the correct MCU, speed, etc.. The following `make` commands are available:

- `make`: compile source code
- `make size`: print size of executable generated for the MCU
- `make test-connection`: test if communication with the MCU is working
- `make fuse`: program fuses (AVR only)
- `make upload`: upload executable to the MCU
- `make talk`: opens a serial connection from the computer to the MCU
- `make clean`: delete the intermediate files generated

A program called `reset` is also made available that simply resets the MCU.
