#include <stdio.h>

int main()
{
  int sum = 0;
  int p1term = 1, p2term = 0; // previous 
  int fib;

  do {
    fib = p1term + p2term;
    printf("FIB: %d P1term: %d P2ter, %d\n", fib, p1term, p2term);
    p2term = p1term;
    p1term = fib;
    if ( fib % 2 == 0 ) sum += fib;
  } while (p1term < 6000000);

  printf("EVEN SUM: %d\n", sum);
}
