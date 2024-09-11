#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore_{
	int valor;
	struct noArvore_ *dir;
	struct noArvore_ *esq;
}noArvore;

noArvore *alocaNo(int valor){
	noArvore *no = malloc(sizeof(noArvore));
	no->valor = valor;
	no->dir = NULL;
	no->esq = NULL;
	return no;
}


noArvore *insere(noArvore *raiz, noArvore *no){
	if(raiz == NULL) return no;
	if(raiz->valor > no->valor){
    	raiz->esq = insere(raiz->esq, no);
	}
	else{
    	raiz->dir = insere(raiz->dir, no);
	}
	return raiz;
}

void emOrdem(noArvore *raiz){
	if(raiz->esq != NULL) emOrdem(raiz->esq);
	printf("%d ", raiz->valor);
	if(raiz->dir != NULL) emOrdem(raiz->dir);
}

noArvore *busca(noArvore *raiz, int k){
	if(raiz == NULL || raiz->valor == k) return raiz;
	if(raiz->valor > k){
    	return busca(raiz->esq, k);
	}
	else{
    	return busca(raiz->dir, k);
	}
}

noArvore *buscaPai(noArvore *raiz, int k){
	if(busca(raiz, k)->valor == k || busca(raiz, k)->valor == k){
    	return raiz;
	}
	//Continuar
}

int main(){
	noArvore *raiz = NULL;
	raiz = insere(raiz, alocaNo(10));
	raiz = insere(raiz, alocaNo(2));
	raiz = insere(raiz, alocaNo(12));
	raiz = insere(raiz, alocaNo(4));

	emOrdem(raiz);

	puts("");
	if(busca(raiz, 5) != NULL){
    	puts("Encontrado!");
	}
	else{
    	puts("Não encontrado!");
	}

	puts("");
	return 0;
}
