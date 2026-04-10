#include <stddef.h>
#include <stdio.h>
#include "prime.h"
#include "date.h"

#define atoul(a) strtoul((a), NULL, 10)
void print_efficiency(Stack_ul *s) {
  printf("total length:%lu,size:%lu,efficiency:%.2f%%\n",
         s->length, s->size,
         100.0 * s->length / s->size);
}

size_t bsearch4ul(ul *base, size_t length, ul targit) {
  /*
    return the last number greater than or equal to targit;
    assuming the array to be ascending
   */
  size_t l = 0, r = length, mid = (l + r) / 2,res=-1;
  while (l < r) {
    if (base[mid] >= targit) {
      res = mid;
      r=mid-1;
    } else {
      l=mid+1;
    }
    mid=(l+r)/2;
  }
  return res;
}

void case1() {
  Stack_ul *s = euler_filter(100000000);
  printf("There is %lu primes between 0 and 1e8\n",s->length);
  print_efficiency(s);
}

void case2(int argc,char *argv[]) {
  
  char flag=1;
  ul input_num = atoul(argv[1]);
  Stack_ul *s = euler_filter(input_num+2);
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
  free_stack(s);
  if (flag)
    printf("It's a prime birthday\n");
}

void case3(int argc, char *argv[]) {
  if (argv[1] > argv[2])
      printf("no prime birthday in this domain");
  else {
    Stack_ul *s = euler_filter(atoul(argv[2]));
    size_t start = bsearch4ul(s->array, s->length, atoul(argv[1]));
    size_t i;
    char flag=1;
    for (i = start; i < s->length; i++) {
      Date *temp = ul2Date(s->array[i]);
      if (legal_date(temp)) {
	print_date(temp);
	printf(" is a prime birthday\n");
	flag=0;
      }
    }
    if (flag)
      printf("no prime birthday in this domain");
    free_stack(s);
  }
}


int main(int argc, char *argv[]) {

  switch (argc) {
  case 1:
    case1();
    break;
    
  case 2:
    case2(argc, argv);
    break;

  case 3:
    case3(argc, argv);
    break;
    
  default:
    break;
  }
  return 0;
}
