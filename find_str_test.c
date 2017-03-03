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

void check(char* s, char* sub)
{
//    printf("find_str(\"%s\", \"%s\") = %d\n", s, sub, find_str(s, sub));
    printf("find_str_c(\"%s\", \"%s\") = %d\n", s, sub, find_str_c(s, sub));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", s, sub, find_str_c_stdlib(s, sub));
    printf("\n");    
}

int main (int argc, char* argv[])
{
    // Contains

    check("abcde", "a");

    check("abcde", "abc");

    check("abcde", "abcde");

    check("abcde", "bcd");

    check("abcde", "cde");

    // NOT contains

    check("abcde", "xyz");

    check("abcde", "bcq");

    check("abcde", "def");

    check("abcde", "defhijklmn");

    check("abcdef", "abcdef");


}


