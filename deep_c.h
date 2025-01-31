#include <stddef.h>
void print_row_vector(double* vec, size_t total_size);
double dot_product(double* vec1, double* vec2, size_t total_size);
void print_matrix(double* mat, size_t total_size, size_t row_size);
void matrix_multiplication(double* mat1, size_t total_size1, size_t row_size1, double* mat2, size_t total_size2, size_t row_size2, double* results);
void swap_int_variables(int* a, int* b);