#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int valor;
    struct no_ *ant;
}no;

no *topo = NULL;

void insere_pilha(no *No){
    No->ant = topo;
    topo = No;
}

no *remove_pilha(){
    if(topo != NULL){
        no *tmp = topo;
        topo = topo->ant;
        free(tmp);
        return tmp;
    }
    return NULL;
}

void imprime_pilha(){
    if(topo == NULL){
        printf("Pilha Vazia!\n");
    }else{
        no *tmp = topo;
        do{
            printf("%d ", tmp->valor);
            tmp = tmp->ant;
        }while(tmp != NULL);
    }
    puts("");
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
            insere_pilha(add);
            break;
        }
        case 2:
            if(remove_pilha() == NULL){
                printf("Falha ao remover elemento!\n");
            }
            else{
                printf("Elemento removido com sucesso!\n");
            }
            break;
        
        case 3:
            puts("");
            imprime_pilha();
            puts("");
            break;
        
        default:
            break;
        }
    }while(opc != 0);
}