#include "stdio.h"
#include "cmocka.h"

int are_equal(int x, int y) {
    return !(x ^ y);
}

void test_not_equal(void **state) {
    assert_int_equal(0, are_equal(0x55, 0x46));
}

void test_equal(void **state) {
    assert_int_equal(1, are_equal(0x55, 0x55));
}

int main() {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_not_equal),
        cmocka_unit_test(test_equal),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
