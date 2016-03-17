#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isprime(long long num);
int main(int argc, char **argv)
{
  if (argc != 2 ) return -1;

  long long num = strtoll(argv[1], NULL, 0);
  printf("Long Long %lld is prime: %s\n", num, isprime(num)? "true" : "false");
}

bool isprime(long long num)
{
  for ( int i = 2; i < num; i++ ) {
    if ( num % i == 0 ) {
      return false;
    }
  }
  return true;
}
