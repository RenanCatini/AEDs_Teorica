#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    struct No *chave_prox;
}No;


int main(){
    int tam = 10;

    No *primeiro = malloc(sizeof(No));
    No *atual = primeiro;                                             
    
    for(int i = 0; i < tam; i++){
        (*atual).valor = i;
        if(i <  tam-1){
            (*atual).chave_prox = malloc(sizeof(No));
            atual = (*atual).chave_prox;
        }
        else{
            (*atual).chave_prox = NULL; //Quando chegar no tamanho, ele coloca um Null
        }
    }
    
    atual = primeiro;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    while(atual != NULL){
        printf("->%d\n", (*atual).valor);
        atual = (*atual).chave_prox;
    }

    atual = primeiro;
    No *temp;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
    while(atual != NULL){
        temp = atual;
        atual = (*atual).chave_prox;
        free(temp);
    }

    return 0;
}