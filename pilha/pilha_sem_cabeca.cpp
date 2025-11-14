#include <stdio.h>
#include <stdlib.h>

struct cel{
    int conteudo;
    struct cel *seg;
};

typedef struct cel celula;


void empilhar(celula **lst, int y);

int main(){
    celula *lst = NULL;

    empilhar(&lst, 10);
    empilhar(&lst, 20);
    empilhar(&lst, 30);
    empilhar(&lst, 40);

    
    return 0;
}

void empilhar(celula **lst, int y){
    celula *nova;
    nova = (celula *) malloc(sizeof(celula));

    if(nova == NULL){
        printf("Stack Overflow.");
        return;
    }
    nova->conteudo = y;
    nova->seg = *lst;
    *lst = nova;
}