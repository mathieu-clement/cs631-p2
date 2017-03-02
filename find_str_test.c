#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

        for (i = start ; s[i] != 0 && sub[len] != 0 ; i++) {
            if (s[i] == sub[len]) {
                len++;
            } else {
                break;
            }
        }

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
    return pos;
}

int main (int argc, char* argv[])
{
    // Contains

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "a", find_str_c("abcde", "a"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "a", find_str_c_stdlib("abcde", "a"));

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "abc", find_str_c("abcde", "abc"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "abc", find_str_c_stdlib("abcde", "abc"));

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "abcde", find_str_c("abcde", "abcde"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "abcde", find_str_c_stdlib("abcde", "abcde"));

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "bcd", find_str_c("abcde", "bcd"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "bcd", find_str_c_stdlib("abcde", "bcd"));

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "cde", find_str_c("abcde", "cde"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "cde", find_str_c_stdlib("abcde", "cde"));

    // NOT contains

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "xyz", find_str_c("abcde", "xyz"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "xyz", find_str_c_stdlib("abcde", "xyz"));

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "bcq", find_str_c("abcde", "bcq"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "bcq", find_str_c_stdlib("abcde", "bcq"));

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "def", find_str_c("abcde", "def"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "def", find_str_c_stdlib("abcde", "def"));

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "defhijlklmn", find_str_c("abcde", "defhijklmn"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "defhijlklmn", find_str_c_stdlib("abcde", "defhijklmn"));

    printf("find_str_c(\"%s\", \"%s\") = %d\n", "abcde", "abcdef", find_str_c("abcdef", "abcdef"));
    printf("find_str_c_stdlib(\"%s\", \"%s\") = %d\n", "abcde", "abcdef", find_str_c_stdlib("abcdef", "abcdef"));


}


