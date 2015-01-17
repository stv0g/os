%include "config.inc"
%include "multiboot.inc"

SECTION .data


SECTION .stack
align 4

stack_bottom:
	times STACK_SIZE db 0
stack_top:

; Every Multiboot compliant image starts
; with the multiboot header
SECTION .multiboot
align 4
	dd MULTIBOOT_HEADER_MAGIC
	dd MULTIBOOT_HEADER_FLAGS
	dd MULTIBOOT_CHECKSUM

[BITS 32]
SECTION .text
	global _start
	extern main

; Everything starts here
_start:
start32:

	mov esp, stack_top

	lgdt [gdt]
	call 0x8:start64

[BITS 64]

start64:
	extern main
	call main
	

[BITS 32]
; infinitive halt
hang:	hlt
	jmp hang



; Load new GDT
	global gdt_flush
	extern gdt
gdt_flush:
	lgdt [gdt]		; Load the GDT with our '_gp' which is a special pointer
	mov ax, 0x10		; 0x10 is the offset in the GDT to our data segment
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:.far		; 0x08 is the offset to our code segment: Far jump!
.far:
	ret			; Returns back to the C code!
