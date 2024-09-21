#include "linear_algebra.h"

void print_matrix(double* mat, int* rows, int* cols) { linear_algebra_print_matrix(mat, rows, cols); }

void matrix_multiplication(double* mat1, int* rows1, int* cols1, double* mat2, int* rows2, int* cols2, double* results) { linear_algebra_matrix_multiplication(mat1, rows1, cols1, mat2, rows2, cols2, results); }

