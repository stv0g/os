#ifndef _UART_H_
#define _UART_H_

int uart_init();

void uart_putc(char c);
char uart_getc();

#endif /* _UART_H_ */
