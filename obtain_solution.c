#include <stdio.h>
#include "obtain_nullspace.c"

void obtain_solution(double **augmented_matrix, int rows, int cols, int rank){
    
    int i,j;
    double variable[cols];
    int flag = 1;
    if(rank < cols){
        printf("\n\n The given Linear equations have infinite solutions.");
        obtain_nullspace(augmented_matrix, rows, cols, rank);
    } else {
        for(i = rank-1; i >= 0; i--){
            variable[i] = augmented_matrix[i][cols];
            for(j = rank-1; j > i; j--){
                variable[i] -= variable[j]*augmented_matrix[i][j];
            }
            if(augmented_matrix[i][j]==0 && variable[i]!=0){
                flag = 0;
            } else {
                variable[i] /= augmented_matrix[i][j];
            }
        }

    
        if(flag){
            printf("\n\nSolution of the given Linear Equations: ");
            for (i = 0; i < cols; i++)    {
                printf("\nx%d= %.2lf", i,variable[i]);
            }
        } else {
            printf("\nThere is no consitent solution available.");
        }
    }
    
}