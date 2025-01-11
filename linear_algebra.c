#include <stdio.h>

void linear_algebra_print_matrix(double* mat, size_t total_size, size_t row_size){
  int rows = total_size / row_size;
  int cols = row_size / sizeof(double);

  for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
      printf("%lf\t", mat[i * cols + j]);
    }
    printf("\n");
  }
  printf("\n");
}

void linear_algebra_matrix_multiplication(double* mat1, size_t total_size1, size_t row_size1, double* mat2, size_t total_size2, size_t row_size2, double* results){
  int rows1 = total_size1 / row_size1;
  int cols1 = row_size1 / sizeof(double);
  int cols2 = row_size2 / sizeof(double);

  for(int i=0;i<rows1;i++){
    for(int j=0;j<cols2;j++){
      results[i * cols2 + j] = 0;
      for(int k=0;k<cols1;k++){
        results[i * cols2 + j] += mat1[i * cols1 + k] * mat2[k * cols2 + j];
      }
    }
  }
}

