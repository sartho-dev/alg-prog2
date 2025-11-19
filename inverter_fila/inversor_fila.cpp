
#include <stdio.h>
#include <stdlib.h>

struct cel
{
    int conteudo;
    struct cel *seg;
};

typedef struct cel celula;

void enfileire(celula *fim, int y){
    celula *nova = (celula *) malloc(sizeof(celula));

    nova->conteudo = y;
    nova->seg = NULL;

    fim->seg = nova;
    fim = nova;

}

int main(){
    
    celula head;
    head.seg = NULL;
    celula *fim = &head;

    return 0;
}
