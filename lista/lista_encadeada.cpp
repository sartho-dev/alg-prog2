#include <stdio.h>
    #include <stdlib.h>

struct cel{
    int conteudo;
    struct cel *seg;
};

typedef struct cel celula;

void insira(int y, celula *lst);
void imprime(celula *lst);
void remove_tudo(celula *lst);

int main(){

    celula c, *lst;

    c.seg = NULL;
    lst = &c;

    insira(50, lst);
    insira(10, lst);
    insira(20, lst);
    insira(30, lst);
    insira(7, lst);

    imprime(lst);

    remove_tudo(lst);

    imprime(lst);



    return 0;
}


void insira(int y, celula *lst){
    celula  *nova;

    nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;
    nova->seg = lst->seg;
    lst->seg = nova;

}   

void imprime(celula *lst){
    celula *p = lst->seg;

    while(p != NULL){
        printf("Conteudo: %d\n", p->conteudo);
        p = p->seg;
    }
}


void remove_tudo(celula *lst){

    celula *p = lst->seg;
    celula *prox;

    while(p != NULL){
        prox = p->seg;
        free(p);
        p = prox;
    }

    lst->seg = NULL;
}



void remove_tudoR(celula *lst){


    if(lst->seg == NULL){
        printf("acabou");
        return;
    }

    remove_tudoR(lst->seg);

    celula *p = lst->seg;
    lst->seg = p->seg;
    free(p);

}



int conte_celulas(celula *lst){

    celula *p = lst->seg;
    int contador = 0;

    while(p != NULL){
        p = p->seg;
        contador++;
    }

    return contador;
}


celula *funde_listas(celula *lst1, celula *lst2){ 
    celula *nova = (celula *) malloc(sizeof(celula));
    nova->seg = NULL;

    celula *p = lst1->seg;

    if(p == NULL){
        nova->seg = lst2->seg;
        return nova;
    }

    nova->seg = lst1->seg;

    while(p != NULL){
        p = p->seg;
    }

    p->seg = lst2->seg;
    
    return nova;

}


void teste_fusao() {
    celula a, b;
    a.seg = NULL;
    b.seg = NULL;

    insira(1, &a);
    insira(2, &a);
    insira(3, &a);

    insira(10, &b);
    insira(20, &b);
    insira(30, &b);

    printf("Lista A:\n");
    imprime(&a);

    printf("Lista B:\n");
    imprime(&b);

    celula *resultado = funde_listas(&a, &b);

    printf("Lista fundida:\n");
    imprime(resultado);
}