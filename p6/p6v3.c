#include "stdio.h"
#include "mpi.h"
#include "math.h"
#include "time.h"

int main(int argc, char *argv[])
{
    
    long long n;
    n = 100000000;

    MPI_Init(&argc, &argv);

    int procesador, cantidad;
    long long a, b, m, envio, recepcion;
    double sum, pi;

    clock_t t0, tf;

    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    

    if(cantidad < 3)
    {
        if(procesador == 0)
        {
            t0 = clock();

            sum = 0;
            for(int i = 1; i <= n; i ++)
                sum += sqrt(pow(n, 2) - pow(i, 2));
            pi = 4 * sum / pow(n, 2);
            printf("\nPI: %lf", pi);

            tf = clock();

            double tiempo = (double)(tf - t0)/CLOCKS_PER_SEC;

            printf("\nn= %d, Tiempo: %lf seg.", n, tiempo);
        }
    }
    else
    {
        // envio = 0;
        m = n / (cantidad - 1);
        if(procesador == 0)
        {
            t0 = clock();
            a = 1;
            sum = 0;
            
            for(int i = 1; i < cantidad; i++)
            {
                //Una forma diferente de enviar intervalos [ai, ai + m]
                MPI_Send(&a, 1, MPI_LONG_LONG, i, 0, MPI_COMM_WORLD);
                a += m;
            }

            for(int i = 1; i < cantidad; i ++)
            {
                //Recibiendo sumatorias de cada proceso
                MPI_Recv(&recepcion, 1, MPI_LONG_LONG, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
                sum += recepcion;
            }
            
            pi = 4 * sum / pow(n, 2);
            printf("\nPI: %lf", pi);

            tf = clock();

            double tiempo = (double)(tf - t0)/CLOCKS_PER_SEC;

            printf("\nn = %d, Tiempo: %lf seg.", n, tiempo);

        }
        else
        {
            MPI_Recv(&b, 1, MPI_LONG_LONG, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            for(int i = 0; i < m; i ++)
            {
                //Sumatoria de f(xi)*deltaX
                envio += sqrt(pow(n, 2) - pow(b + i, 2));
            }
            MPI_Send(&envio, 1, MPI_LONG_LONG, 0, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Finalize();

}
