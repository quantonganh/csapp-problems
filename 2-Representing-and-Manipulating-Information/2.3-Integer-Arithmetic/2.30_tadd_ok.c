#include <limits.h>
#include <assert.h>

/* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y);

int main() {
    int s = tadd_ok(INT_MIN, -1);
    assert(s == 0);

    s = tadd_ok(INT_MAX, 1);
    assert(s == 0);

    s = tadd_ok(INT_MIN + 1, INT_MAX);
    assert(s == 1);
}

int tadd_ok(int x, int y) {
    int sum = x + y;
    if (x < 0 && y < 0 && sum > 0) {
        return 0;
    }

    if (x > 0 && y > 0 && sum < 0) {
        return 0;
    }

    return 1;
}
