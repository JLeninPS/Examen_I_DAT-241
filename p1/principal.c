#include "stdio.h"
#include "funciones.h"

void main(){
    int a, b, s, r, p, cociente, residuo, sw;

    printf("\nIntroducir a: ");
    scanf("%d", &a);
    printf("\nIntroducir b: ");
    scanf("%d", &b);

    printf("\n==========RESULTADO==========\n");
    printf("a = %d\nb = %d", a, b);

    suma(a, b, &s);
    resta(a, b, &r);
    producto(a, b, &p);

    //---------------------------
    //Para la División
    residuo = a;
    sw = 1;
    if(b != 0 && b <= a) division(&residuo, b, &cociente);
    else sw = 0;
    //---------------------------

    printf("\nSuma: %d", s);
    printf("\nResta: %d", r);   
    printf("\nProducto: %d", p);
    
    printf("\nDivision:");
    if(a != 0) {
        if (sw) printf("\n\tCociente = %d\n\tResiduo = %d", cociente, residuo);
        else printf("\n\tNo es posible realizar la division...");
    }else printf("\n\tCociente = %d\n\tResiduo = %d", 0, 0);

    printf("\n\n-------Fin de Programa-------\n");
}