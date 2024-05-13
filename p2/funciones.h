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