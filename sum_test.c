#include <stdio.h>
#include <stdlib.h>
#define size(a,t) (sizeof(a) / sizeof(t))

/**
 * Returns sum of array of int
 */
int sum_array(int *array, int n);

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
    has_errors |= assert_sum(positive_array, size(positive_array,int), 45);
    
    int negative_array[] = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
    has_errors |= assert_sum(negative_array, size(negative_array,int), -45);
    
    int zero_array[] = {0, 0, 0, 0, 0};
    has_errors |= assert_sum(zero_array, size(zero_array, int), 0);
    
    int one_element_array[] = {5};
    has_errors |= assert_sum(one_element_array, size(one_element_array,int), 5);

    if (has_errors) {
        fprintf(stderr, "One or more tests failed.\n");
    } else {
        printf("ALL TESTS PASSED.\N");
    }

    return has_errors;
}
