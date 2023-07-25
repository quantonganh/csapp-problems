#include "stdio.h"

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    printf("x: %d, y: %d\n", *x, *y);
    *x = *x ^ *y;
    printf("x: %d, y: %d\n", *x, *y);
    *y = *x ^ *y;
    printf("x: %d, y: %d\n", *x, *y);
}

int main() {
    int x = 1;
    int y = 2;
    printf("x: %d, y: %d\n", x, y);
    inplace_swap(&x, &y);
}
