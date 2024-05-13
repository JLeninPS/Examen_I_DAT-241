#include"stdio.h"
#include"omp.h"

void main(){
    int a, b;

    printf("\nIntroducir a: ");
    scanf("%d", &a);
    printf("\nIntroducir b: ");
    scanf("%d", &b);
    
    printf("\n==========RESULTADOS==========\n");
    printf("a = %d\nb = %d\n", a, b);
    
    //=====================================================
    //      PRODUCTO EN BASE A SUMAS  
    int p = 0;
    #pragma omp parallel reduction(+:p)
    {
        #pragma omp for
            for(int i = 0; i < b; i++)
                p += a;
    }
    printf("\nProducto: %d", p);
    //-----------------------------------------------------

    //=====================================================
    //      DIVISION EN BASE A RESTAS
    int cociente = 0;
    int residuo = a;
    printf("\nDivision:");
    if(a != 0){
        if(b != 0 && a >= b){ 
            #pragma omp parallel reduction(+:cociente)
            {
                #pragma omp for
                for(int i = a; i >= b; i -= b){
                    cociente++;
                    #pragma omp atomic
                        residuo -= b;
                }
            }
            printf("\n\tCociente = %d\n\tResiduo = %d", cociente, residuo);
        }else printf("\n\tNo es posible realizar la division...");
    }else printf("\n\tCociente = 0\n\tResiduo = 0");
    //-----------------------------------------------------

    printf("\n\n-------Fin del Programa-------");
}