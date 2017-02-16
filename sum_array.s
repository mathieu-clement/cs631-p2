
.global sum_array
.func sum_array

# int sum_array(int *array, int n)
sum_array:
    # r0 : pointer to array (address is incremented directly to access elements) 
    # r1 : size of array => int
    # r2 : sum => int
    # r3 : i (for loop index) => int
    # r4 : value of array[r0]
    mov r2, $0 // sum = 0
    mov r3, $0 // i = 0

    cmp r3, r1 // i == n
    beq end

loop:
    ldr r4, [r0], $4
    add r2, r4 // sum += array[i]
    cmp r3, r1 // i < n
    add r3, $1
    ble loop

end:
    mov r0, r2
    bx lr
