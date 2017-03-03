#include <stdio.h>
#include <stdlib.h>

int fib_rec (int n);

int fib_rec_c (int n)
{
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fib_rec(n - 1) + fib_rec(n - 2);
    }
}

int main (int argc, char* argv[])
{
    int fail = 0;
    for (int i = 0 ; i < 20 ; i++) {
        int asm_result = fib_rec(i);
        int c_result = fib_rec_c(i);
        printf("fib_rec(%d)   = %d\n", i, asm_result);
        printf("fib_rec_c(%d) = %d\n", i, c_result);
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

