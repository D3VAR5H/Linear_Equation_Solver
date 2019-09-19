#include <stdio.h>
#include <stdlib.h>
#include "input_matrix.c"
#include "gaussian_elimination.c"

int main()
{
    int i,j;

    int cols;
    printf("No. of variables: ");
    scanf("%d", &cols);

    int rows;
    printf("No. of equations: ");
    scanf("%d", &rows);

    double **augmented_matrix;
    augmented_matrix = (double **)calloc(rows, sizeof(double *));
    for (i = 0; i < rows; i++)    {
        augmented_matrix[i] = (double *)calloc(cols, sizeof(double));
    }

    input_matrix(augmented_matrix, rows, cols);

    gaussian_elimination(augmented_matrix, rows, cols);
    
    free(augmented_matrix);

    return 0;
}

/*
1 2 3 6
2 4 7 19
3 6 10 22

1 2 3 6
3 6 1 9
7 13 8 9

1 2 3
2 3 5
1 4 5

1 2 2 4 5
3 8 6 16 19

1 1 1 3
2 3 4 6

0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0

2 4 -2 1 1
-2 -5 7 3 2
3 7 -8 6 3

0 1 0 2 3 4
0 2 0 4 6 8
0 3 0 5 7 9
0 4 0 9 11 13
0 5 0 11 17 19

1 2 3 4 5
6 12 7 8 9
10 20 11 12 13
14 28 15 16 17

-3 6 -1 1 -7 5
1 -2 2 3 2.33 6
2 -4 5 8 -4 11
*/