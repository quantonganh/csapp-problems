#include <stdio.h>
#include <assert.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    if (i >= 0 && i < sizeof(unsigned)) {
        // Clear the i-th byte in x
        x &= ~(0xFF << (i * 8));
        // Replace it with b
        x |= (b << (i * 8));
    }

    printf("0x%X\n", x);
    return x;
}

int main() {
    unsigned result = replace_byte(0x12345678, 2, 0xAB);
    assert(result == 0x12AB5678);

    result = replace_byte(0x12345678, 0, 0xAB);
    assert(result == 0x123456AB);
}