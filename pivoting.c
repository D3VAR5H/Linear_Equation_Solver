#include <stdio.h>
#include "swap_rows.c"

int pivoting(double **augmented_matrix, int rows, int cols, int i, int j) {
    int k = i + 1;
    while (k < rows){
        if (augmented_matrix[k][j] == 0) {
            k++;
        } else {
            swap_rows(augmented_matrix, cols, i, k);
            return 1;
        }
    }
    return 0;
}