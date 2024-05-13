#include"stdio.h"
#include"stdlib.h"
#include"omp.h"

void main(){

    freopen("datos.in", "r", stdin);

    int N;

    scanf("%d", &N);

    int M[N][N];
    int V[N];
    int R[N];

    for(int j = 0; j < N; j++)
        scanf("%d", &V[j]);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            scanf("%d", &M[i][j]);
    }

    printf("\nMatriz de dimension: 1x%d\n", N);
    for(int i = 0; i < N; i++)
        printf("\t%d", V[i]);

    printf("\n");

    printf("\nMatriz de dimension: %dx%d\n", N, N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            printf("\t%d", M[i][j]);
        printf("\n");
    }

    int res;
    #pragma omp parallel reduction(+:res)
    {
        #pragma omp for
        for(int i = 0; i < N; i++){
            res = 0;
            for(int j = 0; j < N; j++)
                res += V[j] * M[j][i];  
            R[i] = res;
        }
    }

    printf("\n==========RESULTADO==========\n");
    printf("Matriz de dimension: 1x%d\n", N);
    for(int i = 0; i < N; i++)
            printf("\t%d", R[i]);

    printf("\n\n-------Fin de Programa-------");
}