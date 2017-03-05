Project 02  - 5 ARM assembly utilities
======================================

Compile and test
----------------

A Makefile is provided. To compile and test the program:

    make test

or

    make clean all test

`function()` is the assembly version, and `function_c()` is the C version.

In the case of find_str, a reference version that uses strstr is provided.

When a test uses more than 15 elements (such as the one with more than 1,000 elements), the function's parameter list is ellipsed ("...")

Make will return a non zero error code if any of the tests fail.
