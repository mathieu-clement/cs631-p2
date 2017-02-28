#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#define size(a,t) (sizeof(a) / sizeof(t))

/**
 * Returns max from array of int
 */
int find_max(int* array, int n);

int find_max_c(int* array, int n)
{
    int max = array[0];
    for (int i = 1 ; i < n ; ++i) {
        if (array[i] > max) {
            max = array[i];
        } // end if
    } // end for
    return max;
} // end find_max_c

/**
 * Returns non zero if assertion is false
 */
int assert_find_max(int* array, int n)
{
    int actual = find_max(array, n);
    int expected = find_max_c(array, n);

    printf("find_max(");
    print_int_array(array, n);
    printf("]) = %d\n", actual);
    
    printf("find_max_c(");
    print_int_array(array, n);
    printf(") = %d\n", expected);
    puts("\n");

    if (actual != expected) {
        fprintf(stderr, "]) is equal to %d, expected %d\n",
                actual, expected);

        return 1;
    } // end if
    return 0;
} // end assert_find_max

int main (int argc, char* argv[])
{
    int has_errors = 0;
    
    int one_element_array[] = {5};
    int one_element_n = size(one_element_array,int);
    has_errors |= assert_find_max(one_element_array, one_element_n);

    int positive_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int positive_array_n = size(positive_array, int);
    has_errors |= assert_find_max(positive_array, positive_array_n);
    
    int negative_array[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
    int negative_array_n = size(negative_array, int);
    has_errors |= assert_find_max(negative_array, negative_array_n);
    
    int zero_array[] = {0, 0, 0, 0, 0};
    int zero_array_n = size(zero_array, int);
    has_errors |= assert_find_max(zero_array, zero_array_n);

    int thousands_n = 1001;
    int* thousands_array = malloc(sizeof(int) * thousands_n);
    for (int i = 0 ; i < thousands_n ; i++) {
       thousands_array[i] = i; 
    }

    has_errors |= assert_find_max(thousands_array, thousands_n);

    if (has_errors) {
        fprintf(stderr, "One or more tests failed.\n");
    } else {
        printf("ALL TESTS PASSED.\n");
    }

    return has_errors;
} // end main

