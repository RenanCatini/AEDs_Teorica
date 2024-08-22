#include <stdio.h>
#include <stdlib.h>

#define MAX 100
typedef struct{
    int chave;
    int valor;
    //...
}No;

/*Busca de uma chave em um vetor.
*Retorna o índice do vetor onde a chave está
*ou retorna -1 caso ele não exista.
*/
int busca_chave(int x, No vetor[], int n){
    vetor[n].chave = x;
    int i = 0;
    while(vetor[i].chave != x){
        i++;
    }
    if(i != n){
        return i;
    }
    return -1;
}

/*Insere um Nó na lista desejada.
*Retorna o tamanho da lista caso seja inserido, 
*-1 caso o elemento ja exista na lista, ou -2 caso lista cheia.
*/
int insere_no(No no, No vetor[], int *n){
    if(*n < MAX){
        if(busca_chave(no.chave, vetor, *n) == -1){
            vetor[*n] = no;
            *n = *n + 1;
            return *n;
        } else{
            return -1;
        }
    } else{
        return -2;
    }
}

/*Remove um elemento da lista desejada.
Retorna: o endereço de nó, caso ele seja removido, e NULL caso ele não exista.
*/
No *remove_no(int chave, No vetor[], int *n){
    if(*n != 0){
        int indice = busca_chave(chave, vetor, *n);
        if(indice != -1){
            //Aloca espaço na memória para inserir o Nó excluido.
            No *retorno = malloc(sizeof(No));
            (*retorno) = vetor[indice];

            for(int i = indice; i < *n; i++){
                vetor[i] = vetor[*n-1];
            }
            *n = *n - 1;

            return (retorno);
        }else{
            return NULL;
        }     
    } else{
        return NULL;
    }
}

void cabecalho(int *opcao){
    system("cls");
    printf("=====================\n");
    printf("0 - Sair.\n");
    printf("1 - Inserir No.\n");
    printf("2 - Retirar No.\n");
    printf("3 - Vizualizar Vetor de Nos.\n");
    printf("Escolha: ");
    scanf("%d", opcao);

    while(*opcao < 0 || *opcao > 3){
        printf("\n*Opcao Invalida*\n");
        printf("Digite uma opcao valida: ");
        scanf("%d", opcao);
    }
}

void pausar() {
    printf("\nPrecione enter para continuar...");
    getchar();
    getchar();
}

int main(){
    int opcao = 100, tam_vetor = 0;
    No vetor[MAX];
    No inserir;

    while(opcao != 0){
        cabecalho(&opcao);

        if(opcao == 1){
            if(tam_vetor != MAX){
                printf("\n===Inserir===\n");
                printf("-Digite uma chave valida para o No: ");
                scanf("%d", &inserir.chave);
                while(busca_chave(inserir.chave, vetor, tam_vetor) != -1){
                    printf("*Chave em uso*\n");
                    printf("-Digite outra chave: ");
                    scanf("%d", &inserir.chave);
                }

                printf("-Digite o valor para o No: ");
                scanf("%d", &inserir.valor);

                insere_no(inserir, vetor, &tam_vetor);
                printf("No alocado no vetor com sucesso!\n");
            }
        }
        else if(opcao == 2){
            printf("\n===Retirar===\n");
            printf("Digite uma chave de um no: ");
            scanf("%d", &inserir.chave);
            if(remove_no(inserir.chave, vetor, &tam_vetor) != NULL){
                printf("\n*No de chave removido com sucesso!*\n");
            }
            else{
                printf("\n*No invalido!*\n");
            }
        }
        else if(opcao == 3){
            printf("\n====Vetor====\n");
            for(int i = 0; i < tam_vetor; i++){
                printf("(Chave: %d; Valor: %d)\n", vetor[i].chave, vetor[i].valor);
            }
        }

        //Pausar se opcao != 0, senão não fazer nada
        opcao != 0 ? pausar() : 0; 
    }
    return 0;
}