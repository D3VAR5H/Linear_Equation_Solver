void divide_row(double **augmented_matrix, int cols, int i, int j){
    int k = cols;
    while(k >= 0){
        augmented_matrix[i][k] = augmented_matrix[i][k]/augmented_matrix[i][j];
        k--;
    }
}