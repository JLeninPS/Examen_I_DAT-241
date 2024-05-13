#include"stdio.h"
#include"mpi.h"
#include"math.h"

int main(int argc, char *argv[])
{
    MPI_Init(&argc, &argv);
    
    int cantidad, procesador, p, m;
    long long N, n, count; //Tamanio maximo de long long 10 digitos
    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);

    N = 30;

    if (cantidad > 1 && N > (cantidad - 1))
    {
        m = (N % (cantidad - 1) == 0) ? N / (cantidad - 1): N / (cantidad - 1) + 1;
        long long fibo[m];
        
        if (procesador == 0)
        {
            count = 0;
            printf("\n");
            for (int i = 1; i < cantidad; i++)
            {
                MPI_Recv(fibo, m, MPI_LONG_LONG, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                for (int j = 0; j < m; j++)
                {
                    if (count == N) break;
                    else printf(" %d", fibo[j]);
                    count++;
                }
                // printf("\n"); 
            }

        }
        else
        {
            n = m * (procesador - 1);
            fibo[0]= ((1/sqrt(5)) * pow((1 + sqrt(5))/2, n)) - ((1/sqrt(5)) * pow((1 - sqrt(5))/2, n));
            fibo[1]= ((1/sqrt(5)) * pow((1 + sqrt(5))/2, (n + 1))) - ((1/sqrt(5)) * pow((1 - sqrt(5))/2, (n + 1)));

            for (int i = 2; i < m; i++)
            {
                fibo[i] = fibo[i - 1] + fibo[i - 2];
            }
            MPI_Send(fibo, m, MPI_LONG_LONG, 0, 0, MPI_COMM_WORLD);
        }
    }
    else
    {
        if (procesador == 0)
        {
            long long a, b, aux;
            a = 0;
            b = 1;
            printf("\n");
            for (int i = 0; i < N; i++)
            {
                printf(" %d", a);
                aux = a + b;
                a = b;
                b = aux;
            }
        }
    }

    MPI_Finalize();
}