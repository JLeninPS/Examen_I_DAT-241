#include"stdio.h"
#include"omp.h"

void main()
{
    int N, P, T, m, res, procesador, cantidad;
    
    #pragma omp parallel
    {
        cantidad = omp_get_num_threads();
    }

    printf("\nUsted cuenta con %d procesadores.", cantidad);
    printf("\nCuantos desea usar?: ");
    scanf("%d", &P);

    printf("\nIntroducir tamanio de la serie (N): ");
    scanf("%d", &N);

    P = (P < cantidad && P > 0) ? P : cantidad;
    P = (N < P) ? N : P;
    
    T = N * 2;//Ultimo valor de la serie
    
    m = (N % P == 0) ? N / P : N / P + 1;
    P = (N % m == 0) ? N / m : P;
    int M[P][m];

    #pragma omp parallel num_threads(P) private(procesador)
    {
        procesador = omp_get_thread_num();
        
        M[procesador][0] = (m * procesador + 1) * 2;

        for(int i = 1; i < m; i++)
            M[procesador][i] = M[procesador][i - 1] + 2;
    }

    for(int i = 0; i < P; i++)
    {
        printf("\nProcesador: %d", i);
        for(int j = 0; j < m; j++)
        {
            res = M[i][j];
            printf("\t%d", res);
            if(res == T) break;
        }
    }

}