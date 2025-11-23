/*7. Write a MPI Program to demonstration of Broadcast operation. */


#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int rank, size;
    int number;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) {
        number = 50;
        printf("Process %d broadcasting number %d to all other processes.\n", rank, number);
    }

    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received number %d\n", rank, number);

    MPI_Finalize();
    return 0;
}

/*Step 1: Save the MPI Program : mpi_broadcast_demo.c 
Step 2: Compile the MPI Program:   
mpicc mpi_broadcast_demo.c -o mpi_broadcast_demo  
Step 3: Run the MPI Program: mpirun -np 4 ./mpi_broadcast_demo 
Output:*/

/**/