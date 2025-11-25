#include <stdio.h>

int succ(int x){
    return ++x;
}

int soma_dois_recursivo(int a, int b){

    if(b == 0){
        return a;
    }
 
    a = succ(a);
    return soma_dois_recursivo(a, b - 1);
}

int main(){

    int resultado = soma_dois_recursivo(8, 3);

    printf("Resultado: %d\n", resultado);

    return 0;
}