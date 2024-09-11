#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    struct no_ *prox;
    int chave;
    int valor;
}no;

void insere_fila(no *inserir, no **inicio, no **fim){
    inserir->prox = NULL;
    if(*fim != NULL){
        (*fim)->prox = inserir;
    }
    else {
        *inicio= inserir;
    }
    *fim = inserir;
}

no *remove_fila(no **inicio, no **fim){
    no *removido = NULL;
    if(*inicio != NULL){
        removido = *inicio;
        *inicio = (*inicio)->prox;
        if(*inicio == NULL) *fim = NULL;
    }
    return removido;
}

void imprime(no **inicio){
    no *tmp = *inicio;
    if(tmp == NULL){
        printf("Fila Vazia!\n");
        return;
    }
    printf("Fila: ");
    while(tmp != NULL){
        printf("%d ", tmp->valor);
        tmp = tmp->prox;
    }
    puts("");
}

int main(){
    no *inicio = NULL, *fim = NULL;
    no *no1 = malloc(sizeof(no));
    no *no2 = malloc(sizeof(no));
    no *no3 = malloc(sizeof(no));

    no1->valor = 1;
    no1->chave = 0;
    no2->valor = 5;
    no2->chave = 1;
    no3->valor = 2;
    no3->chave = 2;

    insere_fila(no1, &inicio, &fim);
    insere_fila(no2, &inicio, &fim);
    insere_fila(no3, &inicio, &fim);
    imprime(&inicio);
    if(remove_fila(&inicio, &fim) != NULL) puts("Removido com sucesso!");
    else puts("Falha ou lista vazia!");

    if(remove_fila(&inicio, &fim) != NULL) puts("Removido com sucesso!");
    else puts("Falha ou lista vazia!");

    imprime(&inicio);

    if(remove_fila(&inicio, &fim) != NULL) puts("Removido com sucesso!");
    else puts("Falha ou lista vazia!");
    
    imprime(&inicio);

    if(remove_fila(&inicio, &fim) != NULL) puts("Removido com sucesso!");
    else puts("Falha ou lista vazia!");
}