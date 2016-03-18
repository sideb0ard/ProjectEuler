#include <stdio.h>
#include <stdbool.h>

#define NUM 20

int main(int argc, char **argv)
{

  int temp = 1, num = 1, i = 1;
  while ( i <= NUM ) {
    if ( num % i == 0 ) {
      i++;
      temp = num; 
    } else {
      num = num + temp;
    }
  }

  printf("Smallest num %d\n", num);

}

