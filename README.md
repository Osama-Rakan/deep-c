# Deep C

Deep C is a personal project I'm working on to implement mathematical, machine learning, and deep learning algorithms from scratch in C.

Why? Because, why not? I'm having fun :).

## Linear Algebra
* Dot product between two row vectors (a⋅u)
* 2D matrix multiplication (AB)
* Element-wise product (A∘B)
```C
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

  double results[rows1][cols2];

  matrix_multiplication((double*)mat1, mat1_total_size, mat1_row_size, (double*)mat2,  mat2_total_size, mat2_row_size, (double*)results);
  print_matrix((double*)results, sizeof(results), sizeof(results[0]));

  double mat3[2][3]={{0.6787, 1, 8},
                    {0.123, 0.34556, 0.12355}};

  double results2[2][3];

  element_wise_product((double*)mat1, (double*)mat3, (double*)results2, sizeof(mat1), sizeof(mat1[0]));
  print_matrix((double*)results2, sizeof(results2), sizeof(results2[0]));

  return 0;
}
```

## General utils
* Swapping two integers using bitwise XOR
```C
#include <stdio.h>
#include "deep_c.h"

int main(){
  int y = 2;
  int z = 9;
  printf("Before swapping: x=%d, y=%d\n", y, z);
  swap_int_variables(&y, &z);
  printf("After swapping: x=%d, y=%d\n", y, z);

  return 0;
}
```

## How to run
```
gcc -o app main.c deep_c.c linear_algebra.c utils.c
./app
```
