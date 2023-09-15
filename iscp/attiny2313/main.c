#include <stdio.h>

#include <avr/pgmspace.h>
#include <util/delay.h>

#include "uart.h"

int main(void)
{
    uart_init();
    for (;;) {
        puts_P(PSTR("Hello world!"));
        _delay_ms(50);
    }
    return 0;
}
