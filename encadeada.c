#include <stdio.h>
#include <stdlib.h>


typedef struct No{
   int valor;
   struct No *end_prox;
}No;


No ptlista;


//Buscar elemento na,lista encadeada.
void busca_enc(int valor, No **ant, No **pont){
   *pont = NULL;
   *ant = &ptlista;
   No *ptr = ptlista.end_prox;


   while(ptr != NULL){
       if(ptr->valor < valor){
           *ant = ptr;
           ptr = (*ptr).end_prox;
       }
       else if((*ptr).valor == valor){
           *pont = ptr;
           ptr = NULL;
       }
   }


}


//Inserir elemento na lista encadeada.
int insere_enc(int x){
   No *ant, *pont;
   busca_enc(x, &ant, &pont);
   if(pont == NULL){
       No *novo = (No*) malloc(sizeof(No));
       (*novo).end_prox = (*ant).end_prox;
       novo->valor = x;
       (*ant).end_prox = novo;
       return 0;
   }

   return -1;
}  


//Remove elemento na lista encadeada.
No *remove_enc(int x){
   No *ant, *pont;
   busca_enc(x, &ant, &pont);
   if(pont != NULL){
       ant->end_prox = pont->end_prox;
       return pont;
   }
   return NULL;
}




int main(){
   printf("%d ", insere_enc(1));
   printf("%d ", insere_enc(2));
   printf("%d ", insere_enc(3));
   printf("%d ", insere_enc(4));
   printf("%d ", insere_enc(5));
   printf("%d ", insere_enc(6));
   printf("%d ", insere_enc(7));
   printf("%d ", insere_enc(8));
   printf("%d\n\n", insere_enc(9));


   No *aux = ptlista.end_prox;
   while(aux != NULL){
       printf("%d ", aux->valor);
       aux = aux->end_prox;
   }

   remove_enc(8);
   remove_enc(4);
   remove_enc(2);

   puts("\n");

   aux = ptlista.end_prox;
   while(aux != NULL){
       printf("%d ", aux->valor);
       aux = aux->end_prox;
   }


   puts("\n");
   aux = ptlista.end_prox;
   No *temp;
   while(aux != NULL){
       temp = aux;
       aux = aux->end_prox;
       free(temp);
   }

   return 0;
}