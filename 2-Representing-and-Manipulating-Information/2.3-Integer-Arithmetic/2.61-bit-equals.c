#include <assert.h>

int any_bit_equals_1(int x) {
    return x || 0;
}

int any_bit_equals_0(int x) {
    return !!~x;
}

int any_bit_in_lsb_equals_1(int x) {
    return any_bit_equals_1(x & 0xFF);
}

int any_bit_in_msb_equals_0(int x) {
    return !(x & 0xFF);
}

int main() {
    int x = 1;
    assert(any_bit_equals_1(x));
    x = 0;
    assert(!any_bit_equals_1(x));

    x = 0;
    assert(any_bit_equals_0(x));
    x = ~0;
    assert(!any_bit_equals_0(x));

    x = 0x123456ff;
    assert(any_bit_in_lsb_equals_1(x));
    x = 0x1235600;
    assert(!any_bit_in_lsb_equals_1(x));

    x = 0x12345600;
    assert(any_bit_in_msb_equals_0(x));
    x = ~0;
    assert(!any_bit_in_msb_equals_0(x));
}