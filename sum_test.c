#include <stdio.h>
#include <stdlib.h>
#define size(a,t) (sizeof(a) / sizeof(t))

/**
 * Returns sum of array of int
 */
int sum_array(int* array, int n);

int sum_array_c(int* array, int n)
{
    int sum = 0;
    for (int i = 0 ; i < n ; i++) {
        sum += array[i];
    }
    return sum;
} // end sum_array_c

/**
 * Returns non zero if assertion is false
 */
int assert_sum(int* array, int n, int expected)
{
    int actual = sum_array(array, n);
    if (actual != expected) {
        fprintf(stderr, "sum_array([");
        if (n > 0) {
            fprintf(stderr, "%d", array[0]);
        }

        for (int i = 1 ; i < n ; i++) {
            fprintf(stderr, ", %d", array[i]);
        } 

        fprintf(stderr, "]) is equal to %d, expected %d\n",
                actual, expected);

        return 1;
    } // end if
    return 0;
} // end assert_sum

int main (int argc, char* argv[])
{
    int has_errors = 0;
    int positive_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int positive_array_n = size(positive_array, int);
    has_errors |= assert_sum(positive_array, positive_array_n,
                             sum_array_c(positive_array, positive_array_n));
    
    int negative_array[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
    int negative_array_n = size(negative_array, int);
    has_errors |= assert_sum(negative_array, negative_array_n,
                             sum_array_c(negative_array, negative_array_n));
    
    int zero_array[] = {0, 0, 0, 0, 0};
    int zero_array_n = size(zero_array, int);
    has_errors |= assert_sum(zero_array, zero_array_n, 
                             sum_array_c(zero_array, zero_array_n));
    
    int one_element_array[] = {5};
    int one_element_n = size(one_element_array,int);
    has_errors |= assert_sum(one_element_array, one_element_n, 
                             sum_array_c(one_element_array, one_element_n));

    if (has_errors) {
        fprintf(stderr, "One or more tests failed.\n");
    } else {
        printf("ALL TESTS PASSED.\n");
    }

    return has_errors;
}
