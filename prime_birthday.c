#include <stddef.h>
#include <stdio.h>
#include "prime.h"

void print_efficiency(Stack_ul *s) {
  printf("total length:%lu,size:%lu,efficiency:%.2f%%\n",
         s->length, s->size,
         100.0 * s->length / s->size);
}

int main() {
  Stack_ul *s = euler_filter(20050000);
  
  print_efficiency(s);
  free_stack(s);
  return 0;
}
