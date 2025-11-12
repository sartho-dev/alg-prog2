#include <stdio.h>

#define N 30

void empilhe(int p[], int &t, int y);
int desempilhe(int p[], int &t);

int main(){

    int vetor_pilha[N];
    int t = 0;

    empilhe(vetor_pilha, t, 33);
    empilhe(vetor_pilha, t, 7);
    empilhe(vetor_pilha, t, 11);
    desempilhe(vetor_pilha, t);
    desempilhe(vetor_pilha, t);
    empilhe(vetor_pilha, t, 2);
    desempilhe(vetor_pilha, t);


    return 0;
}


void empilhe(int p[], int &t, int y){
    if (t == N)
    {
        printf("Overflow. Pilha atingiu sua capacidade maxima");
        return;
    }
    
    p[t] = y;
    t++;
    printf("Empilhou: %d (t = %d)\n", y, t);
}

int desempilhe(int p[], int &t){
    if (t == 0)
    {
        printf("Underflow. Pilha ja vazia. Não foi possível remover o elemento");
        return 0;
    }

    t--;
    int x = p[t]; 
   
    printf("Desempilhou: %d (t = %d)\n", x, t);

    return x;
}

