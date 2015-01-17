

#ifndef _BITS_H_
#define _BITS_H_

typedef unsigned bit;

#define  bit(p)		(1 <<  (p))
#define setb(v, p)	(v |  B(p))
#define clrb(v, p)	(v & ~B(p))

#define msb(v)
#define lsb(v)

#endif /* _BITS_H_ */

