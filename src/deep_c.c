#include "linear_algebra.h"
#include "utils.h"

void print_row_vector(double* vec, size_t total_size) { linear_algebra_print_row_vector(vec, total_size); }

double dot_product(double* vec1, double* vec2, size_t total_size) { return linear_algebra_dot_product(vec1, vec2, total_size); }

void print_matrix(double* mat, size_t total_size, size_t row_size) { linear_algebra_print_matrix(mat, total_size, row_size); }

void matrix_multiplication(double* mat1, size_t total_size1, size_t row_size1, double* mat2, size_t total_size2, size_t row_size2, double* results) { linear_algebra_matrix_multiplication(mat1, total_size1, row_size1, mat2, total_size2, row_size2, results); }

void swap_int_variables(int* a, int* b) { utils_swap_int_variables(a, b); }

void element_wise_product(double* mat1, double* mat2, double* results, size_t total_size, size_t row_size) { linear_algebra_element_wise_product(mat1, mat2, results, total_size, row_size); };

void matrix_transpose(double* mat, size_t total_size, size_t row_size, double* results) { linear_algebra_matrix_transpose(mat, total_size, row_size, results); }

void matrix_flatten(double* mat, size_t total_size, size_t row_size, double* results) { linear_algebra_matrix_flatten(mat, total_size, row_size, results); }