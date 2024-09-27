#include <stdio.h>
#include <stdlib.h>

#define TAM 7

typedef int heap[TAM];
int tam_atual = 0;


int inserir_heap(int valor, heap arvore){
    if(tam_atual == TAM){
        puts("Árvore cheia!");
        return -1;
    }

    tam_atual++;
    int i = tam_atual-1;
    arvore[i] = valor;

    while(i != 0 && arvore[noPai(i)] < arvore[i]){
        swap(&arvore[noPai(i)], &arvore[i]);
        i = noPai(i);                                                                               
    }

    return i;
}

void swap(int *p1, int *p2){
    int tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int noPai(int i){
    return (i-1)/2;
}

int main(){
    heap arvore={0}; 

    inserir_heap(10, arvore);
    inserir_heap(15, arvore);
    inserir_heap(30, arvore);
    inserir_heap(40, arvore);
    inserir_heap(50, arvore);
    inserir_heap(60, arvore);
    inserir_heap(100, arvore);
    inserir_heap(40, arvore);

    for(int i = 0; i < tam_atual; i++){
        printf("%d ", arvore[i]);
    }
    puts("");
    return 0;
}