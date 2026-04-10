#include "prime.h"
#include "bitmap.h"
#include <stddef.h>
#include <math.h> //need to add -lm

#define est_size(n) (size_t)((n)/log((n))*1.2+10)
#define ncy_size(n) (size_t)(sqrt((n)) + 10)
#define between(n, l, r) (((n) >= (l)) && ((n) < (r)))

Stack_ul *euler_filter(ul n) {
  /*
get primes under n include n
   */
  Stack_ul *primes = get_stack(est_size(n));
  bitmap is_n_prime=get_bitmap(n+1);
  size_t i,j;//keypoint 2
  for (i = 2; i <= n; i++) {
    if (!get(i, is_n_prime))
      push_stack(primes, i);
    for (j = 0; j < primes->length; j++) {
      ul p = primes->array[j]; //keypoint 3
      if (i * p <= n)//keypoint 1
        set(i * p, is_n_prime);
      else
	break;
      if (i % p == 0)
	break;
    }
  }
  free_bitmap(is_n_prime);
  return primes;
}

/*
too slow

  Stack_ul *primes_between(ul l, ul r) {

  //  get primes between l and r

  if (r < l)
    return NULL;

  size_t i, j, length = r - l;
  Stack_ul *primes=get_stack(est_size(length));
  Stack_ul *base_prime = euler_filter(ncy_size(r));
  bitmap is_n_prime=get_bitmap(length);

  for (i = l/top_stack(base_prime); i <= r; i++) {
    if (between(i, l, r) && !get(i - l, is_n_prime))
      push_stack(primes, i);
    for (j = 0; j < base_prime->length; j++) {
      ul p = base_prime->array[j]; //keypoint 3
      if (between(i * p, l, r))// keypoint 1
        set(i * p-l, is_n_prime);
      if (i % p == 0)
        break;
    }
  }

  free_bitmap(is_n_prime);
  free_stack(base_prime);
  return primes;
  }
*/
  
  
