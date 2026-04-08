#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include "prime.h"
#include "date.h"

void print_efficiency(Stack_ul *s) {
  printf("total length:%lu,size:%lu,efficiency:%.2f%%\n",
         s->length, s->size,
         100.0 * s->length / s->size);
}


int main(int argc, char *argv[]) {
  Stack_ul *s = euler_filter(100000000);
  
  switch (argc) {
  case 1:
    printf("There is %lu primes between 0 and 1e8\n",s->length);
    print_efficiency(s);
    break;
    
  case 2:
    ;
    ul input_num = strtoul(argv[1], NULL, 10);
    char flag=1;
    if (in_stack(s,input_num))
      printf("%lu is a prime.\n", input_num);
    else {
      printf("%lu is not a prime.\n", input_num);
      flag=0;
    }
    
    Date *day = ul2Date(input_num);
    if (legal_date(day)) {
      print_date(day);
      printf(" is a legal date.\n");
    } else {
      print_date(day);
      printf(" is not a legal date.\n");
      flag=0;
    }
    free(day);
    
    if (flag)
      printf("It's a prime birthday\n");
    break;
    
  case 3:
    break;
  default:
    break;
  }
  free_stack(s);
  return 0;
}
