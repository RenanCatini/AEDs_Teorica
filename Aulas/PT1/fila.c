#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int valor;
    struct no_ *prox;   
}no;

no *fim = NULL, *inicio = NULL;

void insere_fila(no *No){
    No->prox = NULL;
    if(fim != NULL){
        fim->prox = No;
    }
    else{
        inicio = No;
    }
    fim = No;
}

no *remove_fila(){
    no *tmp = NULL;
    if(inicio != NULL){
        tmp = inicio;
        inicio = inicio->prox;
        free(tmp);
    }
    if(inicio == NULL)
        fim = NULL;

    return tmp;
}

void imprime_fila(){
    if(inicio == NULL){
        printf("Fila vazia!\n");
    }
    else{
        no *tmp = inicio;
        do{
            printf("%d ", tmp->valor);
            tmp = tmp->prox;
        }while(tmp != NULL);
    }
}

int main(){
    int opc;
    do{
        printf("1-Inserir\n");
        printf("2-Remover\n");
        printf("3-Imprimir\n");
        printf("->");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:{
            no *add = malloc(sizeof(no));
            printf("Digite um valor para o no: ");
            scanf("%d", &add->valor);
            insere_fila(add);
            break;
        }
        case 2:
            if(remove_fila() == NULL){
                printf("Falha ao remover elemento!\n");
            }
            else{
                printf("Elemento removido com sucesso!\n");
            }
            break;
        
        case 3:
            puts("");
            imprime_fila();
            puts("");
            break;
        
        default:
            break;
        }
    }while(opc != 0);
}