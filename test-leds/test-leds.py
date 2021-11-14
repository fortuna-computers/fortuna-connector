#!/usr/bin/env python

import atexit
import time
import RPi.GPIO as GPIO
from itertools import cycle

SDA  = 2
MOSI = 10
MISO = 9
SWIO = 24
RX   = 15
TX   = 14

PINS = [SDA, MOSI, MISO, SWIO, RX, TX]

@atexit.register
def cleanup():
    GPIO.cleanup()

GPIO.setmode(GPIO.BCM)

for pin in PINS:
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, GPIO.HIGH)

previous = None
for pin in cycle(PINS):
    if previous:
        GPIO.output(previous, GPIO.HIGH)
    GPIO.output(pin, GPIO.LOW)
    previous = pin
    time.sleep(0.2)
