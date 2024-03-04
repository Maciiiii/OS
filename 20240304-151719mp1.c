#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char
L *argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Calculate the number of elements each process will handle
    int elements_per_process = 1000 / size;
    
    // Initialize a seed for random number generation based on the rank
    srand(rank);

    // Generate random numbers on each process
    int local_numbers[elements_per_process];
    for (int i = 0; i < elements_per_process; i++) {
        local_numbers[i] = rand();
    }

    // Gather all local numbers to process 0
    int all_numbers[1000];
    MPI_Gather(local_numbers, elements_per_process, MPI_INT, all_numbers, elements_per_process, MPI_INT, 0, MPI_COMM_WORLD);

    // Print the numbers on process 0
    if (rank == 0) {
        printf("Generated Numbers:\n");
        for (int i = 0; i < 1000; i++) {
            printf("%d ", all_numbers[i]);
        }
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}