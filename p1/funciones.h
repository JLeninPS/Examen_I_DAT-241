#include"stdio.h"
#include"string.h"

void suma(int a, int b, int *c){
    *c = a + b;
}

void resta(int a, int b, int *c){
    *c = a - b;
}

void producto(int a, int b, int *c){
    *c = 0;
    for(int i = 0; i < b; i ++)
        suma(a, *c, &*c);
}

void division(int *a, int b, int *c){
    *c = 0;
    while(*a >= b){
        resta(*a, b, &*a);
        *c += 1;
    }
}

//----------------------
// void digitos(int x, int *n){
//     *n = 0;
//     int residuo = x;
//     while(x > 0){
//         division(&residuo, 10, &x);
//         *n += 1;
//     }
// }
// void potencia(int x, int exp, int *res){
//     *res = 0;
//     for(int i = 0; i < exp; i++){
//         producto(x, x, &*res);
//     }
// }
// void division2(int a, int b, char *res, int presicion){
//     int n, cociente, residuo;
//     digitos(b, &n);
//     potencia(10, n, &residuo);

//     for(int i = 1; i < n; i++)
//         res[i+1] = '0';
    
//     char aux1[presicion];
//     char aux2[presicion];
//     cociente = 0;
//     while(presicion > 0){
//         while(residuo >= b){
//             resta(residuo, b, &residuo);
//             cociente += 1;
//         }
//         residuo *= 10;
//         digitos(cociente, &n);
//         resta(presicion, n, &presicion);
//         sprintf(aux1, "%d", cociente);
//         strcat(aux2, aux1);
//     }
//     cociente *= a;
//     strcat(res, aux2);
//     // sprintf("division2: %s", res);
//     // *res = *res + aux;
// }