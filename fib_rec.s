
.global fib_rec
.func fib_rec

# int fib_rec (int n)
fib_rec:
    # r0 : n => int
    cmp r0, #0      /* if n == 0 */
    bxeq lr         /*     return 0 */
    cmp r0, #1      /* if n == 1 */
    bxeq lr         /*     return 1 */

    # r1 : copy of n
    mov r1, r0
    # Preserve r1
    sub sp, #8      /* "Allocate space on stack for r1, taking care of alignment */
    str r1, [sp]

    sub r0, #1      /* n - 1 */
    bl fib_rec      /* fib_rec(n-1) */

    # r2 : result of fib_rec(n-1)
    mov r2, r0
    # Restore n from stack */
    add sp, $8
    ldr r1, [sp]
    # Preserve r2
    add sp, #4      /* Move sp to position we'll store r2 */
    str r2, [sp]    /* Store r2 */
    sub sp, #4      /* Keep sp 8 byte aligned */

    sub r0, r1, r2  /* n - 2 */
    bl fib_rec      /* fib_rec(n-2) */

    # r0 holds   result of fib_rec(n-2)
    # Bring back result of fib_rec(n-1) to r1
    add sp, #4
    ldr r1, [sp]
    # Return sp to original position
    add sp, #4

    # Set return value
    add r0, r1, r0
    bx lr

