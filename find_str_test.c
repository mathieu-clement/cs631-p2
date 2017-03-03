#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int find_str(char *s, char *sub);

int find_str_c(char *s, char *sub)
{
    int start = 0;

    while (s[start] != 0 && s[start] != sub[0]) {
        start++;
    }

    if (s[start] == 0) {
        return -1;
    }

    int len = 0;

    while (s[start] != 0) {
        int i;

        for (i = start ; s[i] != 0 && sub[len] != 0 && s[i] == sub[len]; i++, len++);
        

        if (sub[len] != 0) {
            start++;
        } else {
            return start;
        }
    }

    return -1;

} // end find_str_c

// Using readily available C libraries
// Code from http://stackoverflow.com/a/7500951/753136
int find_str_c_stdlib(char *s, char *sub)
{
    char *result = strstr(s, sub);
    int pos = result - s;
    return max(pos, -1);
}

/*
 * Check find_str with three different implementations.
 * Returns non zero if NOT all implementations return the same result.
 */
int check(char* s, char* sub)
{
    int asm_result = find_str(s, sub);
    printf("find_str(\"%s\", \"%s\") = %d\n", s, sub, asm_result);
    int my_c_impl_result = find_str_c(s, sub);
    printf("find_str_c(\"%s\", \"%s\") = %d\n", s, sub, my_c_impl_result);
    int stdlib_ref_result = find_str_c_stdlib(s, sub);
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", s, sub, stdlib_ref_result);    
    printf("\n");    

    if (asm_result == my_c_impl_result && my_c_impl_result == stdlib_ref_result) {
        return 0;
    } else {
        return 1;
    }
}

int main (int argc, char* argv[])
{
    int fail = 0;

    // Contains

    fail |= check("abcde", "a");
    fail |= check("abcde", "abc");
    fail |= check("abcde", "abcde");
    fail |= check("abcde", "bcd");
    fail |= check("abcde", "cde");

    // NOT contains

    fail |= check("abcde", "xyz");
    fail |= check("abcde", "bcq");
    fail |= check("abcde", "def");
    fail |= check("abcde", "defhijklmn");
    fail |= check("abcdef", "abcdef");

    if (!fail) {
        printf("All tests passed.\n");
    } else {
        printf("One or more tests failed.\n");
    }

    return fail;
}


