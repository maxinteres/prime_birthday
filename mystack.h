#include <stdlib.h>

#ifndef MYSTACK_H
#define MYSTACK_H

typedef unsigned long ul;
typedef struct Stack_ul {
  size_t size;
  size_t length;
  ul *array;
} Stack_ul;
Stack_ul *get_stack(size_t size);
Stack_ul *resize_stack(Stack_ul *s, size_t size);
Stack_ul *push_stack(Stack_ul *s, ul num);
Stack_ul *pop_stack(Stack_ul *s);
ul top_stack(Stack_ul *s);
void free_stack(Stack_ul *stack) {
#endif
