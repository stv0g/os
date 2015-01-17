KERNEL = os

VPATH = include kernel driver lib

# Cross compiler prefix
CROSS = x86_64-elf-

# Tools
RM   = rm -f
CC   = $(CROSS)gcc
LD   = $(CROSS)ld
ASM  = nasm
QEMU = qemu-system-x86_64
GDB  = gdb

# Flags
INCS = -Iinclude/
LIBS = -lgcc

ASMFLAGS += -g -felf64 $(INCS)
CFLAGS += -c -fdiagnostics-color -ffreestanding -O2 -Wall -Wextra -std=c99 -nostdlib $(INCS)
LDFLAGS += -z max-page-size=4096

all: $(KERNEL).elf

-include $(addsuffix /Makefile, $(VPATH))
-include $(wildcard *.d)

# Link kernel image
$(KERNEL).elf: $(OBJS)
	$(LD) $(LDFLAGS) -T scripts/script.ld $^ -o $@

# Translate CPP macros to NASM macros
%.inc: %.h
	sed -n -f scripts/cpp2nasm.sed < $< > $@

# Compile & Assemble
%.o: %.c
	$(CC)  $(CFLAGS)  -MMD -MF $*.d $< -o $@

%.o: %.s
	$(ASM) $(ASMFLAGS) -MG -MD $*.d $< -o $@

clean:
	$(RM) *.o *.d *.inc *.elf

debug:
	$(QEMU) -monitor stdio -gdb tcp::1234 -kernel $(KERNEL).elf
	$(GDB) gdb &

.PHONY: clean qemu
