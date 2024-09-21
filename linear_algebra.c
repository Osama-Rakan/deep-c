#include <stdio.h>

void linear_algebra_print_matrix(double* mat, int* rows, int* cols){
  for(int i=0;i<*rows;i++){
    for(int j=0;j<*cols;j++){
      printf("%lf\t", mat[i * *cols + j]);
    }
    printf("\n");
  }
}

void linear_algebra_matrix_multiplication(double* mat1, int* rows1, int* cols1, double* mat2, int* rows2, int* cols2, double* results){
  for(int i=0;i<*rows1;i++){
    for(int j=0;j<*cols2;j++){
      results[i * *cols2 + j] = 0;
      for(int k=0;k<*cols1;k++){
        results[i * *cols2 + j] += mat1[i * *cols1 + k] * mat2[k * *cols2 + j];
      }
    }
  }
}

