#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Existing defects */

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
    // DEFECT 4: STRING_TRUNCATION
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

/* -------- NEW GUARANTEED DEFECT -------- */

void unsafe_gets() {
    char buf[8];
    gets(buf);   // DEFECT 8: UNSAFE_API / BUFFER_OVERFLOW (ALWAYS DETECTED)
}

int main() {
    printf("Overflow value: %d\n", integer_overflow(1000));
    array_out_of_bounds();
    wrong_free();
    unchecked_return();
    null_pointer_deref();
    use_after_free();
    format_string_vulnerability();
    unsafe_gets();
    return 0;
}
