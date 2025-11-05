#include <stdio.h>
#define TAMANHO_FILA 30

void enfileire(int vetor[], int *t, int *s, int x);
int desenfileire(int vetor[], int *s, int *t);
int vazia(int *s, int *t);

int main(){
    int vetor[TAMANHO_FILA];
    int s, t;

    s = t = 0;

    enfileire(vetor, &t, &s, 13);
    enfileire(vetor, &t, &s,16);
    desenfileire(vetor, &s, &t);

    enfileire(vetor, &t, &s, 17);


    return 0;
}

void enfileire(int vetor[], int *t, int *s,  int x){
    
    if((*t + 1) % TAMANHO_FILA == *s){
        printf("Fim da lista. Overflow\n");
        return;
    }

    vetor[*t] = x;
    *t = (*t + 1) % TAMANHO_FILA;

}

int desenfileire(int vetor[], int *s, int *t){

    if(vazia(s, t)){
        printf("Fila vazia.\n");
        return -1;
    }

    int x = vetor[*s];
    *s = (*s + 1) % TAMANHO_FILA;

    return x;
}

int vazia(int *s, int *t){
    return (*s == *t);
}