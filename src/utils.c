#include "utils.h"
#include <stdio.h>

void utils_swap_int_variables(int* a, int* b){  
  *a = *a^*b; // a XOR b
  *b = *a^*b; // (a XOR b) XOR b = a XOR (b XOR b) = a XOR 0 = a
  *a = *a^*b; // (a XOR b) XOR (a XOR b) XOR b = (a XOR a) XOR (b XOR b) XOR b = 0 XOR 0 XOR b = b
}