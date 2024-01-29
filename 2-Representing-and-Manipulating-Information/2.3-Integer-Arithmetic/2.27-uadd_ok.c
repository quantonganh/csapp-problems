#include <limits.h>
#include "assert.h"

/* Determine whether arguments can be added without overflow */
int uadd_ok(unsigned x, unsigned y);

int main() {
    int s = uadd_ok(UINT_MAX, 1);
    assert(s == 0);

    s = uadd_ok(UINT_MAX-1, 1);
    assert(s == 1);
}

int uadd_ok(unsigned x, unsigned y) {
    unsigned sum = x + y;
    return sum >= x;
}
