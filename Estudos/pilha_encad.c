#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    struct no_ *prox;
    int chave;
    int valor;
}no;


void insere_pilha(no *No, no **topo){
    No->prox = topo;
    topo = No;
}

no *remove_pilha(no **topo){
    no *tmp = *topo;
    if(*topo != NULL){
        tmp = *topo;
        *topo = (*topo)->prox;
    }
}

int main(){

}