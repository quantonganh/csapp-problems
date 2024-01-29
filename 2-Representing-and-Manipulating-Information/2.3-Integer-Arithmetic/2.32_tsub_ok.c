#include <limits.h>
#include <assert.h>

int tsub_ok(int x, int y);

int main() {
    int is_overflow = tsub_ok(-1, INT_MIN);
    assert(is_overflow == 1);
}

int tadd_ok(int x, int y) {
    int s = x + y;
    if (x < 0 && y < 0 && s > 0) {
        return 0;
    }

    if (x > 0 && y > 0 && s < 0) {
        return 0;
    }

    return 1;
}

int tsub_ok(int x, int y) {
    return tadd_ok(x, -y);
}

