
#include "gdt.h"

struct gdt_desc gdt[] = {
	{ 0 },                                             /* NULL descriptor */
	{ .type = 10, .s = 1, .p = 1, .dpl = 0, .lm = 1 }, /* Kernel Code */
	{ .type =  2, .s = 1, .p = 1, .dpl = 0, .lm = 1 }  /* Kernel Data */
};
