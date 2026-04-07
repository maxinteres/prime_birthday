#include <stddef.h>
#include <stdio.h>
#include "prime.h"
#include "date.h"

void print_efficiency(Stack_ul *s) {
  printf("total length:%lu,size:%lu,efficiency:%.2f%%\n",
         s->length, s->size,
         100.0 * s->length / s->size);
}

int main(int argc,char *argv[]) {
  Stack_ul *s = euler_filter(20050000);
  size_t i;
  
  print_efficiency(s);
  free_stack(s);
  return 0;
}
