#include "stdio.h"

int main() {
    unsigned int x = 0x01234567;
    char *c = (char*) &x;

    if (*c == 0x01) {
        printf("big endian");
    } else {
        printf("little endian");
    }
}
