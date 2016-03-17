#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxnumprimes = 1000;
int initprimes[1000];
int initprimesidx = 0;
long long primefactors[100] = {0};
int primeidx = 0;

void factorize(long long num);
bool isprime(long long num);
bool done = false;

void fillprimes()
{
  int i = 2;
  do {
    if ( isprime(i) ) {
      initprimes[initprimesidx++] = i;
    }
    i++;
  } while ( initprimesidx < maxnumprimes );
}


int main(int argc, char **argv)
{
  if (argc != 2 ) return -1;

  fillprimes();
  //for (int i = 0; i < maxnumprimes; i++ ) 
  //  printf("Primey: %d\n", initprimes[i]);

  long long num = strtoll(argv[1], NULL, 0);

  printf("Long Long Long %lld\n", num);

  factorize(num);

  printf("\nPrime factors: ");
  for ( int i = 0; i < primeidx; i++) {
    printf("%lld ", primefactors[i]);
  }
  printf("\n");
}

void factorize(long long num)
{
  printf ("\nFactorize called for %lld\n", num);
  for ( int i = 0; i < maxnumprimes; i++ ) {

    if ( done ) return;
    printf ("Trying prime %d\n", initprimes[i]);

    if ( num % initprimes[i] == 0 ) {
      printf("Found a clean prime divisor: %d\n", initprimes[i]);
      printf("Adding %d to PRIMES\n", initprimes[i]);
      primefactors[primeidx++] = initprimes[i];
      long long divided = num / initprimes[i];
      printf("DIvided: %lld\n", divided);

      if ( isprime(divided) ) {
        printf("Adding %lld to PRIMES\n", divided);
        primefactors[primeidx++] = divided;
        printf("\nDone!\n\n");
        done = true;
        return;
      } else {
        factorize(divided);
      }

    }
  }
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
