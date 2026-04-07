#include "mystack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
size_t upper2(size_t size) {
  size_t i = 1;
  for (i = 1; i <= size; i <<= 1)
    ;
  return i;
}

Stack_ul *get_stack(size_t size) {
  Stack_ul *new = malloc(sizeof(Stack_ul));
  new->length = 0;
  new->size = size;
  new->array = malloc(size * sizeof(ul));
  if(new->array==NULL)perror("fail in getting array");
  return new;
}

Stack_ul *resize_stack(Stack_ul *s, size_t size) {
  if (s == NULL)
    return NULL;
  s->array = realloc(s->array, size * sizeof(ul));
  s->size = size;
  return s;
}

Stack_ul *push_stack(Stack_ul *s, ul num) {
  if (s == NULL)
    return NULL;
  if (s->length<s->size)
    s->array[s->length++] = num;
  else {
    s = resize_stack(s, upper2(s->size));
    s->array[s->length++] = num;
  }
  return s;
}

Stack_ul *pop_stack(Stack_ul *s) {
  if (s == NULL)
    return NULL;
  if (s->length > 0)
    s->length--;
  return s;
}

ul top_stack(Stack_ul *s) {
  if (s == NULL)
    return 0;
  return s->array[s->length-1];
}

void free_stack(Stack_ul *stack) {
  free(stack->array);
  free(stack);
}

char in_stack(Stack_ul *s, ul num) {
  if (s == NULL)
    return 0;
  
  size_t i;
  for (i = 0; i < s->length; i++)
    if (s->array[i] == num)
      return 1;
  return 0;
}

