
#ifndef _GDT_H_
#define _GDT_H_

struct gdt_ptr
{
	unsigned short limit;
	unsigned int base;
} __attribute__((packed));

struct gdt_desc
{
	unsigned limit1		: 16;
	unsigned base1		: 16;
	unsigned base2		: 8;
	unsigned type		: 4;
	unsigned s		: 1;
	unsigned dpl		: 1;
	unsigned p		: 1;
	unsigned limit2		: 4;
	unsigned avl		: 1;
	unsigned lm		: 1;
	unsigned d_b		: 1;
	unsigned g		: 1;
	unsigned base2		: 8;
} __attribute__((packed));

#endif /* _GDT_H_ */
