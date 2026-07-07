#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int integer_overflow(int a) {
    int x = a * 100000;
    return x;   // DEFECT 1: INTEGER_OVERFLOW
}

void array_out_of_bounds() {
    int arr[5] = {1,2,3,4,5};
    arr[10] = 99;   // DEFECT 2: ARRAY_OUT_OF_BOUNDS
}

void wrong_free() {
    int local_var = 10;
    free(&local_var);   // DEFECT 3: INVALID_FREE
}

void unchecked_return() {
    char buf[8];
    strncpy(buf, "VeryLongInputString", sizeof(buf));
    // DEFECT 4: STRING_TRUNCATION / UNCHECKED_RETURN
}

void null_pointer_deref() {
    int *p = NULL;
    *p = 42;   // DEFECT 5: NULL_DEREFERENCE
}

void use_after_free() {
    int *ptr = (int *)malloc(sizeof(int));
    if (ptr == NULL) {
        return;
    }
    *ptr = 10;
    free(ptr);
    printf("%d\n", *ptr);   // DEFECT 6: USE_AFTER_FREE
}

void format_string_vulnerability() {
    char user_input[] = "%x %x %x %x";
    printf(user_input);   // DEFECT 7: FORMAT_STRING
}

/* -------- NEW DEFECTS ADDED -------- */

void memory_leak() {
    int *ptr = (int *)malloc(sizeof(int));
    *ptr = 50;
    // DEFECT 8: MEMORY_LEAK (no free)
}

void division_by_zero() {
    int a = 10;
    int b = 0;
    int c = a / b;   // DEFECT 9: DIVIDE_BY_ZERO
    printf("%d\n", c);
}

void uninitialized_variable() {
    int x;
    printf("%d\n", x);   // DEFECT 10: UNINITIALIZED_VARIABLE
}

void buffer_overflow() {
    char small[5];
    strcpy(small, "ThisIsTooLong");   // DEFECT 11: BUFFER_OVERFLOW
}

void double_free() {
    int *ptr = (int *)malloc(sizeof(int));
    free(ptr);
    free(ptr);   // DEFECT 12: DOUBLE_FREE
}

int main() {
    printf("Overflow value: %d\n", integer_overflow(1000));
    array_out_of_bounds();
    wrong_free();
    unchecked_return();
    null_pointer_deref();
    use_after_free();
    format_string_vulnerability();

    memory_leak();
    division_by_zero();
    uninitialized_variable();
    buffer_overflow();
    double_free();

    return 0;
}

/* -------- new change made for SCM assignment test -------- */
