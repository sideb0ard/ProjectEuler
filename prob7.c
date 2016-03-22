#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

bool isprime(long long num);
int numbits(int num);
void bitnums(int num, char* bitwurd);
void rev(char* wurd);

int main(int argc, char **argv)
{
    if (argc != 2 ) return -1;
    long long num = strtoll(argv[1], NULL, 10);
    //printf("Num of bits in %lld is %d\n", num, numbits(num));

    char bitwurd[2049] = {0};
    bitnums(num, bitwurd);
    //printf("BACKWURDS %s\n", bitwurd);
    rev(bitwurd);
    printf("FWARDSS %s\n", bitwurd);
}

int numbits(int num)
{
  int nbits = 0;
  while ( num ) {
    nbits++;
    num >>= 1;
  }
  return nbits;
}

void bitnums(int num, char *bitwurd)
{
    int i = 0;
    while ( num ) {
        bitwurd[i] = num & 1 ? '1' : '0';
        //if ( num & 1 ) {
        //  bitwurd[i]= '1';
        //} else  {
        //  bitwurd[i]= '0';
        //}
        i++;
        num >>= 1;
    }
    bitwurd[i] = '\0';
}

void rev(char* wurd)
{
    if ( wurd ) {
        char* end = wurd + strlen(wurd) - 1;
#define XOR_SWAP(a, b) do\
        {\
            a ^= b;\
            b ^= a;\
            a ^= b;\
        } while (0)

        while ( wurd < end ) {
            XOR_SWAP(*wurd, *end);
            wurd++;
            end--;
        }
#undef XOR_SWAP
    }
}
