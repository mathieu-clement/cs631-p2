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
    for (int i = 0 ; i < 20 ; i++) {
        printf("fib_rec(%d)   = %d\n", i, fib_rec(i));
        printf("fib_rec_c(%d) = %d\n", i, fib_rec_c(i));
        printf("\n");
    }
}

