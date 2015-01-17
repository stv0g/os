
#ifndef _REGISTERS_H_
#define _REGISTERS_H_

/**
 * Control Register 0
 */

#define CR0_PE		0
#define CR0_MP		1
#define CR0_EM		2
#define CR0_TS		3
#define CR0_ET		4
#define CR0_NE		5
#define CR0_WP		16
#define CR0_AM		18
#define CR0_NW		29
#define CR0_CD		30
#define CR0_PG		31

#define CR3_PWT		3
#define CR3_PCD		4

#define CR4_VME		0
#define CR4_PVI		1
#define CR4_TSD		2
#define CR4_DE		3
#define CR4_PSE		4
#define CR4_PAE		5
#define CR4_MCE		6
#define CR4_PGE		7
#define CR4_PCE		8
#define CR4_OSFXSR	9
#define CR4_OSXMMEXCPT	10
#define CR4_VMXE	13
#define CR4_SMXE	14
#define CR4_FSGSBASE	16
#define CR4_PCIDE	17
#define CR4_OSXSAVE	18
#define CR4_SMEP	20
#define CR4_SMAP	21

#define EFER_LME	8
#define EFER_LMA	10
#define EFER_NXE	11
#define EFER_SVME	12
#define EFER_LMSLE	13
#define EFER_FFXSR	14
#define EFER_TCO	15

#endif /* _REGISTERS_H_ */
