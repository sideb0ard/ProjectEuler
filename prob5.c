#include <stdio.h>
#include <stdbool.h>

#define NUM 20

int main(int argc, char **argv)
{

  for ( int i = 1 ; ; i++ ) {
    for ( int j = 1; j <= NUM ; j++ ) {
      if ( !(i % j == 0) ) {
        break;
      }
      if ( j == NUM ) {
        printf("Smallest number than can be divided be each of the numbers "
               "from 1 to %d is : %d\n", NUM, i);
        return 0;
      }
    }
  }



}

