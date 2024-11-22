#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

void swap(int* xp, int* yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n){
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }

        // Se não houve a troca de elementos
        if (!swapped)
            break;
    }
}

int main(){
    int vetor[TAM];
    for (int i = 0; i < TAM; i++) 
        vetor[i] = i;

    srand((unsigned int)time(0));
    for (int i = TAM - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        int temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
    
    printf("Vetor desordenado: ");
    for(int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }
    puts("");

    bubbleSort(vetor, TAM);

    printf("Vetor ordenado: ");
    for(int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }
    puts("");
    
    return 0;
}