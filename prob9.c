#include <stdio.h>
#include <math.h>

float sqz[1000];

void setupSq()
{
    for ( int i = 1; i < 999; i++ ) {
        float pi = pow(i, 2);
        printf("PI%f\n", pi);
        sqz[i] = pi;
    }
}

int main(int argc, char **argv)
{
    setupSq();
    for ( int i = 1; i < 999; i++ ) {
        for ( int j = i+1; j < 999; j++ ) {
            for ( int k = j+1; k < 999; k++ ) {
                if ( sqz[i] + sqz[j] == sqz[k] ){
                    int tote = i + j + k;
                    printf("Pythagorean Triplet! i: %d j: %d k: %d - %.f + %.f = %.f // TOTAL:%d\n", i,j,k, sqz[i], sqz[j], sqz[k], tote);
                    if ( tote == 1000 ) {
                        printf("TOTE is %d, PRODUCT IS %d\n", tote, i*j*k);
                        return 0;
                    }
                }
            }
        }
    }
}


//    int i, j, k;
//    for ( i = 0; i < 1000 ; i++ ) {
//        for ( j = i+1; j < 1000; j++ ) {
//            for ( k = j+1; k < 1000; k++ ) {
//                //printf("i: %d j: %d k: %d\n", i, j, k);
//                int pi, pj, pk;
//                pi = pow(i,2); pj = pow(j,2); pk = pow(k,2);
//                //if (pow(i,2) + pow(j,2) == pow(k,2)) {
//                if (pi + pj == pk ) {
//                    printf("\nPythagorean Triplet:: : %d %d %d ( %d, %d, %d)\n", pi, pj, pk, i, j, k);
//                    if ( pi + pj + pk > 1000 ) {
//                        goto last;
//                    }
//                }
//            }
//        }
//last:
//        printf("\n\nBOOW YA POW : %d %d %d\n", i, j, k);
//        printf("\n\nTOTES : %d\n", i+j+k);
//        if ( i + j + k == 1000 ) {
//            printf("WE DONE! product is %d", i*j*k);
//            return 0;
//        }
//    }

