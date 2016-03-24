#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>

bool isprime(long long num);
bool q_isprime(long long num);
int numbits(int num);
void bitnums(int num, char* bitwurd);
void rev(char* wurd);
int newton(int num);

#define UNDERNUM 2000000

int main(int argc, char **argv)
{
    //int topprime;
    //int count = 0;
    ////int idx = 1;
    //while ( count != 2000000 ) {
    //    if ( q_isprime(count) ) {
    //    //if ( isprime(idx) ) {
    //        count++;
    //        topprime = idx;
    //    }
    //    idx++;
    //}
    long psum = 0;
    //int pcount = 0;
    for ( int i = 0; i < UNDERNUM; i++ ) {
        if ( q_isprime(i) ) {
            //printf("Prime: %d\n", i);
            //pcount++;
            psum += i;
        }
    }

    //printf("Total PRimes under %d is %d\n", UNDERNUM, pcount);
    printf("SUm of PRimes under %d is %ld\n", UNDERNUM, psum);
}

bool isprime(long long num)
{
    for ( int i = 2; i < num; i++ ) {
        if ( num % i == 0 )
            return false;
    }
    return true;
}

bool q_isprime(long long num)
{
    if ( num <= 1 )
        return false;
    else if ( num <= 3 )
        return true;
    else if ( num % 2 == 0 || num % 3 == 0 )
        return false;
    int x = 5;
    while ( x * x <= num ) {
        if ( num % x == 0 || num % ( x + 2 ) == 0 ) {
            return false;
        }
        x += 6;
    }
    return true;
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

int newton(int num)
// http://stackoverflow.com/questions/1623375/writing-your-own-square-root-function
{
    if ( num <= 0 )
        return -1;
    int x = pow(2, numbits(num)/2);
    int y;
    while (1) {
        y = floor((x + floor(num/x))/2);
        if ( y >= x )
            return x;
        x = y;
    }
}

