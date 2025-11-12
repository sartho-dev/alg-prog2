#include <stdio.h>
#include <stdlib.h>

struct cel{
    int conteudo;
    struct cel *seg;
};

typedef struct cel celula;

int main(){

    celula c, *lst;
    c.seg = NULL;
    lst = &c;



    return 0;
}


void empilhar(int y, celula *lst){
    celula *nova;

    nova = (celula *) malloc(sizeof(celula));

    if(nova == NULL){
        printf("Overflow. Não foi possivel inserir");
        return;
    }

    nova->conteudo = y;
    nova->seg = lst->seg;
    lst->seg = nova;
}

int desempilhar(celula *lst){
    
    if(lst->seg == NULL){
        printf("Underflow. Pilha vazia");
        return 0;
    }

    
    celula *p = lst->seg;
    int x = p->conteudo;

    lst->seg = p->seg;
    free(p);

   
    return x;
}