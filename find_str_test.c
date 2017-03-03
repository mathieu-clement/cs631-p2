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
    if (result == NULL) return -1;
    int pos = result - s;
    return pos;
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
    // C compiler stores identical litterals at the same memory location
    // We have to explicitely copy the string to avoid that
    char* abcde = "abcde";
    char* abcde_copy = malloc(strlen("abcde")+1);
    strcpy(abcde_copy, abcde);
    fail |= check(abcde, abcde_copy);
    fail |= check("abcde", "bcd");
    fail |= check("abcde", "cde");
    fail |= check("Time flies like an arrow", "Time");
    fail |= check("Time flies like an arrow", "flies");
    fail |= check("Time flies like an arrow", "arrow");
    fail |= check("Time flies like an arrow", "w");

    // NOT contains

    fail |= check("abcde", "xyz");
    fail |= check("abcde", "bcq");
    fail |= check("abcde", "def");
    fail |= check("abcde", "defhijklmn");
    fail |= check("abcdef", "abcdef");

    if (!fail) {
        printf("All tests passed.\n");
    } else {
        fprintf(stderr, "One or more tests failed.\n");
    }

    return fail;
}


