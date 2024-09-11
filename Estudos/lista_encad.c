#include <stdio.h>
#include <stdlib.h>

typedef struct node_{
    struct node_ *prox;
    int chave;
    int valor;
}node;

node *cria_lista(){
    return malloc(sizeof(node));
}

void busca_encad(int x, node **ant, node **pont, node *ptlista){
    *ant = ptlista;
    *pont = NULL; //Nó de retorno
    node *ptr = ptlista->prox; //Ponteiro de elementos da lista.

    while(ptr != NULL){
        if(ptr->chave < x){
            *ant = ptr;
            ptr = ptr->prox;
        }else{
            if(ptr->chave == x){
                *pont = ptr; //Retornar nó encontrado
            }
            ptr = NULL;
        }
    }
}

int insere_enc(node *no_inserir, node *ptlista){
    node *ant;
    node *pont;
    busca_encad(no_inserir->chave, &ant, &pont, ptlista);
    if(pont == NULL){  //Não encontrou, então pode adicionar
        no_inserir->prox = ant->prox;
        ant->prox = no_inserir;
        return 0;
    }
    return -1;
}   

node *remove_enc(int x, node *ptlista){
    node *ant;
    node *pont;
    busca_encad(x, &ant, &pont, ptlista);
    if(pont != NULL){  //Se encontrar o ponteiro, retira.
        ant->prox = pont->prox;
        return pont;
    }
    return NULL;
}


int main(){
    node * ptlista;
    ptlista = malloc(sizeof(node));
    (*ptlista).prox = NULL;

    node * inserir = malloc(sizeof(node));
    (*inserir).chave = 1;
    (*inserir).valor = 1;
    (*inserir).prox = NULL;

    if(insere_enc(inserir, ptlista) == -1){
        printf("erro ao inserir\n");
    }else{
        printf("insercao realizada\n");
    }

    node* removido = remove_enc(2, ptlista);
    if(removido == NULL){
        printf("elemento nao encontrado\n");
    }else{
        printf("chave: %d | valor: %d\n",
        (*removido).chave, (*removido).valor );
    }


    removido = remove_enc(1, ptlista);
    if(removido == NULL){
        printf("elemento nao encontrado\n");
    }else{
        printf("chave: %d | valor: %d\n",
        (*removido).chave, (*removido).valor );
    }
    return 0;
}