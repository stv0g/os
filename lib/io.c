
#include <config.h>

#include <lib/io.h>

void kputs(char *str)
{
	while (*str) {
		kputc(*str++);
	}
}

void kputc(char chr)
{
#ifdef CONFIG_VGA
	vga_putc(chr);
#endif

#ifdef CONFIG_UART
	uart_putc(chr);
#endif
}
