#include <stdio.h>
#include <stdlib.h>

int fib_iter (int n);

int fib_iter_c (int n)
{
    if (n == 0) return 0; // special case, avoids issues with table[1]

    int table[n+1];
    table[0] = 0;
    table[1] = 1;
    for (int i = 2 ; i < n+1 ; i++) {
        table[i] = table[i-1] + table[i-2];
    }
    return table[n];
}

int main (int argc, char* argv[])
{
    int fail = 0;
    for (int i = 0 ; i < 20 ; i++) {
        int asm_result = fib_iter(i);
        int c_result = fib_iter_c(i);
        printf("fib_iter(%d)   = %d\n", i, asm_result);
        printf("fib_iter_c(%d) = %d\n", i, c_result);
        printf("\n");
        if (asm_result != c_result) {
            fail = 1;
        }
    }

    if (fail) {
        fprintf(stderr, "One or more tests failed.\n");
    } else {
        printf("All tests passed.\n");
    }

    return fail;
}

