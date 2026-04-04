#include <stddef.h>

#ifndef BITMAP_H
#define BITMAP_H

#define get(x, map) ((map[x >> 3] >> (x & 7)) & 1)
#define set(x, map) (map[x >> 3] |= (1 << (x & 7)))
#define clr(x, map) (map[x >> 3] &= ~(1 << (x & 7)))

typedef char *bitmap;
bitmap get_bitmap(size_t size);
void free_bitmap(bitmap bm);
#endif
