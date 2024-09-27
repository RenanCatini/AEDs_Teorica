#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef int heap[TAM];
int tam_atual = 0;

//Retorna o índice do nó pai.
int noPai(int i){
    return (i-1)/2;
}

//Retorna o índice do nó filho da esquerda.
int fil_Esq(int i){
    return (2*i)+1;
}

//Retorna o índice do nó filho da direita.
int fil_Dir(int i){
    return (2*i)+2;
}

//Troca os valores do vetor.
void swap(int *p1, int *p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int inserir_heap(int valor, heap arvore){
    //Comparação caso esteja cheia
    if(tam_atual == TAM){
        puts("Arvore cheia!");
        return -1;
    }

    //Adicionar o valor
    tam_atual++;
    int i = tam_atual-1;
    arvore[i] = valor;

    //Reequilibrar a árvore
    while(i != 0 && arvore[noPai(i)] > arvore[i]){
        swap(&arvore[noPai(i)], &arvore[i]);
        i = noPai(i);                                                                               
    }

    return i;
}

//Função recursiva que organiza os valores.
void organizar(int i, heap arvore){
    int esq = fil_Esq(i);
    int dir = fil_Dir(i);
    int menor = i;

    //Verifica se o filho a esquerda é menor que o nó atual
    if(esq < tam_atual && arvore[esq] < arvore[menor]) 
        menor = esq;
    //Verifica se o filho a direita é menor que o nó atual
    if(dir < tam_atual && arvore[dir] < arvore[menor]) 
        menor = dir;

    //Se o nó atual não é menor, faz a troca e continua organizando.
    if(menor != i){
        swap(&arvore[i], &arvore[menor]);
        organizar(menor, arvore);
    }
    //Obs.: Entender recursividade.
}

int remover(heap arvore){
    //Checa se a arvore está vazia
    if(tam_atual <= 0){
        puts("Arvore Vazia!");
        return -1;
    }
    //Caso só tenha um elemento, ele exclui so a raiz.
    if(tam_atual == 1){
        tam_atual--;
        return arvore[0];
    }

    //Com mais elementos: 
    int raiz = arvore[0];
    arvore[0] = arvore[tam_atual-1];
    tam_atual--;
    organizar(0, arvore);

    return raiz;
}

void imprimir(heap arvore){
    printf("-Arvore: ");
    for(int i = 0; i < tam_atual; i++){
        printf("%d ", arvore[i]);
    }
    puts("");
}

int main(){
    heap arvore; 

    int opc = 1, valor;
    do{
        printf("1. Adicionar valor\n");
        printf("2. Remover menor no\n");
        printf("0. Sair\n");
        printf("->");
        scanf("%d", &opc);

        switch (opc){
        case 1:
            printf("\n-Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            inserir_heap(valor, arvore);
            imprimir(arvore);
            puts("");
            break;
        
        case 2:
                printf("Remover menor no.\n");
                remover(arvore);
                imprimir(arvore);
                puts("");
            break;

        case 0: 
            break;
        
        default:
            break;
        }
    }while(opc != 0);
    
    return 0;
}