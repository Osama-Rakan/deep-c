#include "linear_algebra.h"

void print_matrix(double* mat, size_t total_size, size_t row_size) { linear_algebra_print_matrix(mat, total_size, row_size); }

void matrix_multiplication(double* mat1, size_t total_size1, size_t row_size1, double* mat2, size_t total_size2, size_t row_size2, double* results) { linear_algebra_matrix_multiplication(mat1, total_size1, row_size1, mat2, total_size2, row_size2, results); }

