#include <stdio.h>
#include <stdlib.h>

struct cel {
    int valor;
    struct cel *prox;
    struct cel *ant;
};

typedef struct cel celula;

// Inicializa a fila
void inicializar(celula *lst) {
    lst->prox = NULL;
    lst->ant = NULL;
}

// Insere no fim (ENFILEIRAR)
void enfileire(celula *lst, int y) {
    celula *nova = (celula *) malloc(sizeof(celula));
    nova->valor = y;
    nova->prox = NULL;
    nova->ant = NULL;

    // Se estiver vazia
    if (lst->prox == NULL) {
        lst->prox = nova;
        return;
    }

    // Percorre até o final
    celula *p = lst->prox;
    while (p->prox != NULL) {
        p = p->prox;
    }

    // Conecta no fim
    p->prox = nova;
    nova->ant = p;
}

// Remove do início (DESENFILEIRAR)
int desenfileire(celula *lst) {
    celula *p = lst->prox;

    if (p == NULL) {
        printf("Underflow.\n");
        return -1;
    }

    int x = p->valor;

    lst->prox = p->prox;

    if (p->prox != NULL)
        p->prox->ant = NULL;

    free(p);
    return x;
}

// Mostrar iterativamente
void mostrar_iterativa(celula *lst) {
    celula *p = lst->prox;

    while (p != NULL) {
        printf("Valor: %d\n", p->valor);
        p = p->prox;
    }
}

// Função auxiliar da recursiva
void mostrar_recursiva_aux(celula *p) {
    if (p == NULL)
        return;

    printf("Valor: %d\n", p->valor);
    mostrar_recursiva_aux(p->prox);
}

// Mostrar recursivamente
void mostrar_recursiva(celula *lst) {
    mostrar_recursiva_aux(lst->prox);
}


void bubble_sort(celula *lst){
    celula *p = lst->prox;

    int trocou = 1;

    while(trocou){
        trocou = 0;

        p  = lst->prox;
        while(p->prox != NULL){

            if(p->valor > p->prox->valor){
                int aux = p->prox->valor;
                p->prox->valor = p->valor;
                p->valor = aux;
                trocou = 1;
            }

            p = p->prox;
        }

    }
}

void selection_sort(celula *lst){

    celula *i = lst->prox;

    while(i != NULL){
        
        celula *min = i;
        celula *p = i->prox;

        while(p != NULL){
    
            if(min->valor > p->valor){
                min = p;
            }
    
            p = p->prox;
        }

        if(min != i){
            int aux = i->valor;
            i->valor = min->valor;
            min->valor = aux;
        }

        i = i->prox;

    }

}

void quick_sort(celula *lst){
    
}



// MAIN
int main() {
    celula lst;
    inicializar(&lst);

    enfileire(&lst, 17);
    enfileire(&lst, 4);
    enfileire(&lst, 30);
    enfileire(&lst, 8);
    enfileire(&lst, 7);

    //bubble_sort(&lst);

    printf("Fila atual:\n");
    mostrar_iterativa(&lst);

    printf("\nDesenfileirado: %d\n", desenfileire(&lst));

    printf("\nFila depois de remover:\n");
    mostrar_iterativa(&lst);

    return 0;
}


