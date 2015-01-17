
#ifndef _PAGE_H_
#define _PAGE_H_

#define BITS			64
/// Linear/virtual address width
#define VIRT_BITS		48
/// Physical address width (maximum value)
#define PHYS_BITS		52
/// Page map bits
#define PAGE_MAP_BITS		9
/// Number of page map indirections
#define PAGE_MAP_LEVELS	4
/// Mask the page address without page map flags
#define PAGE_MASK		0x000FFFFFFFFFF000

/// Page is present
#define PG_PRESENT		0
/// Page is read- and writable
#define PG_RW			1
/// Page is addressable from userspace
#define PG_USER			2
/// Page write through is activated
#define PG_PWT			3
/// Page cache is disabled
#define PG_PCD			4
/// Page was recently accessed (set by CPU)
#define PG_ACCESSED		5
/// Page is dirty due to recentwrite-access (set by CPU)
#define PG_DIRTY		6
/// Huge page: 4MB (or 2MB, 1GB)
#define PG_PSE			7
/// Page attribute table
#define PG_PAT			7
/// Global TLB entry
#define PG_GLOBAL		8
/// Disable execution for this page
#define PG_XD			63

struct page_entry {
	unsigned flags		: 12;
	unsigned pfn		: 40;
	unsigned flags2		: 12;
};

struct vir_addr {
	unsigned offset		: 12;
	unsigned vpn		: 52;
};

#endif /* _PAGE_H_ */
