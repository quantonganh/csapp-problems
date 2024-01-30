#include "show-bytes.h"

int main() {
    int a = 0x12345678;
    byte_pointer ap = (byte_pointer) &a;
    show_bytes(ap, 1);
    show_bytes(ap, 2);
    show_bytes(ap, 3);

    return 0;
}