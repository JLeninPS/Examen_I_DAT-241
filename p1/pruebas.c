#include"stdio.h"
#include"funciones.h"
void main(){
    // int x = 12;
    // int n = 0;
    // int residuo = 12;
    // while(x > 0){
    //     division(&residuo, 10, &x);
    //     n += 1;
    //     printf("\n%d", x);
    // }
    // printf("\n\nRES: %d", n);

    // x = 3;
    // int exp = 3;
    // int res = 0;
    // for(int i = 0; i < exp; i++){
    //     producto(x, x, &res);
    // }
    // printf("\nResultado: %d", res);

    char text[20];
    sprintf(text, "%d", 456);
    printf("\ntexto %s", text);

    char saludo[20] = "HOLA";

    for(int i = 0; i < 10;i++){
        saludo[i+4] += 'a';
    }

    printf("\nSaludo: %s", saludo);

    int a, b; 
    char res[30] = "0.";
    int presicion = 10;
    a = 3;
    b = 9;

    int n, cociente, residuo;

    digitos(b, &n);
    potencia(10, n, &residuo);

    for(int i = 1; i < n; i++)
        res[i+1] = '0';
    
    char aux1[presicion];
    char aux2[presicion];
    cociente = 0;
    while(presicion > 0){
        while(residuo >= b){
            resta(residuo, b, &residuo);
            cociente += 1;
        }
        residuo *= 10;
        digitos(cociente, &n);
        resta(presicion, n, &presicion);
        sprintf(aux1, "%d", cociente);
        strcat(aux2, aux1);
    }
    cociente *= a;
    strcat(res, aux2);
    printf("\nDivision2: %s", res);

    //---------------------------
    // //Para la Division 2
    // int precision = 10;
    // char res[30] = "0.";
    // division2(a, b, res, precision);
    //---------------------------
}