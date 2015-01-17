#ifndef _VGA_H_
#define _VGA_H_

#define VGA_ADDRESS	0xB8000

#define VGA_LINES	25
#define VGA_COLUMNS	80

#define VGA_BLANK	0x0000

/* Hardware text mode color constants. */
enum vga_color
{
	COLOR_BLACK		= 0,
	COLOR_BLUE		= 1,
	COLOR_GREEN		= 2,
	COLOR_CYAN		= 3,
	COLOR_RED		= 4,
	COLOR_MAGENTA		= 5,
	COLOR_BROWN		= 6,
	COLOR_LIGHT_GREY	= 7,
	COLOR_DARK_GREY		= 8,
	COLOR_LIGHT_BLUE	= 9,
	COLOR_LIGHT_GREEN	= 10,
	COLOR_LIGHT_CYAN	= 11,
	COLOR_LIGHT_RED		= 12,
	COLOR_LIGHT_MAGENTA	= 13,
	COLOR_LIGHT_BROWN	= 14,
	COLOR_WHITE		= 15,
};

struct vga_char {
	char chr;
	struct vga_attribs {
		enum vga_color fg : 4;
		enum vga_color bg : 4;
	} attr;
};

void vga_init();

void vga_clear();

void vga_putc(char chr);

void vga_move(int line, int column);

void vga_color(enum vga_color fg, enum vga_color bg);

void vga_scroll();

#endif /* _VGA_H_ */
