
#include <config.h>

#include <lib/int.h>
#include <vga.h>

static struct vga_attribs attribs;
static struct vga_char *cursor;
const  struct vga_char screen[VGA_LINES][VGA_COLUMNS] __attribute__ ((section(".vga")));

void vga_init()
{
	vga_clear();
	vga_move(0, 0);
}

void vga_move(int l, int c)
{
	cursor = &screen[l][c];
}

void vga_color(enum vga_color fg, enum vga_color bg) {
		attribs.fg = fg;
		attribs.bg = bg;
}

void vga_putc(char chr)
{
	cursor->chr = chr;
	cursor->attr = attribs;
	cursor++;
}

void vga_clear()
{
	memset(screen, 0, sizeof(screen));
}

void vga_scroll()
{
	for (int l = 1; l < VGA_LINES; l++) {
		memcpy(&screen[l-1], &screen[l], VGA_COLUMNS * sizeof(struct vga_char));
	}

	memset(screen[VGA_LINES-1], 0, VGA_COLUMNS * sizeof(struct vga_char)):
}
