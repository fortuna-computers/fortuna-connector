#include <stdio.h>

#include <avr/pgmspace.h>

#include "uart.h"

int main(void)
{
    uart_init();
    puts_P(PSTR("Hello world!"));
    return 0;
}
