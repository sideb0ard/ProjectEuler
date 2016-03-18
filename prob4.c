#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZENUM 1000

bool ispalin(long long num);
char* reverse(char*);

int main(int argc, char **argv)
{
  int big_pal = 0;
  char wurd[10];

  for ( int i = SIZENUM; i > 100; i-- ) {
    for ( int j = SIZENUM; j > 100; j-- ) {
      int product = i * j;
      sprintf(wurd, "%d", product);
      if ( !strcmp(wurd, reverse(wurd)) && product > big_pal ) big_pal = product;
    }
  }

  printf("Biggest Palindrome is %d (size: %d)\n", big_pal, SIZENUM);
}

char* reverse(char *wurd) {
  int wlen = strlen(wurd);
  char *revwurd = calloc(wlen+1, sizeof(char));
  revwurd[wlen] = '\0';
  for ( int i = wlen - 1, j = 0; i >= 0; i--, j++) {
    revwurd[i] = wurd[j];
  }
  return revwurd;
}
