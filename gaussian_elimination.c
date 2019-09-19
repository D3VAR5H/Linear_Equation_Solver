#include <stdio.h>
#include <stdlib.h>
#include "elimination.c"
#include "divide_row.c"
#include "pivoting.c"
#include "print_matrix.c"
#include "obtain_nullspace.c"
#include "obtain_solution.c"

void gaussian_elimination(double **augmented_matrix, int rows, int cols) {
    int i, j, k = 0, singular = 0;

    for(i=0,j=0; i<rows && j<cols; i++,j++){
        if (augmented_matrix[i][j] == 0) {
            if(pivoting(augmented_matrix, rows, cols, i, j) == 0){
                singular = 1;
            }else{
                j--;
            }
            i--;
        } else {
            divide_row(augmented_matrix, cols, i, j);
            elimination(augmented_matrix, rows, cols, i, j);
        }
    }

    print_matrix(augmented_matrix, rows, cols);
    
    if(singular == 1){
        obtain_nullspace(augmented_matrix, rows, cols, i);
    }
    else{
        obtain_solution(augmented_matrix, rows, cols, i);
    }
}