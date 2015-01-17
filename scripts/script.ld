ENTRY(start32)
OUTPUT_FORMAT(elf32-i386)
OUTPUT_ARCH(i386)

page_size = 4K;
kernel_start = 1M;

SECTIONS
{
	/* Memory mapped VGA textmode */
	.vga : ALIGN(PAGE_SIZE) {
		
	}

	/* Kernel and 
	. = kernel_start;
	.text : ALIGN(PAGE_SIZE)
	{
		*(.multiboot)
		*(.text)
	}
	kernel_end = .;

	/* Read-only data. */
	.rodata : ALIGN(PAGE_SIZE)
	{
		*(.rodata)
	}

	/* Read-write data (initialized) */
	.data : ALIGN(PAGE_SIZE)
	{
		*(.data)
	}

	/* Read-write data (uninitialized) and stack */
	.bss : ALIGN(PAGE_SIZE)
	{
		*(COMMON)
		*(.bss)
		*(.stack)
	}

	/* We do not need stack unwinding information */
	/DISCARD/ :
	{
		*(.eh_frame)
		*(.eh_frame_hdr)
	}
}

