#include<iostream>
#include"funciones.h"

using namespace std;

int main(){
    int a, b, s, r, p, cociente, residuo, sw;

    cout << "\nIntroducir a: ";
    cin >> a;
    cout << "\nIntroducir b: ";
    cin >> b;

    cout << "\n==========RESULTADO==========\n";
    cout << "a = " << a << '\n' << "b = " << b;

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

    cout << "\nSuma: " << s;
    cout << "\nResta: " << r;
    cout << "\nProducto: " << p;
    
    cout << "\nDivision:";
    if(a != 0) {
        if(sw) cout << "\n\tCociente = " << cociente << "\n\tResiduo = " << residuo;
        else cout << "\n\tNo es posible realizar la division...";
    }else cout << "\n\tCociente = " << 0 << "\n\tResiduo = " << 0;
    
    cout << "\n\n-------Fin de Programa-------\n";

}