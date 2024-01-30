#include <stdio.h>
#include <assert.h>

int get_lsb(int x) {
    int lsb = x & 0xFF;
    printf("0x%X\n", lsb);
    return lsb;
}

int zero_lsb(int x) {
    int zero_lsb = x & 0xFFFFFF00;
    printf("0x%X\n", zero_lsb);
    return zero_lsb;
}

int main() {
    unsigned int x = 0x89ABCDEF;
    unsigned int y = 0x76543210;

    unsigned result = zero_lsb(y) | get_lsb(x);
    printf("0x%X\n", result);
    assert(result == 0x765432EF);
}