#include "stdio.h"
#include "strings.h"

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    for (int i = 0; i < len; i++) {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

int main() {
    const char *m = "mnopqr";
    show_bytes((byte_pointer) m, strlen(m));

    return 0;
}