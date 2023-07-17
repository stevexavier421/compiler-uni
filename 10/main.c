// -fopenmp
#include <stdio.h>
#include <omp.h>

int main() {
    int n = 100; 
    int sum = 0; 

    // Enable parallelism and distribute the loop iterations across multiple threads
    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("Sum: %d\n", sum);

    return 0;
}
