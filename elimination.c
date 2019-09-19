#include <stdio.h>
#include "subtract.c"

void elimination(double **augmented_matrix, int rows, int cols, int i, int j) {
    int k = 0;
    
    while (k < rows){
        if(k != i){
            double r = augmented_matrix[k][j] / augmented_matrix[i][j];
            subtract(augmented_matrix, cols, r, i, k);
        }
        k++;
    }
}