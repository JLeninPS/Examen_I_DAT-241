#include"stdio.h"
#include"mpi.h"

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);

    int procesador, cantidad;
    int N, m, p, a, b, res;
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);

    freopen("datos.in", "r", stdin);

    scanf("%d", &N);

    int M[N][N];
    int V[N];
    // int R[N];
    int AUX[N];
    int I[2];//Intervalo

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            scanf("%d", &M[i][j]);
    }
    for(int j = 0; j < N; j++)
        scanf("%d", &V[j]);
    
    if(cantidad > 1 && cantidad < N)
    {
        
        if(procesador == 0)
        {
            m = N / (cantidad - 1);
            p = N;
            
            a = 0;
            b = 0;
            for(int i = 1; i < cantidad; i++)
            {
                b = (i == (cantidad - 1)) ? N : b + m;
                I[0] = a;
                I[1] = b;
                MPI_Send(I, 2, MPI_INT, i, 0, MPI_COMM_WORLD);
                a += m;
            }

            printf("\nMatriz de dimension: %dx%d\n", N, N);
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++)
                    printf("\t%d", M[i][j]);
                printf("\n");
            }
            printf("\nMatriz de dimension: %dx1\n", N);
            for(int i = 0; i < N; i++)
                printf("\n\t%d", V[i]);

            printf("\n");

            printf("\n=======RESULTADO=======\n");
            printf("\nMatriz de dimension: %dx1\n", N);
            
            for(int i = 1; i < cantidad; i++){
                MPI_Send(AUX, N, MPI_INT, i, 0, MPI_COMM_WORLD);
                MPI_Recv(AUX, N, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            }
            for(int j = 0; j < N; j++){
                printf("\n\t%d", AUX[j]);
            }
        }
        else
        {
            MPI_Recv(I, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Recv(AUX, N, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            for(int i = I[0]; i < I[1]; i++){
                res = 0;
                for(int j = 0; j < N; j++){
                    res += M[i][j] * V[j];
                }
                AUX[i] = res;
            }
            MPI_Send(AUX, N, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }
    else
    {
        if(procesador == 0)
        {
            printf("\nMatriz de dimension: %dx%d\n", N, N);
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++)
                    printf("\t%d", M[i][j]);
                printf("\n");
            }
            printf("\nMatriz de dimension: %dx1\n", N);
            for(int i = 0; i < N; i++)
                printf("\n\t%d", V[i]);

            printf("\n");

            printf("\n=======RESULTADO=======\n");
            printf("\nMatriz de dimension: %dx1\n", N);
            res = 0;
            for(int i = 0; i < N; i++){
                res = 0;
                for(int j = 0; j < N; j++){
                    res += M[i][j] * V[j];
                }
                printf("\n\t%d", res);
            }
        }
    }

    MPI_Finalize();
}