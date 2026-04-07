#include "bitmap.h"

bitmap get_bitmap(size_t size) {
  size_t alloc_size=(size+7)/8;
  bitmap new = malloc(alloc_size);
  memset(new,0,alloc_size);
  return new;
}

void free_bitmap(bitmap bm) {
  free(bm);
}
