#include <stdio.h>
#include <stdlib.h>

struct cel
{
    int valor;
    struct cel *prox;
};

typedef struct cel celula;

void enfileire(celula *lst, int y);

int main(){

    celula c, *lst;

    c.prox = NULL;
    lst = &c;

    enfileire(lst, 13);

    return 0;

}

void enfileire(celula *lst, int y){
    celula *nova;
    nova = (celula *) malloc(sizeof(celula));

    nova->valor = y;
    nova->prox = NULL;

    celula *p = lst->prox;

    while(p != NULL){
        p = p->prox;
    }

    p->prox = nova;
}


int desenfileire(celula *lst){
    celula *p = lst->prox;

    if(p == NULL){
        printf("Underflow.");
        return - 1;
    }
    int x = p->valor;
    lst->prox = p->prox;

    free(p);

    return x;
}

void mostrar_iterativa(celula *lst){
    celula *p = lst->prox;

    while(p != NULL){
        printf("Valor: %d\n", p->valor);
        p = p->prox;
    }
}

void mostrar_recursiva(celula *lst){
    celula *p = lst->prox;

    if(p == NULL){
        printf("Cabo a lista");
        return;
    }

    printf("Valor: %d", p->valor);

    mostrar_recursiva(p);


}