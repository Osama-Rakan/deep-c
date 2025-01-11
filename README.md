# Deep C

Deep C is a personal project I'm working on to implement mathematical, machine learning, and deep learning algorithms from scratch in C. This project aims to provide efficient, low-level implementations of core algorithms used in data science and AI.

Why? Because, why not? I'm having fun :).

## Linear Algebra

### 2D Matrix Multiplication
```C
#include "deep_c.h"

int main(){
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

  return 0;
}

```

## How to run
```
gcc -o app main.c deep_c.c linear_algebra.c
./app
```
