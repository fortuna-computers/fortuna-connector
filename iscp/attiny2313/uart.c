#include <stdio.h>

#include <avr/io.h>
#include <util/delay.h>
#include <util/setbaud.h>

static int uart_putchar(char c, FILE* f)
{
    (void) f;

    if (c == '\n')
        uart_putchar('\r', f);
    loop_until_bit_is_set(UCSRA, UDRE);
    UDR = c;
    return 0;
}

static int uart_getchar(FILE* f)
{
    (void) f;

    loop_until_bit_is_set(UCSRA, RXC);
    return UDR;
}

void uart_init(void)
{
    _delay_ms(100);
    
    // set speed
    UBRRH = UBRRH_VALUE;
    UBRRL = UBRRL_VALUE;

    // set config
    UCSRC = (1<<USBS) | (1<<UCSZ1) | (1<<UCSZ0);   // Async-mode 
    UCSRB = (1<<RXEN) | (1<<TXEN);     // Enable Receiver and Transmitter

    static FILE uart = FDEV_SETUP_STREAM(uart_putchar, uart_getchar, _FDEV_SETUP_RW);
    stdin = stdout = &uart;

    _delay_ms(100);
}
