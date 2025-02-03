#include <stdio.h>

void linear_algebra_print_row_vector(double* vec, size_t total_size){
  const size_t cols = total_size / sizeof(double);
  for(size_t current_col=0;current_col<cols;current_col++){
    printf("%lf\t", vec[current_col]);
  }
  printf("\n");
}

// a ⋅ u
double linear_algebra_dot_product(double* vec1, double* vec2, size_t total_size){
  const size_t cols = total_size / sizeof(double); // two row vectors of the same size, and the number of rows is always 1
  double sum = 0;
  for(size_t current_col=0;current_col<cols;current_col++){
    sum += vec1[current_col] * vec2[current_col];
  }
  return sum;
}

void linear_algebra_print_matrix(double* mat, size_t total_size, size_t row_size){
  const size_t rows = total_size / row_size;
  const size_t cols = row_size / sizeof(double);

  for(size_t current_row=0;current_row<rows;current_row++){
    for(size_t current_col=0;current_col<cols;current_col++){
      printf("%lf\t", mat[current_row * cols + current_col]);
    }
    printf("\n");
  }
  printf("\n");
}

// AB
void linear_algebra_matrix_multiplication(double* mat1, size_t total_size1, size_t row_size1, double* mat2, size_t total_size2, size_t row_size2, double* results){
  const size_t mat1_number_of_rows = total_size1 / row_size1; // same as results_number_of_rows
  const size_t mat1_number_of_cols = row_size1 / sizeof(double);
  const size_t mat2_number_of_cols = row_size2 / sizeof(double); // same as results_number_of_cols

  for(size_t mat1_current_row=0;mat1_current_row<mat1_number_of_rows;mat1_current_row++){
    for(size_t mat2_current_col=0;mat2_current_col<mat2_number_of_cols;mat2_current_col++){
      results[mat1_current_row * mat2_number_of_cols + mat2_current_col] = 0;
      for(size_t mat1_current_col=0;mat1_current_col<mat1_number_of_cols;mat1_current_col++){
        results[mat1_current_row * mat2_number_of_cols + mat2_current_col] += mat1[mat1_current_row * mat1_number_of_cols + mat1_current_col] * mat2[mat1_current_col * mat2_number_of_cols + mat2_current_col];
      }
    }
  }
}

// A ∘ B
void linear_algebra_element_wise_product(double* mat1, double* mat2, double* results, size_t total_size, size_t row_size){
  const size_t rows = total_size / row_size;
  const size_t cols = row_size / sizeof(double);

  for(size_t current_row=0;current_row<rows;current_row++){
    for(size_t current_col=0;current_col<cols;current_col++){
      results[current_row * cols + current_col] = mat1[current_row * cols + current_col] * mat2[current_row * cols + current_col];
    }
  }
}

// Aᵀ
void linear_algebra_matrix_transpose(double* mat, size_t total_size, size_t row_size, double* results){
  const size_t rows = total_size / row_size;
  const size_t cols = row_size / sizeof(double);

  for(size_t current_row=0;current_row<rows;current_row++){
    for(size_t current_col=0;current_col<cols;current_col++){
      results[current_col * rows + current_row] = mat[current_row * cols + current_col];
    }
  }
}