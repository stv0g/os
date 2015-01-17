#ifndef _MULTIBOOT_H_
#define _MULTIBOOT_H_

#define MULTIBOOT_HEADER_FLAGS			((1 << MULTIBOOT_PAGE_ALIGN) | (1 << MULTIBOOT_MEMORY_INFO))
#define MULTIBOOT_CHECKSUM			-(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

/* How many bytes from the start of the file we search for the header. */
#define MULTIBOOT_SEARCH			8192

/* The magic field should contain this. */
#define MULTIBOOT_HEADER_MAGIC			0x1BADB002

/* This should be in %eax. */
#define MULTIBOOT_BOOTLOADER_MAGIC		0x2BADB002

/* Alignment of multiboot modules. */
#define MULTIBOOT_MOD_ALIGN			0x00001000

/* Alignment of the multiboot info structure. */
#define MULTIBOOT_INFO_ALIGN			0x00000004

/* Flags set in the 'flags' member of the multiboot header. */

/* Align all boot modules on i386 page (4KB) boundaries. */
#define MULTIBOOT_PAGE_ALIGN			0

/* Must pass memory information to OS. */
#define MULTIBOOT_MEMORY_INFO			1

/* Must pass video information to OS. */
#define MULTIBOOT_VIDEO_MODE			2

/* This flag indicates the use of the address fields in the header. */
#define MULTIBOOT_AOUT_KLUDGE			0x00010000

/* Flags to be set in the 'flags' member of the multiboot info structure. */

/* is there basic lower/upper memory information? */
#define MULTIBOOT_INFO_MEMORY			0
/* is there a boot device set? */
#define MULTIBOOT_INFO_BOOTDEV			1
/* is the command-line defined? */
#define MULTIBOOT_INFO_CMDLINE			2
/* are there modules to do something with? */
#define MULTIBOOT_INFO_MODS			3

/* These next two are mutually exclusive */

/* is there a symbol table loaded? */
#define MULTIBOOT_INFO_AOUT_SYMS		4
/* is there an ELF section header table? */
#define MULTIBOOT_INFO_ELF_SHDR			5

/* is there a full memory map? */
#define MULTIBOOT_INFO_MEM_MAP			6

/* Is there drive info? */
#define MULTIBOOT_INFO_DRIVE_INFO		7

/* Is there a config table? */
#define MULTIBOOT_INFO_CONFIG_TABLE		8

/* Is there a boot loader name? */
#define MULTIBOOT_INFO_BOOT_LOADER_NAME		9

/* Is there a APM table? */
#define MULTIBOOT_INFO_APM_TABLE		10

/* Is there video information? */
#define MULTIBOOT_INFO_VIDEO_INFO		11

#define MULTIBOOT_MEMORY_AVAILABLE		1
#define MULTIBOOT_MEMORY_RESERVED		2

struct multiboot_header
{
	/* Must be MULTIBOOT_MAGIC - see above. */
	uint32_t magic;

	/* Feature flags. */
	uint32_t flags;

	/* The above fields plus this one must equal 0 mod 2^32. */
	uint32_t checksum;

	/* These are only valid if MULTIBOOT_AOUT_KLUDGE is set. */
	uint32_t header_addr;
	uint32_t load_addr;
	uint32_t load_end_addr;
	uint32_t bss_end_addr;
	uint32_t entry_addr;

	/* These are only valid if MULTIBOOT_VIDEO_MODE is set. */
	uint32_t mode_type;
	uint32_t width;
	uint32_t height;
	uint32_t depth;
};

/* The symbol table for a.out. */
struct multiboot_aout_symbol_table
{
	uint32_t tabsize;
	uint32_t strsize;
	uint32_t addr;
	uint32_t reserved;
};

/* The section header table for ELF. */
struct multiboot_elf_section_header_table
{
	uint32_t num;
	uint32_t size;
	uint32_t addr;
	uint32_t shndx;
};

struct multiboot_info
{
	/* Multiboot info version number */
	uint32_t flags;

	/* Available memory from BIOS */
	uint32_t mem_lower;
	uint32_t mem_upper;

	/* "root" partition */
	uint32_t boot_device;

	/* Kernel command line */
	uint32_t cmdline;

	/* Boot-Module list */
	uint32_t mods_count;
	uint32_t mods_addr;

	union
	{
		multiboot_aout_symbol_table_t aout_sym;
		multiboot_elf_section_header_table_t elf_sec;
	} u;

	/* Memory Mapping buffer */
	uint32_t mmap_length;
	uint32_t mmap_addr;

	/* Drive Info buffer */
	uint32_t drives_length;
	uint32_t drives_addr;

	/* ROM configuration table */
	uint32_t config_table;

	/* Boot Loader Name */
	uint32_t boot_loader_name;

	/* APM table */
	uint32_t apm_table;

	/* Video */
	uint32_t vbe_control_info;
	uint32_t vbe_mode_info;
	uint16_t vbe_mode;
	uint16_t vbe_interface_seg;
	uint16_t vbe_interface_off;
	uint16_t vbe_interface_len;
};

struct multiboot_mmap_entry
{
	uint32_t size;
	uint64_t addr;
	uint64_t len;
	uint32_t type;
} __attribute__ ((packed));

struct multiboot_mod_list
{
	/* the memory used goes from bytes 'mod_start' to 'mod_end-1' inclusive */
	uint32_t mod_start;
	uint32_t mod_end;

	/* Module command line */
	uint32_t cmdline;

	/* padding to take it to 16 bytes (must be zero) */
	uint32_t pad;
};

#endif /* _MULTIBOOT_H_ */
