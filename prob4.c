#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZENUM 1000

bool ispalin(long long num);
char* reverse(char*);

int big_pal = 0;

int main(int argc, char **argv)
{

  for ( int i = 0; i < SIZENUM; i++ ) {
    for ( int j = 0; j < SIZENUM; j++ ) {
      int product = i * j;
      printf("Product: %d\n", product);
      if ( ispalin(product) && product > big_pal ) big_pal = product;
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

bool ispalin(long long num) {
  char wordnum[100];
  sprintf(wordnum, "%lld", num);
  char *revwurd = reverse(wordnum);
  return (!strcmp(wordnum, revwurd) ? true : false );
}

