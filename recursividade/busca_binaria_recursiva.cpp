#include <stdio.h>


int busca_binaria_recursiva(int vetor[], int mid, int valor_buscar){

    int valor_recebido = busca_binaria_recursiva(vetor, mid, valor_buscar);

    if (valor_recebido == valor_buscar)
    {
        return valor_recebido;
    }
    


}

int main(){
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int mid = 10 / 2;

    int valor_buscar = 1;

    busca_binaria_recursiva(vetor, mid, valor_buscar);

    return 0;
}