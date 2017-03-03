#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int min(int a, int b)
{
    return a > b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

/**
 * Print array of int. Example: "[1, 2, 4]"
 * 
 * No newline added at the end.
 */
void print_int_array(int* array, int length)
{
    printf("[");
    if (length > 0) {
        printf("%d", array[0]);
    }

    int last;
    if (length > 15) {
        last = 15;
    } else {
        last = length - 1;
    }

    for (int i = 1 ; i <= last ; i++) {
        printf(", %d", array[i]);
    } 

    if (length > 15) {
        printf("...");
    }

    printf("]");

}

