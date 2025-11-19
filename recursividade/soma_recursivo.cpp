

#include <stdio.h>


int soma_recursiva(int n){
    if(n == 0){
        return 0;
    }
    return n + soma_recursiva(n - 1);
}

int main(){


    int resultado = soma_recursiva(4);

    printf("Resultado: %d\n", resultado);

    return 0;
}