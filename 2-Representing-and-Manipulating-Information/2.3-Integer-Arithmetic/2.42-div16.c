#include <stdio.h>
#include <assert.h>

int div16(int x) {
    int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;
}

int main() {
    int r = div16(12340);
    printf("r: %d\n", r);
    assert(r == 771);

    r = div16(-12340);
    printf("r: %d\n", r);
    assert(r == -771);
}
