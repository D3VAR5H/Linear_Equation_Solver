void swap_cols(double **matrix, int rows, int i, int j) {
    int k;
    double temp;
    for (k = 0; k < rows; k++) {
        //printf("%d",k);
        temp = matrix[k][i];
        matrix[k][i] = matrix[k][j];
        matrix[k][j] = temp;
    }
}