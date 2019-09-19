#include <stdio.h>

void input_matrix(double **augmented_matrix, int rows, int cols) {
    int i, j;

    for (i = 0; i < cols; i++) {
        printf("x%d   ",i);
    }
    printf("rhs\n");

    for (i = 0; i < rows; i++) {
        for (j = 0; j <= cols; j++) {
            scanf("%lf", &augmented_matrix[i][j]);
        }
    }
}