

#ifndef _MEM_H_
#define _MEM_H_

void memcopy(void *dest, void *src, size_t len);

int memcmp(void *dest, void *src, size_t len);

void memset(void *dest, uint8_t value, size_t len);

#endif /* _MEM_H_ */
