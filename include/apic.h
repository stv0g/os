
#ifndef _APIC_H_
#define _APIC_H_

/// Local APIC ID Register
#define APIC_ID			0x0020	
/// Local APIC Version Register
#define APIC_VERSION		0x0030	
/// Task Priority Regster
#define APIC_TPR		0x0080	
/// EOI Register
#define APIC_EOI		0x00B0	
/// Spurious Interrupt Vector Register
#define APIC_SVR		0x00F0	
/// Error Status Register
#define APIC_ESR		0x0280
/// Interrupt Command Register [bits 0-31]
#define APIC_ICR1		0x0300	
/// Interrupt Command Register [bits 32-63]
#define APIC_ICR2		0x0310	
/// LVT Timer Register
#define APIC_LVT_T		0x0320	
/// LVT Thermal Sensor Register
#define APIC_LVT_TSR		0x0330
/// LVT Performance Monitoring Counters Register
#define APIC_LVT_PMC		0x0340	
/// LVT LINT0 Register
#define APIC_LINT0		0x0350	
/// LVT LINT1 Register
#define APIC_LINT1		0x0360
/// LVT Error Register
#define APIC_LVT_ER		0x0370	
/// Initial Count Register
#define APIC_ICR		0x0380	
/// Current Count Register
#define APIC_CCR		0x0390	
/// Divide Configuration Register
#define APIC_DCR		0x03E0	

/// Register index: ID
#define IOAPIC_REG_ID		0x0000	
/// Register index: version
#define IOAPIC_REG_VER		0x0001	
/// Redirection table base
#define IOAPIC_REG_TABLE	0x0010	

#define APIC_DEST_SELF		0x40000
#define APIC_DEST_ALLINC	0x80000
#define APIC_DEST_ALLBUT	0xC0000
#define APIC_ICR_RR_MASK	0x30000
#define APIC_ICR_RR_INVALID	0x00000
#define APIC_ICR_RR_INPROG	0x10000
#define APIC_ICR_RR_VALID	0x20000
#define APIC_INT_LEVELTRIG	0x08000
#define APIC_INT_ASSERT		0x04000
#define APIC_ICR_BUSY		0x01000
#define APIC_DEST_LOGICAL	0x00800
#define APIC_DM_FIXED		0x00000
#define APIC_DM_LOWEST		0x00100
#define APIC_DM_SMI		0x00200
#define APIC_DM_REMRD		0x00300
#define APIC_DM_NMI		0x00400
#define APIC_DM_INIT		0x00500
#define APIC_DM_STARTUP		0x00600
#define APIC_DM_EXTINT		0x00700
#define APIC_VECTOR_MASK	0x000FF

#endif /* _APIC_H_ */
