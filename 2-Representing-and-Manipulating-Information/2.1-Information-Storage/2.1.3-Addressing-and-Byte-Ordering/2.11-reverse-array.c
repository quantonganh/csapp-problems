#include "stdio.h"
#include "cmocka.h"

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void print_array(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
}

void reverse_array(int a[], int cnt) {
    print_array(a, cnt);
    int first, last;
    for (first = 0, last = cnt - 1; first < last; first++, last--) {
        inplace_swap(&a[first], &a[last]);
    }
    print_array(a, cnt);
}

void test_even_length(void **state) {
    int a[] = {1, 2, 3, 4};
    int expected[] = {4, 3, 2, 1};
    size_t size = sizeof(expected) / sizeof(expected[0]);
    reverse_array(a, size);
    assert_memory_equal(a, expected, sizeof(expected));
}

void test_odd_length(void **state) {
    int a[] = {1, 2, 3, 4, 5};
    int expected[] = {5, 4, 3, 2, 1};
    size_t size = sizeof(expected) / sizeof(expected[0]);
    reverse_array(a, size);
    assert_memory_equal(a, expected, sizeof(expected));
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_even_length),
        cmocka_unit_test(test_odd_length),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}