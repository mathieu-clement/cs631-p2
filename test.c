#include <stdio.h>

int sum_array(int *array, int n);

int main (int argc, char* argv[])
{
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(int);
    printf("sum_array = %d\n", sum_array(array, n));
    return 0;
}
