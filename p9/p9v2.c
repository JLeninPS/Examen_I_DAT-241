#include"stdio.h"
#include"mpi.h"

void main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    int cantidad, procesador;
    int N, T, m, res;
    
    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    
    N = 50;//Tamanio de la serie

    T = 2 * N; //Ultimo elemento de la serieS
    m = (N % cantidad == 0) ? N / cantidad : N / cantidad + 1;

    int V[m];

    V[0] = (procesador * m + 1) * 2;
    if(V[0] <= T)
    {
        for(int i = 1; i < m; i++)
        {
            V[i] = V[i - 1] + 2;
        }

        printf("Procesador %d: ", procesador);
        for(int i = 0; i < m; i++)
        {
            res = V[i];
            printf("%d, ", V[i]);
            if(res == T) break;
        }
    }

    MPI_Finalize();
}