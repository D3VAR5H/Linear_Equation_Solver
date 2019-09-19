#include <stdio.h>

void print_matrix(double **augmented_matrix, int rows, int cols){
    int i,j;
    printf("\nAugmented Matrix:");
    for (i = 0; i < rows; i++){
        printf("\n");
        for (j = 0; j <= cols; j++){
            printf("%3.2lf  ", augmented_matrix[i][j]);
            if(j==cols-1){
                printf("%c  ", 179);
            }
        }
    }
}