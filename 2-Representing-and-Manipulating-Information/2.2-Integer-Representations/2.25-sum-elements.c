#include "stdio.h"

float sum_elements(float a[], unsigned length) {
    float result = 0;

    for (int i = 0; i <= length-1; i++)
        result += a[i];
    return result;
}

int main() {
    float a[0];
    printf("sum: %.1f\n", sum_elements(a, 0));
}