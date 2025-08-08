#include <stdio.h>
#include <omp.h>

int main() {
    int n;
    printf("Enter number of threads: ");
    scanf("%d", &n);

    printf("\nSequential Hello World:\n");
    for (int i = 0; i < n; i++) {
        printf("Hello World from thread %d (Sequential)\n", i);
    }

    printf("\nParallel Hello World:\n");
    omp_set_num_threads(n);

    #pragma omp parallel
    {
        int id = omp_get_thread_num();
        printf("Hello World from thread %d (Parallel)\n", id);
    }

    return 0;
}
