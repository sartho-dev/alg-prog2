#include<stdio.h>

int multiplicacao_recursiva(int a, int b){

    if(b == 0){
        return 0;
    }

    return a + multiplicacao_recursiva(a, b - 1);

}

int main(){
    
    int resultado =  multiplicacao_recursiva(2,3);

    printf("Resultado: %d", resultado);

    return 0;
}