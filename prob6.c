#include <stdio.h>

#define PUZNUM 100

int sq(int num);
int sosq(int num);
int sqos(int num);

int main(int argc, char **argv)
{

  int sum_of_sq = sosq(PUZNUM);
  int square_of_sum = sqos(PUZNUM);

  printf("Diff is: %d\n", square_of_sum - sum_of_sq);

}

int sq(int num) {
  return num * num;
}

int sosq(int num) {
  int sum = 0;
  for ( int i = 1; i <= num ; i++ ) 
    sum += sq(i);
  printf("Sum of Squares is %d\n", sum);
  return sum;
}

int sqos(int num) {
  int sum = 0;
  for (int i = 1; i <= num; i++ )
    sum += i;
  int sqsum = sq(sum);
  printf("Sqsum is %d\n", sqsum);
  return sqsum;
}

