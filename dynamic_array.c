#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    /* TODO: define the 2D pointer variable here */
    int nrows = 2;
    int ncols = 2;
    /* TODO: complete the following line to allocate memory for holding three rows */
    int **pnumbers = (int **) malloc(nrows * sizeof(int *));

    /* TODO: allocate memory for storing the individual elements in a row */
    pnumbers[0] = (int *) malloc(1 * sizeof(int));

    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j <= i; j++) {
            printf("%d", pnumbers[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        /* TODO: free memory allocated for each row */
    }

    /* TODO: free the top-level pointer */

  return 0;
}