
#ifndef _IDT_H_
#define _IDT_H_

struct idt_gate {
	unsigned offset1	: 16;	/* first dword */
	unsigned selector	: 16;
	unsigned ist		: 3;	/* second dword */
	unsigned _reserved1	: 8;
	unsigned type		: 5;
	unsigned dpl		: 2;
	unsigned present	: 1;
	unsigned offset2	: 16;

	unsigned offset3	: 32;	/* third dword */
	unsigned _reserved2	: 32;	/* fourth dword */
} __attribute__((packed));

#endif

