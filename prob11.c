#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define LINEMAX 120

int main(int argc, char **argv)
{
    char buf[LINEMAX];

    FILE *fd_r = fopen("2020grid.txt", "ro");
    //FILE *fd_w = fopen("2020grid.c", "rw");

    char *tok, *wurd;

    while ( fgets (buf, LINEMAX, fd_r)) {
        printf("\t[");
        for ( tok = strtok_r(buf, " ", &wurd );
              tok;
              tok = strtok_r(NULL, " ", &wurd))
        {
            if (strlen(tok) == 3) {
                char naecr[3];
                strncpy (naecr, tok, 2);
                naecr[2] = '\0';
                printf("%s", naecr);
            } else {
                printf("%s,", tok);
            }

        }
        printf("]\n");
    }
}

