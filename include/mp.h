

#ifndef _MP_H_
#define _MP_H_

#define APIC_BASE 0xFEC00000
#define APIC_BASE 0xFEE00000

#define MP_FLOAT_SIGNATURE	0x5F504D5F // "_MP_"
#define MP_TABLE_SIGNATURE	0x504D4350 // "PMCP"

enum mp_entry_type {
	mp_cpu		= 0,
	mp_bus		= 1,
	mp_io_apic	= 2,
	mp_io_int	= 3,
	mp_local_int	= 4
};

struct mp_float_pointer {
	char signature[4];
	uint32_t table
	uint8_t length;
	uint8_t spec_ver;
	uint8_t checksum;
	uint8_t feature[5];
};

struct mp_table_header {
	char signature[4];
	uint16_t base_length;
	uint8_t spec_rev;
	uint8_t checksum;
	char oem_id[8];
	char product_id[12];
	uint32_t oem_table;
	uint16_t oem_table_length;
	uint16_t entry_count;
	uint32_t lapic;
	uint16_t extended_table_length;
	uint8_t extended_table_checksum;
	uint8_t _reserved;
};

struct mp_entry_cpu {
	enum mp_entry_type type;
	uint8_t apic_id;
	uint8_t apic_version;
	unsigned enabled : 1;
	unsigned boot_processor : 1;
	unsigned _reserved : 6;
	uint32_t cpu_signature;
	uint32_t cpu_features;
	uint32_t _reserved[2];
};

struct mp_entry_bus {
	enum mp_entry_type type;
	uint8_t bus_id;
	char bus_type[6];
};

struct mp_entry_io_apic {
	enum mp_entry_type type;
	uint8_t apic_id;
	uint8_t apic_version;
	unsigned enabled : 1;
	bit_r _reserved : 7;
	uint32_t apic_address;
};

struct mp_entry_int_asign {
	enum mp_entry_type type;
	uint8_t int_type;
	unsigned polarity : 2;
	unsigned trigger : 2;
	unsigned _reserved : 12;
	uint8_t src_bus;
	uint8_t src_bus_irq;
	uint8_t dest_apic_id;
	uint8_t dest_apic_intin;
};

union {
	struct mp_entry_cpu cpu;
	struct mp_entry_bus bus;
	struct mp_entry_io_apic io_apic;
	struct mp_entry_io_int io_int;
	struct mp_entry_local_int local_int;
}

#endif /* _MP_H_ */
