#include <stdio.h>
#include "deep_c.h"

int main(){
  double row_vector1[3] = {0.3, 0.6, 0.1};
  double row_vector2[3] = {0.8, 0.7, 0.5};
  print_row_vector(row_vector1, sizeof(row_vector1));
  print_row_vector(row_vector2, sizeof(row_vector2));
  printf("\n");

  double d = dot_product((double*)row_vector1, (double*)row_vector2, sizeof(row_vector1));
  printf("%lf\n", d);

  double mat1[2][3]={{0.7778, 5, 4},
                    {0.8, 0.5555, 0.99999}};

  double mat2[3][4]={{6, 7.997854, 78, 99},
                    {8, 9, 78, 883},
                    {11, 7.66, 73824, 8756}};

  // 8*6=48 total size, 3*8=24 rows size, 8 bytes double size
  // number of rows = 48/24 = 2
  // number of cols = 24/8 = 3
  size_t mat1_total_size = sizeof(mat1), mat1_row_size = sizeof(mat1[0]); 
  print_matrix((double*)mat1, mat1_total_size, mat1_row_size);

  size_t mat2_total_size = sizeof(mat2), mat2_row_size = sizeof(mat2[0]); 
  print_matrix((double*)mat2, mat2_total_size, mat2_row_size);
  
  int rows1 = sizeof(mat1) / sizeof(mat1[0]);
  int cols1 = sizeof(mat1[0]) / sizeof(mat1[0][0]);

  int rows2 = sizeof(mat2) / sizeof(mat2[0]);
  int cols2 = sizeof(mat2[0]) / sizeof(mat2[0][0]);

  double matrix_multiplication_results[rows1][cols2];

  matrix_multiplication((double*)mat1, mat1_total_size, mat1_row_size, (double*)mat2,  mat2_total_size, mat2_row_size, (double*)matrix_multiplication_results);
  print_matrix((double*)matrix_multiplication_results, sizeof(matrix_multiplication_results), sizeof(matrix_multiplication_results[0]));


  double mat3[2][3]={{0.6787, 1, 8},
                    {0.123, 0.34556, 0.12355}};

  double element_wise_product_results[2][3];

  element_wise_product((double*)mat1, (double*)mat3, (double*)element_wise_product_results, sizeof(mat1), sizeof(mat1[0]));
  print_matrix((double*)element_wise_product_results, sizeof(element_wise_product_results), sizeof(element_wise_product_results[0]));

  double matrix_transpose_results[cols1][rows1];
  print_matrix((double*)mat1, sizeof(mat1), sizeof(mat1[0]));
  matrix_transpose((double*)mat1, sizeof(mat1), sizeof(mat1[0]), (double*)matrix_transpose_results);
  print_matrix((double*)matrix_transpose_results, sizeof(matrix_transpose_results), sizeof(matrix_transpose_results[0]));

  double matrix_flatten_results[rows1*cols1];
  print_matrix((double*)mat1, sizeof(mat1), sizeof(mat1[0]));
  matrix_flatten((double*)mat1, sizeof(mat1), sizeof(mat1[0]), (double*)matrix_flatten_results);
  print_row_vector((double*)matrix_flatten_results, sizeof(matrix_flatten_results));

  int y = 2;
  int z = 9;
  printf("Before swapping: x=%d, y=%d\n", y, z);
  swap_int_variables(&y, &z);
  printf("After swapping: x=%d, y=%d\n", y, z);

  return 0;
}