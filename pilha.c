#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int chave;
    //...
}No;

//Insere valor seguindo a lógica de pilha.
int insere_pilha(No no, No vetor[], int *top){
    if(*top != MAX){
        (*top)++;
        vetor[*top] = no;
        return *top;
    }
    return -1;
}

//Retira valor seguindo a lógica de pilha.
No *retira_pilha(No vetor[], int *top){
    if(*top >= 0){
        (*top)--;
        return &vetor[(*top)+1];
    }
    return NULL;
}


int main(){
    No no1 = {3}; 
    No no2 = {5}; 
    No no3 = {9};

    No pilha[MAX];
    int topo = -1;

    insere_pilha(no1, pilha, &topo); 
    insere_pilha(no2, pilha, &topo); 
    insere_pilha(no3, pilha, &topo);

    for(int i = 0; i <= topo; i++){
        printf("%d ", pilha[i].chave);
    }

    printf("\nRetirado: %d\n", (*retira_pilha(pilha, &topo)).chave);

    for(int i = 0; i <= topo; i++){
        printf("%d ", pilha[i].chave);
    }

    return 0;
}