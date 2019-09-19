#include "swap_cols.c"
#include <stdio.h>
#include <stdlib.h>

void obtain_nullspace(double **augmented_matrix, int rows, int cols, int rank){

    int i, j, k, l;
    double temp;
    int nullity = cols - rank;
    double variable_matrix[cols][nullity];
    
    int swap_tracker[rank][2];
    for(i=0; i < rank; i++){
        swap_tracker[i][0] = 0;
        swap_tracker[i][1] = 0;
    }

    k = 0;
    for(i=0; i < rank ; i++){
        if(augmented_matrix[i][i] != 1){
            j = i + 1;
            
            while (j < cols){
                if (augmented_matrix[i][j] == 1) {
                    swap_tracker[k][0] = i;
                    swap_tracker[k][1] = j;
                    k++;
                    printf("%d%d ",i,j);
                    for (l = 0; l < rows; l++) {
                        temp = augmented_matrix[l][i];
                        augmented_matrix[l][i] = augmented_matrix[l][j];
                        augmented_matrix[l][j] = temp;
                    }
                    j = cols;
                } else {
                    j++;
                }
            }
        }
    }

    k = 0;
    for(i = cols-1; i >= 0 ; i--){
        for (j = nullity-1; j >=0; j--){
            variable_matrix[i][j] = 0;
        }
        if (k <= nullity){
            variable_matrix[i][nullity-k-1] = 1;
            k++;
        }
    }

    for(i = 0; i < rank; i++){
        for(j = 0; j < nullity; j++){
            variable_matrix[i][j] = (-1.0)*augmented_matrix[i][rank+j];
            if(augmented_matrix[i][rank+j]==0){
                variable_matrix[i][j] = 0;
            }
        }
    }

    for(i = rank-1; i >= 0; i--){
        for (k = 0; k < nullity; k++) {
            temp = variable_matrix[swap_tracker[i][0]][k];
            variable_matrix[swap_tracker[i][0]][k] = variable_matrix[swap_tracker[i][1]][k];
            variable_matrix[swap_tracker[i][1]][k] = temp;
        }
    }

    printf("\n\nBasis of Nullspace for given Matrix:");
    for (i = 0; i < cols; i++){
        printf("\n");
        for (j = 0; j < nullity; j++){
            printf("%.2lf  ", variable_matrix[i][j]);
        }
    }  
}