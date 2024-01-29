#include <stdio.h>
#include <time.h>

int multiplication(int x) {
    return x * 14;
}

int shifting(int x) {
    return (x << 4) - (x << 1);
}

int main() {
    clock_t start_time, end_time;
    double cpu_time_used;
    
    start_time = clock();

    multiplication(10);

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("multiplication: %f seconds\n", cpu_time_used);

    start_time = clock();

    shifting(10);

    end_time = clock();
    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("shifting: %f seconds\n", cpu_time_used);
}
