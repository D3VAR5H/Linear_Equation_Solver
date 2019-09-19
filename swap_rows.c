void swap_rows(double **matrix, int cols, int i, int j) {
    int k;
    double temp;
    for (k = 0; k <= cols; k++) {
        temp = matrix[i][k];
        matrix[i][k] = matrix[j][k];
        matrix[j][k] = temp;
    }
}