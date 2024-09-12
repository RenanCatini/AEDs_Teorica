#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
}no;

int insere_pilha(no L[], no *no, int *topo, int m){
    if(*topo < m-1){
        (*topo)++;
        L[*topo] = *no;
        return *topo;
    }
    puts("Lista cheia!");
    return -1;
}

no *remove_pilha(no L[], int *topo){
    if(*topo >= 0){
        no *aux = &L[*topo];
        (*topo)--;
        return aux;
    }
    puts("Lista Vazia!");
    return NULL;
}

void imprime(no L[], int topo){
    if(topo < 0){
        puts("Lista Vazia!");
        return;
    } else {
        printf("Pilha: ");
        for(int i = 0; i <= topo; i++) printf("%d ", L[i].valor);
        puts("");
    }
}

int main(){
    int max = 3;
    int topo = -1;
    no L[max];

    no *no1 = malloc(sizeof(no));
    no1->valor = 3;

    no *no2 = malloc(sizeof(no));
    no2->valor = 7;

    no *no3 = malloc(sizeof(no));
    no3->valor = 1;

    no *no4 = malloc(sizeof(no));
    no4->valor = 11;

    imprime(L, topo);
    insere_pilha(L, no1, &topo, max);
    insere_pilha(L, no2, &topo, max);
    imprime(L, topo);
    insere_pilha(L, no3, &topo, max);
    insere_pilha(L, no4, &topo, max);
    imprime(L, topo);

    remove_pilha(L, &topo);
    imprime(L, topo);
    remove_pilha(L, &topo);
    imprime(L, topo);
    remove_pilha(L, &topo);
    imprime(L, topo);
    remove_pilha(L, &topo);
}