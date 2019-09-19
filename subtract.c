#include <stdio.h>
#include <conio.h>

void subtract(double **augmented_matrix, int cols, double r, int i, int k) {
    int j;
    for (j = 0; j <= cols; j++) {
        augmented_matrix[k][j] -= r * augmented_matrix[i][j];
    }
}