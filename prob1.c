#include <stdio.h>

int main()
{
  int summ = 0;

  for ( int i = 1; i < 1000; i++ ) {
    if ( i % 3 == 0 || i % 5 == 0 ) {
      printf ( "I: %d\n", i );
      summ += i;
    }
  }

  printf ( "SUm: %d\n", summ);
}
